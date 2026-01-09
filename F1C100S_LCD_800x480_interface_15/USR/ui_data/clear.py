# ...existing code...
import ast
import re
from pathlib import Path
from typing import Optional



#DC_ AC_ light_  power_  keyboard_ home_

CLEAR_PREFIX = "tank_"


ROOT = Path(r"d:\PYC\F1C100S_ALL_Project\Setup_184\F1C100S_LCD_800x480_interface_15\USR\ui_data")

def _get_node_end_lineno(node: ast.AST) -> Optional[int]:
    # 如果有 end_lineno（Python 3.8+）直接返回，否则在子节点中寻找最大的 lineno 作为结束行
    if hasattr(node, "end_lineno"):
        return getattr(node, "end_lineno")
    max_ln = getattr(node, "lineno", None)
    for n in ast.walk(node):
        ln = getattr(n, "lineno", None)
        if ln is not None:
            if max_ln is None or ln > max_ln:
                max_ln = ln
    return max_ln

def clear_ac_arrays_in_py(path: Path) -> bool:
    text = path.read_text(encoding="utf-8")
    try:
        tree = ast.parse(text)
    except Exception:
        return False
    to_replace = []
    for node in ast.walk(tree):
        if isinstance(node, ast.Assign):
            # 只处理赋值值为列表或元组的情况（图片数组声明常为 list/tuple）
            if not isinstance(node.value, (ast.List, ast.Tuple)):
                continue
            for target in node.targets:
                if isinstance(target, ast.Name) and target.id.startswith(CLEAR_PREFIX):#####################
                    start = getattr(node, "lineno", None)
                    end = _get_node_end_lineno(node)
                    if start is not None and end is not None:
                        to_replace.append((start, end, target.id))
    if not to_replace:
        return False
    lines = text.splitlines(keepends=True)
    for start, end, name in sorted(to_replace, key=lambda x: x[0], reverse=True):
        lines[start-1:end] = [f"{name} = []\n"]
    path.write_text("".join(lines), encoding="utf-8")
    return True

# 正则匹配 C 中以 AC_ 开头的 const unsigned char 数组初始化器

_C_ARRAY_RE = re.compile(
    r"(const\s+unsigned\s+char\s+(" + re.escape(CLEAR_PREFIX) + r"[A-Za-z0-9_]+)\s*)\[[^\]]*\]\s*=\s*\{.*?\}(\s*;)",
    re.DOTALL | re.IGNORECASE
)
# ...existing code...
def clear_ac_arrays_in_c(path: Path) -> bool:
    # 兼容不同编码：优先 utf-8，回退 gbk，再回退 latin-1（用于含非文本字节但无 NUL 的情况）
    try:
        text = path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        try:
            text = path.read_text(encoding="gbk")
        except UnicodeDecodeError:
            # 最后尝试按二进制读取并用 latin-1 解码（不会报错但保留原字节）
            try:
                raw = path.read_bytes()
            except Exception:
                return False
            # 如果是明显的二进制（包含 NUL），跳过该文件
            if b"\x00" in raw:
                return False
            try:
                text = raw.decode("latin-1")
            except Exception:
                return False

    def repl(m: re.Match) -> str:
        # 保留声明前缀和结尾分号，只把初始化器内容替换为单个 0
        return f"{m.group(1)}[1]={{0}}{m.group(3)}"
    new_text, n = _C_ARRAY_RE.subn(repl, text)
    if n:
        # 写回时使用 utf-8，latin-1 解码得到的文本也能用 utf-8 写回（非 ASCII 会被转换）
        path.write_text(new_text, encoding="utf-8")
        return True
    return False
# ...existing code...

def main():
    changed_files = 0
    for p in ROOT.glob("*.*"):
        if p.name == "clear.py":
            continue
        if p.suffix.lower() == ".py":
            if clear_ac_arrays_in_py(p):
                changed_files += 1
        elif p.suffix.lower() == ".c":
            if clear_ac_arrays_in_c(p):
                changed_files += 1
    print(f"Finished. Modified {changed_files} file(s).")

# ...existing code...
if __name__ == "__main__":
    main()
# ...existing code...