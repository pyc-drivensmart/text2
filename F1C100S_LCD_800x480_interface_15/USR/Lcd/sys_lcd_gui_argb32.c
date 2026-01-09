#include "includes.h"

//unsigned int *BT1=(unsigned int *)LCDbuff1;

/*
清LCD到指定色
*/
void LCD_Clear_ARGB32(unsigned int Color)
{
	int i;
	unsigned int *BT1 = (unsigned int *)lcd_pdat->vram[0];
	for(i=0;i<(XSIZE_PHYS*YSIZE_PHYS);i++)
	{
		BT1[i] =  Color;
	}
}
void LCD_Clear_ARGB32_1(unsigned int Color)
{
	int i;
	unsigned int *BT1 = (unsigned int *)lcd_pdat->vram[1];
	for(i=0;i<(XSIZE_PHYS*YSIZE_PHYS);i++)
	{
		BT1[i] =  Color;
	}
}
/*
LCD 画点
*/
void LCD_Draw_Points_ARGB32(int x,int y,unsigned int Color)
{
	unsigned int *BT1  = (unsigned int *)lcd_pdat->vram[0];
	BT1[y*XSIZE_PHYS+x]= 0xFF000000 | Color;
}
/*
LCD 画矩形 
*/
void LCD_Draw_Rectangle_ARGB32(int x,int y,int w,int h,unsigned int Color)
{
	unsigned int *BT1 = (unsigned int *)lcd_pdat->vram[1];
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
		BT1[(y+i)*XSIZE_PHYS+(x+l)] = 0xFF000000 | Color;
	}
}
/*
LCD 画图片
*/
void LCD_Draw_Picture32_ARGB32(int x,int y,int w,int h,unsigned char *pic)
{
	
	  int i,l,a,b;
	unsigned int *BT0 = (unsigned int *)lcd_pdat->vram[0];
  u32 *tpic=(u32 *)pic;			
	for(i=0;i<h;i++)//y
	{
		a=(y+i)*XSIZE_PHYS+x;     //显示在画布上的位置
		b=w*i;
		for(l=0;l<w;l++)
		{
			BT0[a+l]=tpic[b+l];//把图像数据复制到画布上
		}
	}
}
void LCD_Draw_Picture32_ARGB32_from_x1y1(int x,int y,int w,int h,unsigned char *pic,int x1,int y1,int x2,int y2)
{
	
	  int i,l,a,b;
	unsigned int *BT1 = (unsigned int *)lcd_pdat->vram[1];
  u32 *tpic=(u32 *)pic;			
	for(i=0;i<(y2-y1);i++)//y
	{
		a=(y+i)*XSIZE_PHYS+x;     //显示在画布上的位置
		b=w*(i+y1)+x1;
		for(l=0;l<(x2-x1);l++)
		{
			BT1[a+l]=tpic[b+l];//把图像数据复制到画布上
		}
	}

/*
  int i,l,a,b;
	short temp = 0;
	short *BT1 = (short *)lcd_pdat->vram[1];
  u32 *tpic=(u32 *)pic;			
	for(i=0;i<h;i++)//y
	{
		a=(y+i)*XSIZE_PHYS+x;     //显示在画布上的位置
		b=w*i;
		for(l=0;l<w;l++)
		{
			//RGB565  RRRR RGGG GGGB BBBB
			//                24        16        8
			//RGBA  RRRR RRRR GGGG GGGG BBBB BBBB AAAA AAAA
			temp = 0;
			temp |= ((short)((tpic[b+l]>>27)<<11))&0xF800;
			temp |= ((short)((tpic[b+l]>>18)<<5))&0x07E0;
			temp |= ((short)((tpic[b+l]>>11)))&0x001F;
			
			//ARGB  AAAA AAAA RRRR RRRR GGGG GGGG BBBB BBBB 
			temp = 0;
			temp |= ((short)((tpic[b+l]>>19)<<11))&0xF800;
			temp |= ((short)((tpic[b+l]>>10)<<5))&0x07E0;
			temp |= ((short)((tpic[b+l]>>3)))&0x001F;
			
			BT1[a+l]=temp;//把图像数据复制到画布上
		}
	}*/
}

/*
显示ASCII
fx =1反显
fd =放大倍数
*/
void LCD_Draw_ASCII_ARGB32(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	/*
u8 i,l,d;
u8 w=8*fd;	
u8 h=16*fd;	
	
	for(i=0;i<h;i+=fd)//y
	{
		d=ASCII_1608[n-0x20][i/fd];
		//d=ASCII_32_32[n-0x20][i/fd];//ASCII_1608
		for(l=0;l<w;l+=fd)//x
		{			
			if(d&0x80)LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color1);
			else
			{
				if(fx==1)//反显
				{
					LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color2);
				}
			}
			d=d<<1;	
		}
	}
	*/
	u8 i,l;
u16 d;
u8 w=16*fd;	
u8 h=32*fd;	
	
	for(i=0;i<h;i+=fd)//y
	{
		d=(ASCII_32_32[n-0x20][i*2/fd]*256)+(ASCII_32_32[n-0x20][i*2/fd+1]);//ASCII_1608
		for(l=0;l<w;l+=fd)//x
		{			
			if(d&0x8000)LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color1);
			else
			{
				if(fx==1)//反显
				{
					LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color2);
				}
			}
			d=d<<1;	
		}
	}
}
void LCD_Draw_ASCII_ARGB64(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
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
			if(d&0x80000000)LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color1);
			else
			{
				if(fx==1)//反显
				{
					LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color2);
				}
			}
			d=d<<1;	
		}
	}
}
void LCD_Draw_ASCII_ARGB128(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	u8 i,l;
u32 d,d1;
u8 w=64*fd;	
u8 h=128*fd;	
	
	for(i=0;i<h;i+=fd)//y
	{
		 
		
		//d=(ASCII_64_64[n-0x20][i*4/fd]<<24)+(ASCII_64_64[n-0x20][i*4/fd+1]<<16)+(ASCII_64_64[n-0x20][i*4/fd+2]<<8)+(ASCII_64_64[n-0x20][i*4/fd+3]);//ASCII_1608
		d=ASCII_128_128[n-0x20][i*8/fd];
		d<<=8;
		d+=ASCII_128_128[n-0x20][i*8/fd+1];
		d<<=8;
		d+=ASCII_128_128[n-0x20][i*8/fd+2];
		d<<=8;
		d+=ASCII_128_128[n-0x20][i*8/fd+3];
		
		d1=ASCII_128_128[n-0x20][i*8/fd+4];
		d1<<=8;
		d1+=ASCII_128_128[n-0x20][i*8/fd+5];
		d1<<=8;
		d1+=ASCII_128_128[n-0x20][i*8/fd+6];
		d1<<=8;
		d1+=ASCII_128_128[n-0x20][i*8/fd+7];

		for(l=0;l<w;l+=fd)//x
		{		
      if(l<32)
			{				
			if(d&0x80000000)LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color1);
			else
			{
				if(fx==1)//反显
				{
					LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color2);
				}
			}
			d=d<<1;	
		  }
			else
			{
			  if(d1&0x80000000)LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color1);
			else
			{
				if(fx==1)//反显
				{
					LCD_Draw_Rectangle_ARGB32(x+l,y+i,fd,fd,Color2);
				}
			}
			d1=d1<<1;	
			}
		}
	}
}
/*
显示String
fx =1反显
fd =放大倍数
*/
void LCD_Draw_String_ARGB32(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	/*while(*str!='\0')
	{
		LCD_Draw_ASCII_ARGB32(x,y,*str,Color1,Color2,fx,fd);
		x+=(8*fd);
		if(x>(XSIZE_PHYS-(8*fd))){y++;x=0;}
		str++;
	}*/

	while(*str!='\0')
	{
		LCD_Draw_ASCII_ARGB32(x,y,*str,Color1,Color2,fx,fd);
		x+=(16*fd);
		if(x>(XSIZE_PHYS-(32*fd))){y++;x=0;}
		str++;
	}
}
void LCD_Draw_String_ARGB64(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	while(*str!='\0')
	{
		LCD_Draw_ASCII_ARGB64(x,y,*str,Color1,Color2,fx,fd);
		x+=(32*fd);
		if(x>(XSIZE_PHYS-(64*fd))){y++;x=0;}
		str++;
	}
}
void LCD_Draw_String_ARGB128(int x,int y,char *str,unsigned int Color1,unsigned int Color2,int fx,int fd)
{
	while(*str!='\0')
	{
		LCD_Draw_ASCII_ARGB128(x,y,*str,Color1,Color2,fx,fd);
		x+=(64*fd);
		if(x>(XSIZE_PHYS-(128*fd))){y++;x=0;}
		str++;
	}
}
/*
显示16色位图片
*/
void LCD_Draw_Picture_ARGB32(int x,int y,int w,int h,char *pic)
{
	/*
	unsigned int *BT1 = (unsigned int *)lcd_pdat->vram[0];
	int i,l,a,b;
	short *tpic=(short *)pic;			
	for(i=0;i<h;i++)//y
	{
		a=(y+i)*XSIZE_PHYS+x;
		b=w*i;
		for(l=0;l<w;l++)BT1[a+l]=tpic[b+l];
	}
	*/
	//ARGB888->RGB565
	short temp;
	short*BT1 = (short *)lcd_pdat->vram[0];
	int i,l,a,b;
	u32 *tpic=(u32 *)pic;			
	for(i=0;i<h;i++)//y
	{
		a=(y+i)*XSIZE_PHYS+x;
		b=w*i;
		for(l=0;l<w;l++)
		{
			temp = 0;
			//RGBA
			temp |= ((short)((tpic[b+l]>>27)<<11)&0xF800);
			temp |= ((short)((tpic[b+l]>>18)<<5)&0x07E0);
			temp = ((short)((tpic[b+l]>>11))&0x001F);
			/*//ARGB
			temp |= ((short)((tpic[b+l]>>19)<<11)&0xF800);
			temp |= ((short)((tpic[b+l]>>10)<<5)&0x07E0);
			temp = ((short)((tpic[b+l]>>3))&0x001F);*/
		  BT1[a+l]=temp;;
		}
	}
}

/*
读16色位显存 
*/
void LCD_Read_Lcdbuff_ARGB32(int x,int y,int w,int h,char *pic)
{
	unsigned int *BT1 = (unsigned int *)lcd_pdat->vram[0];
	int i,l,a,b;
	short *tpic=(short *)pic;			
	for(i=0;i<h;i++)//y
	{
		a=(y+i)*XSIZE_PHYS+x;
		b=w*i;
		for(l=0;l<w;l++)tpic[b+l]=BT1[a+l];
	}
}
/*
显示汉字
fx =1反显
fd =放大倍数
*/
void LCD_Draw_HZ_ARGB32(int x,int y,int v,unsigned int Color1,unsigned int Color2,int fx,int fd,char * hzprt)
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
				if(d&0x80)LCD_Draw_Rectangle_ARGB32((s*w)+x+l,y+i,fd,fd,Color1);
				else
				{
					if(fx==1)//反显
					{
						LCD_Draw_Rectangle_ARGB32((s*w)+x+l,y+i,fd,fd,Color2);
					}
				}
				d=d<<1;	
			}
	  }
	}
}



//void LCD_Draw_HZ1616_ARGB32(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
//	{LCD_Draw_HZ_ARGB32(x,y,16,Color1,Color2,fx,fd,(char *)HZ_1616[n]);}
//void LCD_Draw_HZ2424_ARGB32(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
//	{LCD_Draw_HZ_ARGB32(x,y,24,Color1,Color2,fx,fd,(char *)HZ_2424[n]);}
//void LCD_Draw_HZ3232_ARGB32(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
//	{LCD_Draw_HZ_ARGB32(x,y,32,Color1,Color2,fx,fd,(char *)HZ_3232[n]);}
//void LCD_Draw_HZ4040_ARGB32(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
//	{LCD_Draw_HZ_ARGB32(x,y,40,Color1,Color2,fx,fd,(char *)HZ_4040[n]);}
//void LCD_Draw_HZ4848_ARGB32(int x,int y,int n,unsigned int Color1,unsigned int Color2,int fx,int fd)
//	{LCD_Draw_HZ_ARGB32(x,y,48,Color1,Color2,fx,fd,(char *)HZ_4848[n]);}

