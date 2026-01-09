extern BOOL f_need_LCD_Upgrate;

void Virtual_LCD_Upgrate(void);
void Virtual_LCD_Upgrate_formx1y1(int x,int y,int w,int h);
void Virtual_LCD_Clear_ARGB32(unsigned int *layer,unsigned int Color);
void Virtual_LCD_Draw_Rectangle_ARGB32(int x,int y,int w,int h,unsigned int *layer,unsigned int Color);
void Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(int x,int y,int w,int h,unsigned int Color);
void Virtual_LCD_clean_layer_0_1_2(void);


void Virtual_LCD_Draw_String_ARGB64(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);

void Virtual_LCD_Draw_Picture32_ARGB32(int x,int y,int w,int h,unsigned char *pic,unsigned int *layer);
void Virtual_LCD_Draw_Picture32_ARGB32_from_x1y1(int x,int y,int w,int h,unsigned char *pic,int x1,int y1,int x2,int y2,int x_offet,int y_offet,unsigned int *layer);
void Virtual_LCD_Draw_String_ARGB48(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_align_center_48_4bit(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_ASCII_ARGB_48_4bit_bold(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_48_4bit_bold(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_ASCII_ARGB_32_4bit(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_32_4bit(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);

void Virtual_LCD_Draw_ASCII_ARGB_32_4bit_bold(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_32_4bit_bold(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);

void Virtual_LCD_Draw_ASCII_ARGB_16_4bit(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_16_4bit(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_ASCII_ARGB_24_4bit_bold(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_24_4bit_bold(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_ASCII_ARGB_24_4bit(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_24_4bit(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_align_right_4bit(unsigned int glyph_type,int right_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_ASCII_ARGB_8_4bit(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_8_4bit(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);

void Virtual_LCD_Draw_ASCII_ARGB_8_4bit_bold(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_8_4bit_bold(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);


void Virtual_LCD_Draw_String_o(int x,int y,char *str,lv_font_fmt_txt_glyph_dsc_t *buff,unsigned int Color1,unsigned int Color2,int fx,int fd);
u16 get_str_align_center_x_val(u16 center_x_val,char *str,const lv_font_fmt_txt_glyph_dsc_t *glyph_dsc);

void Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);
void Virtual_LCD_Draw_String_ARGB_align_center_8_4bit(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd);


