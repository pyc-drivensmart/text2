#include "sys_types.h"
typedef struct {
#if LV_FONT_FMT_TXT_LARGE == 0
    u32 bitmap_index : 20;     /**< 字符对应的字模数据索引   Start index of the bitmap. A font can be max 1 MB.*/
    u32 adv_w : 12;            /**< 字符宽度，在此宽度之后绘制下一个字形。8.4 format(存储real_value * 16)。                Draw the next glyph after this width. 8.4 format (real_value * 16 is stored).*/
    u8 box_h;                  /**< 字模高度                Height of the glyph's bounding box*/
	  u8 box_w;                  /**< 字模宽度                Width of the glyph's bounding box*/
    
    u8 ofs_x;                   /**< 字模水平方向偏移（右边为正向）      x offset of the bounding box*/
    u8 ofs_y;                   /**< 字模竖直方向偏移（上边为正向）（当字符需要在基线以下显示时使用这个参数让字模下沉）y offset of the bounding box. Measured from the top of the line*/
#else
    uint32_t bitmap_index;          /**< Start index of the bitmap. A font can be max 4 GB.*/
    uint32_t adv_w;                 /**< Draw the next glyph after this width. 28.4 format (real_value * 16 is stored).*/
    uint16_t box_w;                 /**< Width of the glyph's bounding box*/
    uint16_t box_h;                 /**< Height of the glyph's bounding box*/
    int16_t ofs_x;                  /**< x offset of the bounding box*/
    int16_t ofs_y;                  /**< y offset of the bounding box. Measured from the top of the line*/
#endif
} lv_font_fmt_txt_glyph_dsc_t;

extern const uint8_t glyph_bitmap[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[];
extern const uint8_t glyph_bitmap_48_4bit_bold[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_48_4bit_bold[];
extern const uint8_t glyph_bitmap_32_4bit[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_32_4bit[];

extern const uint8_t glyph_bitmap_32_4bit_bold[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_32_4bit_bold[];
extern const uint8_t glyph_bitmap_16_4bit[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_16_4bit[];
extern const uint8_t glyph_bitmap_16_4bit_bold[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_16_4bit_bold[];

extern const uint8_t glyph_bitmap_24_4bit[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_24_4bit[];

extern const uint8_t glyph_bitmap_24_4bit_bold[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_24_4bit_bold[];

extern const uint8_t glyph_bitmap_8_4bit[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_8_4bit[];

extern const uint8_t glyph_bitmap_8_4bit_bold[];
extern const lv_font_fmt_txt_glyph_dsc_t glyph_dsc_8_4bit_bold[];
