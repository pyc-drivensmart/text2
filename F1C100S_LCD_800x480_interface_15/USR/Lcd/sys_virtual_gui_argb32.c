#include "includes.h"
//update display
BOOL f_need_LCD_Upgrate = FALSE;
extern unsigned int Read_time_ms(void);
extern unsigned int cntt;
unsigned int Ar,Ag,Ab,Br,Bg,Bb,Cr,Cg,Cb;
unsigned char alpha;
void Virtual_LCD_Upgrate(void)
{
	int i;
	unsigned int *BT0 = (unsigned int *)lcd_pdat->vram[0];
	
	
	
	if(f_need_LCD_Upgrate==FALSE)
		return;
	cntt = Read_time_ms();
	for(i=0;i<(XSIZE_PHYS*YSIZE_PHYS);i++)
	{
		/*if(((f_ui_disply_keyboard))&&((Virtual_LCDbuff3[i]&0xFF000000)!=0x00000000 ))
		{

				BT0[i] =  Virtual_LCDbuff3[i];
		}
		else*/
		if((Virtual_LCDbuff2[i]&0xFF000000)!=0x00000000 )
		{
		  //BT0[i] =  Virtual_LCDbuff2[i];		
      alpha = 	(u8)((Virtual_LCDbuff2[i])>>24	);
			Ar = 	(u8)((Virtual_LCDbuff2[i])>>16	);
			Ag = 	(u8)((Virtual_LCDbuff2[i])>>8	);
			Ab = 	(u8)((Virtual_LCDbuff2[i]	)	);
			//C_r = A_r * alpha + B_r * (1 - alpha)
			//C_g = A_r * alpha + B_g * (1 - alpha)
			//C_b = A_r * alpha + B_b * (1 - alpha)
			if((Virtual_LCDbuff1[i]&0xFF000000)!=0x00000000 )
			{
				
				//BT0[i] =  Virtual_LCDbuff1[i];
				Br = 	(u8)((Virtual_LCDbuff1[i])>>16	);
			  Bg = 	(u8)((Virtual_LCDbuff1[i])>>8	);
			  Bb = 	(u8)((Virtual_LCDbuff1[i]	)	);
				
				Cr= ((Ar*alpha)>>8) + ((Br*(255-alpha))>>8);
				Cg= ((Ag*alpha)>>8) + ((Bg*(255-alpha))>>8);
				Cb= ((Ab*alpha)>>8) + ((Bb*(255-alpha))>>8);
				
				BT0[i] = 0xFF000000;
				BT0[i]|=(Cr&0x000000FF)<<16;
				BT0[i]|=(Cg&0x000000FF)<<8;
				BT0[i]|=(Cb&0x000000FF);
				
			}
			else //if((Virtual_LCDbuff0[i]&0xFF000000)!=0x00000000 )
			{
				//BT0[i] =  Virtual_LCDbuff0[i];
				Br = 	(u8)((Virtual_LCDbuff0[i])>>16	);
			  Bg = 	(u8)((Virtual_LCDbuff0[i])>>8	);
			  Bb = 	(u8)((Virtual_LCDbuff0[i]	)	);
				
				Cr= ((Ar*alpha)>>8) + ((Br*(255-alpha))>>8);
				Cg= ((Ag*alpha)>>8) + ((Bg*(255-alpha))>>8);
				Cb= ((Ab*alpha)>>8) + ((Bb*(255-alpha))>>8);
				
				BT0[i] = 0xFF000000;
				BT0[i]|=(Cr&0x000000FF)<<16;
				BT0[i]|=(Cg&0x000000FF)<<8;
				BT0[i]|=(Cb&0x000000FF);
			}
			
		}
		else if((Virtual_LCDbuff1[i]&0xFF000000)!=0x00000000 )
		{
		  BT0[i] =  Virtual_LCDbuff1[i];
		}
		else //if((Virtual_LCDbuff0[i]&0xFF000000)!=0x00000000 )
		{
		  BT0[i] =  Virtual_LCDbuff0[i];
		}
	/*	else
		{
		  BT0[i] =  Virtual_LCDbuff3[i];
		}*/
		
	}
//	sysprintf("Virtual_LCD_Upgrate %d ms\r\n",Read_time_ms()-cntt);
	f_need_LCD_Upgrate = FALSE;
}

void Virtual_LCD_Upgrate_formx1y1(int x,int y,int w,int h)
{
	unsigned int *BT0 = (unsigned int *)lcd_pdat->vram[0];
	int i,l;
	unsigned int Ar,Ag,Ab,Br,Bg,Bb,Cr,Cg,Cb;
	unsigned int addr_temp = 0;
	cntt = Read_time_ms();
	for(i=0;i<h;i++)//y
	for(l=0;l<w;l++)//x	
	{
    addr_temp = (y+i)*XSIZE_PHYS+(x+l);
		/*if(((f_ui_disply_keyboard))&&((Virtual_LCDbuff3[addr_temp]&0xFF000000)!=0x00000000 ))
		{

				BT[addr_temp] =  Virtual_LCDbuff3[addr_temp];
		}
		else*/
		/*if((Virtual_LCDbuff2[addr_temp]&0xFF000000)!=0x00000000 )
		{
		  BT[addr_temp] =  Virtual_LCDbuff2[addr_temp];
		}
		else if((Virtual_LCDbuff1[addr_temp]&0xFF000000)!=0x00000000 )
		{
		  BT[addr_temp] =  Virtual_LCDbuff1[addr_temp];
		}
		else
		{
		  BT[addr_temp] =  Virtual_LCDbuff0[addr_temp];
		}*/
		if((Virtual_LCDbuff2[addr_temp]&0xFF000000)!=0x00000000 )
		{
		  //BT0[addr_temp] =  Virtual_LCDbuff2[i];		
      alpha = 	(u8)((Virtual_LCDbuff2[addr_temp])>>24	);
			Ar = 	(u8)((Virtual_LCDbuff2[addr_temp])>>16	);
			Ag = 	(u8)((Virtual_LCDbuff2[addr_temp])>>8	);
			Ab = 	(u8)((Virtual_LCDbuff2[addr_temp]	)	);
			//C_r = A_r * alpha + B_r * (1 - alpha)
			//C_g = A_r * alpha + B_g * (1 - alpha)
			//C_b = A_r * alpha + B_b * (1 - alpha)
			if((Virtual_LCDbuff1[addr_temp]&0xFF000000)!=0x00000000 )
			{
				
				//BT0[addr_temp] =  Virtual_LCDbuff1[i];
				Br = 	(u8)((Virtual_LCDbuff1[addr_temp])>>16	);
			  Bg = 	(u8)((Virtual_LCDbuff1[addr_temp])>>8	);
			  Bb = 	(u8)((Virtual_LCDbuff1[addr_temp]	)	);
				
				Cr= ((Ar*alpha)>>8) + ((Br*(255-alpha))>>8);
				Cg= ((Ag*alpha)>>8) + ((Bg*(255-alpha))>>8);
				Cb= ((Ab*alpha)>>8) + ((Bb*(255-alpha))>>8);
				
				BT0[addr_temp] = 0xFF000000;
				BT0[addr_temp]|=(Cr&0x000000FF)<<16;
				BT0[addr_temp]|=(Cg&0x000000FF)<<8;
				BT0[addr_temp]|=(Cb&0x000000FF);
				
			}
			else //if((Virtual_LCDbuff0[addr_temp]&0xFF000000)!=0x00000000 )
			{
				//BT0[addr_temp] =  Virtual_LCDbuff0[i];
				Br = 	(u8)((Virtual_LCDbuff0[addr_temp])>>16	);
			  Bg = 	(u8)((Virtual_LCDbuff0[addr_temp])>>8	);  
			  Bb = 	(u8)((Virtual_LCDbuff0[addr_temp]	)	);
				
				Cr= ((Ar*alpha)>>8) + ((Br*(255-alpha))>>8);
				Cg= ((Ag*alpha)>>8) + ((Bg*(255-alpha))>>8);
				Cb= ((Ab*alpha)>>8) + ((Bb*(255-alpha))>>8);
				
				BT0[addr_temp] = 0xFF000000;
				BT0[addr_temp]|=(Cr&0x000000FF)<<16;
				BT0[addr_temp]|=(Cg&0x000000FF)<<8;
				BT0[addr_temp]|=(Cb&0x000000FF);
			}
			
		}
		else if((Virtual_LCDbuff1[addr_temp]&0xFF000000)!=0x00000000 )
		{
		  BT0[addr_temp] =  Virtual_LCDbuff1[addr_temp];
		}
		else //if((Virtual_LCDbuff0[addr_temp]&0xFF000000)!=0x00000000 )
		{
		  BT0[addr_temp] =  Virtual_LCDbuff0[addr_temp];
		}


	}
//	sysprintf("Upgrate_formx1y1 %d ms\r\n",Read_time_ms()-cntt);
}

void Virtual_LCD_Clear_ARGB32(unsigned int *layer,unsigned int Color)
{
	 int i;
	unsigned int *BT = layer;
	for(i=0;i<(XSIZE_PHYS*YSIZE_PHYS);i++)
	{
		BT[i] =  Color;
	}
}

void Virtual_LCD_Draw_Rectangle_ARGB32(int x,int y,int w,int h,unsigned int *layer,unsigned int Color)
{
	unsigned int *BT = layer;
	//short *BT1 = (short *)lcd_pdat->vram[0];
	//short temp = 0;
	int i,l;
	for(i=0;i<h;i++)//y
	for(l=0;l<w;l++)//x	
	{
		
		/*temp = 0;
			temp |= ((short)(((0xFF000000 | Color)>>19)<<11))&0xF800;
			temp |= ((short)(((0xFF000000 | Color)>>10)<<5))&0x07E0;
			temp |= ((short)(((0xFF000000 | Color)>>3)))&0x001F;
	BT1[(y+i)*XSIZE_PHYS+(x+l)] = temp;*/
		BT[(y+i)*XSIZE_PHYS+(x+l)] =  Color;
	}
	f_need_LCD_Upgrate = TRUE;
}
void Clean_Virtual_LCDbuff0_2_Rectangle_ARGB32(int x,int y,int w,int h,unsigned int Color)
{
	int i,l,temp;
	for(i=0;i<h;i++)//y
	for(l=0;l<w;l++)//x	
	{
    temp = (y+i)*XSIZE_PHYS+(x+l);
		//Virtual_LCDbuff0[temp] =  Color;
		Virtual_LCDbuff1[temp] =  Color;
		Virtual_LCDbuff2[temp] =  Color;
	}
	f_need_LCD_Upgrate = TRUE;
}

void Virtual_LCD_clean_layer_0_1_2(void)
{
	unsigned int *BT0 = Virtual_LCDbuff0;
	unsigned int *BT1 = Virtual_LCDbuff1;
	unsigned int *BT2 = Virtual_LCDbuff2;
	//short *BT1 = (short *)lcd_pdat->vram[0];
	//short temp = 0;
	int i;
	for(i=0;i<(XSIZE_PHYS*YSIZE_PHYS);i++)
	{
		BT0[i] =  ARGB_clear;
		BT1[i] =  ARGB_clear;
		BT2[i] =  ARGB_clear;
	}
	f_need_LCD_Upgrate = TRUE;
}


/*
LCD 画图片
*/
void Virtual_LCD_Draw_Picture32_ARGB32(int x,int y,int w,int h,unsigned char *pic,unsigned int *layer)
{
	
	  int i,l,a,b;
	unsigned int *BT = layer;
  u32 *tpic=(u32 *)pic;			
	for(i=0;i<h;i++)//y
	{
		a=(y+i)*XSIZE_PHYS+x;     //显示在画布上的位置
		b=w*i;
		for(l=0;l<w;l++)
		{
			if(tpic[b+l]>0x80000000)
			BT[a+l]=tpic[b+l];//把图像数据复制到画布上
		}
	}
	f_need_LCD_Upgrate = TRUE;
}
void Virtual_LCD_Draw_Picture32_ARGB32_from_x1y1(int x,int y,int w,int h,unsigned char *pic,int x1,int y1,int x2,int y2,int x_offet,int y_offet,unsigned int *layer)
{
	
	  int i,l,a,b,tempx,tempy,tempx_offet,tempy_offet;
	unsigned int *BT = layer;;
  u32 *tpic=(u32 *)pic;		
  tempx = x2-x1;
  tempy = y2-y1;  
	tempx_offet = x1-x_offet;
  tempy_offet = y1-y_offet;  
	for(i=0;i<(tempy);i++)//y
	{
		a=(y+i)*XSIZE_PHYS+x;     //显示在画布上的位置
		b=w*(i+tempy_offet)+tempx_offet;
		for(l=0;l<(tempx);l++)
		{
			BT[a+l]=tpic[b+l];//把图像数据复制到画布上
		}
	}
	f_need_LCD_Upgrate = TRUE;

}


/*
显示ASCII
fx =1反显
fd =放大倍数
*/
void Virtual_LCD_Draw_ASCII_ARGB32(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
u8 i,l;
u16 d;
u8 w=16*fd;	
u8 h=32*fd;	
	
	for(i=0;i<h;i+=fd)//y
	{
		d=(ASCII_32_32[n-0x20][i*2/fd]*256)+(ASCII_32_32[n-0x20][i*2/fd+1]);//ASCII_1608
		for(l=0;l<w;l+=fd)//x
		{			
			if(d&0x8000)Virtual_LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Virtual_LCDbuff2,Color1);
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			d=d<<1;	
		}
	}
}
/*
显示String
fx =1反显
fd =放大倍数
*/
void Virtual_LCD_Draw_String_ARGB32(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{

	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB32(x,y,*str,Color1,Color2,fx,fd);
		x+=(16*fd);
		if(x>(XSIZE_PHYS-(16*fd))){y++;x=0;}
		str++;
	}
}



void Virtual_LCD_Draw_ASCII_ARGB64(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 i,l;
u32 d;
u8 w=32*fd;	
u8 h=64*fd;	
	
	for(i=0;i<h;i+=fd)//y
	{
		 
		
		//d=(ASCII_64_64[n-0x20][i*4/fd]<<24)+(ASCII_64_64[n-0x20][i*4/fd+1]<<16)+(ASCII_64_64[n-0x20][i*4/fd+2]<<8)+(ASCII_64_64[n-0x20][i*4/fd+3]);//ASCII_1608
		d=ASCII_64_64[n-0x20][i*4/fd];
		d<<=8;
		d+=ASCII_64_64[n-0x20][i*4/fd+1];
		d<<=8;
		d+=ASCII_64_64[n-0x20][i*4/fd+2];
		d<<=8;
		d+=ASCII_64_64[n-0x20][i*4/fd+3];

		for(l=0;l<w;l+=fd)//x
		{			
			if(d&0x80000000)Virtual_LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Virtual_LCDbuff2,Color1);
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			d=d<<1;	
		}
	}
}


void Virtual_LCD_Draw_String_ARGB64(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{

	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB64(x,y,*str,Color1,Color2,fx,fd);
		x+=(32*fd);
		if(x>(XSIZE_PHYS-(32*fd))){y++;x=0;}
		str++;
	}
}
/*
显示汉字
fx =1反显
fd =放大倍数
*/
void Virtual_LCD_Draw_HZ_ARGB32(int x,int y,int v,unsigned int Color1,unsigned int Color2,int fx,int fd,char * hzprt)
{
u8 i,l,s,d;
u8 w=8*fd;	
u8 h=v*fd;	
u8 e=v/8;	
	for(i=0;i<h;i+=fd)//y
	{
		for(s=0;s<e;s++)
		{
			d=hzprt[(i*e)/fd+s];
			for(l=0;l<w;l+=fd)//x
			{			
				if(d&0x80)Virtual_LCD_Draw_Rectangle_ARGB32((s*w)+x+l,y+i,fd,fd,Virtual_LCDbuff2,Color1);
				else
				{
					if(fx==1)//反显
					{
						Virtual_LCD_Draw_Rectangle_ARGB32((s*w)+x+l,y+i,fd,fd,Virtual_LCDbuff2,Color2);
					}
				}
				d=d<<1;	
			}
	  }
	}
}

	void LCD_Draw_HZ3232_ARGB32(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
	{Virtual_LCD_Draw_HZ_ARGB32(x,y,32,Color1,Color2,fx,fd,(char *)&DZK_32_32_4E00_9FCF[n*128]);}
	
	
	
	
	
	
	
	
	
	////////////////////////////////////////LvglFontTool////////////////////////////////////////////////////////
	
void Virtual_LCD_Draw_ASCII_ARGB48(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+48-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			//if(pos_data>=0x08)Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,color_temp);
			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}


void Virtual_LCD_Draw_String_ARGB48(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=48;
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB48(x,y,*str,Color1,Color2,fx,fd);
		x+=(glyph_dsc[*str-0x20].adv_w*fd);
		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
		str++;
	}
}
void Virtual_LCD_Draw_String_ARGB_align_center_48_4bit(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=24;
	u16 x_offset;
	x_offset = get_str_align_center_x_val(mid_x,str,glyph_dsc);
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB48(x_offset,y,*str,Color1,Color2,fx,fd);
		x_offset+=(glyph_dsc[*str-0x20].adv_w*fd);
		if(x_offset>(XSIZE_PHYS-(H*fd))){y++;x_offset=0;}
		str++;
	}
}
void Virtual_LCD_Draw_ASCII_ARGB_48_4bit_bold(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc_48_4bit_bold[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+48-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap_48_4bit_bold[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			//if(pos_data>=0x08)Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,color_temp);
			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}


void Virtual_LCD_Draw_String_ARGB_48_4bit_bold(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=48;

	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_48_4bit_bold(x,y,*str,Color1,Color2,fx,fd);
		x+=(glyph_dsc_48_4bit_bold[*str-0x20].adv_w*fd);
		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
		str++;
	}
}

void Virtual_LCD_Draw_String_ARGB_align_center_48_4bit_bold(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=24;
	u16 x_offset;
	x_offset = get_str_align_center_x_val(mid_x,str,glyph_dsc_48_4bit_bold);
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_48_4bit_bold(x_offset,y,*str,Color1,Color2,fx,fd);
		x_offset+=(glyph_dsc_48_4bit_bold[*str-0x20].adv_w*fd);
		if(x_offset>(XSIZE_PHYS-(H*fd))){y++;x_offset=0;}
		str++;
	}
}
	////////////////////////////////LVGL/////////////////////////////////////
void Virtual_LCD_Draw_ASCII_ARGB_32_4bit(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc_32_4bit[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+32-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap_32_4bit[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			//if(pos_data>=0x08)Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,color_temp);
			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}


void Virtual_LCD_Draw_String_ARGB_32_4bit(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=32;
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_32_4bit(x,y,*str,Color1,Color2,fx,fd);
		x+=(glyph_dsc_32_4bit[*str-0x20].adv_w*fd);
		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
		str++;
	}
}



void Virtual_LCD_Draw_ASCII_ARGB_32_4bit_bold(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc_32_4bit_bold[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+32-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap_32_4bit_bold[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			//if(pos_data>=0x08)Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,color_temp);
			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}


void Virtual_LCD_Draw_String_ARGB_32_4bit_bold(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=32;
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_32_4bit_bold(x,y,*str,Color1,Color2,fx,fd);
		x+=(glyph_dsc_32_4bit[*str-0x20].adv_w*fd);
		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
		str++;
	}
}

void Virtual_LCD_Draw_String_ARGB_align_center_32_4bit_bold(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=24;
	u16 x_offset;
	x_offset = get_str_align_center_x_val(mid_x,str,glyph_dsc_32_4bit_bold);
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_32_4bit_bold(x_offset,y,*str,Color1,Color2,fx,fd);
		x_offset+=(glyph_dsc_32_4bit_bold[*str-0x20].adv_w*fd);
		if(x_offset>(XSIZE_PHYS-(H*fd))){y++;x_offset=0;}
		str++;
	}
}



	//////
void Virtual_LCD_Draw_ASCII_ARGB_24_4bit(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 H=24;
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc_24_4bit[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+H-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap_24_4bit[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}

//搞个右对齐才行喔 //输入结尾点，往前推字符长度，然后从哪个点输出就好
void Virtual_LCD_Draw_String_ARGB_align_right_4bit(unsigned int glyph_type,int right_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 H = 0;
  u16 x_offset;
	
  // 计算字符串总宽度
  u16 total_width = 0;
  char *ptr = str;
	const lv_font_fmt_txt_glyph_dsc_t *p_buf;
	
	if(glyph_type==8){p_buf = glyph_dsc_8_4bit_bold;H = 8;}
	else if(glyph_type==16){p_buf = glyph_dsc_16_4bit_bold;H = 16;}
	else if(glyph_type==24){p_buf = glyph_dsc_24_4bit_bold;H = 24;}
	else if(glyph_type==32){p_buf = glyph_dsc_32_4bit_bold;H = 32;}
	else if(glyph_type==48){p_buf = glyph_dsc_48_4bit_bold;H = 48;}
	
	
  while(*ptr != '\0') 
	{
		total_width += p_buf[*ptr - 0x20].adv_w * fd;
		ptr++;
  }
  x_offset = right_x - total_width;

  while(*str != '\0') 
	{
		if(glyph_type==8)Virtual_LCD_Draw_ASCII_ARGB_8_4bit(x_offset,y,*str,Color1,Color2,fx,fd);
		else if(glyph_type==16)Virtual_LCD_Draw_ASCII_ARGB_16_4bit(x_offset,y,*str,Color1,Color2,fx,fd);
		else if(glyph_type==24)Virtual_LCD_Draw_ASCII_ARGB_24_4bit(x_offset,y,*str,Color1,Color2,fx,fd);
		else if(glyph_type==32)Virtual_LCD_Draw_ASCII_ARGB_32_4bit(x_offset,y,*str,Color1,Color2,fx,fd);
		else if(glyph_type==48)Virtual_LCD_Draw_ASCII_ARGB48(x_offset,y,*str,Color1,Color2,fx,fd);
		
		x_offset += (p_buf[*str-0x20].adv_w*fd);
		if(x_offset>(XSIZE_PHYS-(H*fd)))
		{
			y++;
			x_offset = 0;
		}
		str++;
  }
}
//void Virtual_LCD_Draw_String_ARGB_24_4bit(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
//{
//  u8 H=24;
//	while(*str!='\0')
//	{
//		Virtual_LCD_Draw_ASCII_ARGB_24_4bit(x,y,*str,Color1,Color2,fx,fd);
//		x+=(glyph_dsc_24_4bit_bold[*str-0x20].adv_w*fd);
//		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
//		str++;
//	}
//}

void Virtual_LCD_Draw_String_ARGB_24_4bit(int x, int y, char *str, unsigned int Color1, unsigned int Color2, int fx, int fd)
{
    if (str == NULL) return; // 1. 增加空指针保护，避免崩溃
    const u8 H = 24;         // 24号字原高度
    u16 current_x = x;       // 用临时变量保存当前X坐标，避免修改入参
    u16 current_y = y;       // 用临时变量保存当前Y坐标

    while (*str != '\0')
    {
        // 边界校验：避免Y坐标超出屏幕高度（YSIZE_PHYS为LCD垂直分辨率）
        if (current_y + H * fd > YSIZE_PHYS)
            break;

        // 绘制单个字符
//        Virtual_LCD_Draw_ASCII_ARGB_24_4bit(current_x, current_y, *str, Color1, Color2, fx, fd);
        
        Virtual_LCD_Draw_ASCII_ARGB_24_4bit(current_x, current_y, *str, Color1, Color2, 1, 1);

        // 2. 修正：水平步进宽度 = 原步进宽度 * 水平缩放因子fx
        u16 char_adv = glyph_dsc_24_4bit_bold[*str - 0x20].adv_w * fx;

        // 3. 修正换行条件：判断下一个字符是否超出屏幕右边界
        if (current_x + char_adv > XSIZE_PHYS)
        {
            current_y += H * fd; // 下移一行（行高=原高度*垂直缩放fd）
            current_x = x;       // 重置X坐标为初始值（而非0，保持左对齐起始位置）
        }
        else
        {
            current_x += char_adv; // 未超界，更新X坐标
        }

        str++;
    }
}

void Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=24;
	u16 x_offset;
	x_offset = get_str_align_center_x_val(mid_x,str,glyph_dsc_24_4bit);
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_24_4bit(x_offset,y,*str,Color1,Color2,fx,fd);
		x_offset+=(glyph_dsc_24_4bit_bold[*str-0x20].adv_w*fd);
		if(x_offset>(XSIZE_PHYS-(H*fd))){y++;x_offset=0;}
		str++;
	}
}


void Virtual_LCD_Draw_ASCII_ARGB_24_4bit_bold(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 H=24;
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc_24_4bit_bold[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+H-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap_24_4bit_bold[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}


void Virtual_LCD_Draw_String_ARGB_24_4bit_bold(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=24;
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_24_4bit_bold(x,y,*str,Color1,Color2,fx,fd);
		x+=(glyph_dsc_24_4bit_bold[*str-0x20].adv_w*fd);
		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
		str++;
	}
}
void Virtual_LCD_Draw_String_ARGB_align_center_24_4bit_bold(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=24;
	u16 x_offset;
	x_offset = get_str_align_center_x_val(mid_x,str,glyph_dsc_24_4bit_bold);
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_24_4bit_bold(x_offset,y,*str,Color1,Color2,fx,fd);
		x_offset+=(glyph_dsc_24_4bit_bold[*str-0x20].adv_w*fd);
		if(x_offset>(XSIZE_PHYS-(H*fd))){y++;x_offset=0;}
		str++;
	}
}


	//////
void Virtual_LCD_Draw_ASCII_ARGB_16_4bit(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 H=16;
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc_16_4bit_bold[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+H-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap_16_4bit_bold[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}


void Virtual_LCD_Draw_String_ARGB_16_4bit(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=16;
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_16_4bit(x,y,*str,Color1,Color2,fx,fd);
		if((*str>=' ')&&(*str<='~'))
		x+=(glyph_dsc_16_4bit_bold[*str-0x20].adv_w*fd);
		else 
			x+=(glyph_dsc_16_4bit_bold[0].adv_w*fd);
		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
		str++;
	}
}
void Virtual_LCD_Draw_String_ARGB_align_center_16_4bit(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=16;
	u16 x_offset;
	x_offset = get_str_align_center_x_val(mid_x,str,glyph_dsc_16_4bit);
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_16_4bit(x_offset,y,*str,Color1,Color2,fx,fd);
		if((*str>=' ')&&(*str<='~'))
		x_offset+=(glyph_dsc_16_4bit_bold[*str-0x20].adv_w*fd);
		else 
			x_offset+=(glyph_dsc_16_4bit_bold[0].adv_w*fd);
		if(x_offset>(XSIZE_PHYS-(H*fd))){y++;x_offset=0;}
		str++;
	}
}


	//////
void Virtual_LCD_Draw_ASCII_ARGB_8_4bit(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 H=8;
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc_8_4bit[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+H-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap_8_4bit[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}


void Virtual_LCD_Draw_String_ARGB_8_4bit(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=8;
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_8_4bit(x,y,*str,Color1,Color2,fx,fd);
		x+=(glyph_dsc_8_4bit[*str-0x20].adv_w*fd);
		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
		str++;
	}
}
void Virtual_LCD_Draw_String_ARGB_align_center_8_4bit(int mid_x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=16;
	u16 x_offset;
	x_offset = get_str_align_center_x_val(mid_x,str,glyph_dsc_8_4bit);
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_8_4bit(x_offset,y,*str,Color1,Color2,fx,fd);
		if((*str>=' ')&&(*str<='~'))
		x_offset+=(glyph_dsc_8_4bit_bold[*str-0x20].adv_w*fd);
		else 
			x_offset+=(glyph_dsc_8_4bit_bold[0].adv_w*fd);
		if(x_offset>(XSIZE_PHYS-(H*fd))){y++;x_offset=0;}
		str++;
	}
}
	//////
void Virtual_LCD_Draw_ASCII_ARGB_8_4bit_bold(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 H=8;
	u8 i,l;
//u32 d;
lv_font_fmt_txt_glyph_dsc_t* p = (lv_font_fmt_txt_glyph_dsc_t*)&glyph_dsc_8_4bit_bold[n-0x20];
u8 w=p->box_w*fd;	
u8 h=p->box_h*fd;	
int x_temp = x+p->ofs_x;
int y_temp = y+H-p->box_h - p->ofs_y;
u8 pos_data;
u32 color_temp;
	for(i=0;i<h;i+=fd)//y
	{		 
		
		for(l=0;l<w;l+=fd)//x
		{			
			pos_data = glyph_bitmap_8_4bit_bold[p->bitmap_index+i*(w/2/fd)+(l/fd)/2];
			color_temp = Color1;
			if((l/fd)%2==0)
				pos_data = (pos_data>>4)&(0x0F);
			else
				pos_data = (pos_data)&(0x0F);
			/*color_temp = 0;
			color_temp |= ((u8)(Color1>>16)*pos_data/0xFF);
			color_temp= color_temp<<16;
			color_temp |= ((u8)(Color1>>8)*pos_data/0xFF);
			color_temp= color_temp<<8;
			color_temp |= ((u8)(Color1)*pos_data/0xFF);*/

			if(pos_data)
			{
				
				Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,((color_temp&0x00FFFFFF)+(((u32)(pos_data<<4))<<24)));
			}
			else
			{
				if(fx==1)//反显
				{
					Virtual_LCD_Draw_Rectangle_ARGB32(x_temp+l,y_temp+i,fd,fd,Virtual_LCDbuff2,Color2);
				}
			}
			
		}
	}
}


void Virtual_LCD_Draw_String_ARGB_8_4bit_bold(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
  u8 H=8;
	while(*str!='\0')
	{
		Virtual_LCD_Draw_ASCII_ARGB_8_4bit_bold(x,y,*str,Color1,Color2,fx,fd);
		x+=(glyph_dsc_8_4bit_bold[*str-0x20].adv_w*fd);
		if(x>(XSIZE_PHYS-(H*fd))){y++;x=0;}
		str++;
	}
}

//显示温度那个小小圆圈
void Virtual_LCD_Draw_String_o(int x,int y,char *str,lv_font_fmt_txt_glyph_dsc_t *buff,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u16 i;
  i=0;				 
				while(!((str[i]=='\0')||(str[i]=='F')||(str[i]=='C')))
				{
          
					 x+=(buff[str[i]-0x20].adv_w);
					i++;

				}
				 Virtual_LCD_Draw_ASCII_ARGB_8_4bit_bold(x-5,y,'o',Color1,Color2,fx,fd);
}

//计算居中的值
u16 get_str_align_center_x_val(u16 center_x_val,char *str,const lv_font_fmt_txt_glyph_dsc_t *glyph_dsc)
{
	u16 x_offset = 0;
	u8 i;
	
		for(i=0;1;i++)
		{
		  if(str[i]!='\0')
				x_offset += (glyph_dsc[str[i]-0x20].adv_w);
			else
				break;
		}
		if(center_x_val>(x_offset/2))
			return center_x_val-(x_offset/2);
				else
					return 0;
}
