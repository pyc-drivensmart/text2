@echo off %关闭显示命令%
color 2e %设置窗口颜色%
title=F1C100S/F1C200S下载
color 2e %设置窗口颜色%

echo 准备下载...


if "%1"=="" (
echo 没有输入烧录工具地址，使用默认烧录工具地址！
cd\  %标回到根目录%
%~d0
cd %~dp0sunxi-tools-烧录
echo 烧录工具地址：%~dp0sunxi-tools-烧录
) else (
cd\  %标回到根目录%
%~d1 %打开盘符%
cd %1  %打开烧录工具地址%
echo 烧录工具地址： %1
)

echo 程序地址：%~dp0f1c100s.bin

echo 下载中
sunxi-fel -p spiflash-write 0x50000 %~dp0f1c100s.bin
echo 下载完成

TIMEOUT /T 3 %延时退出%
