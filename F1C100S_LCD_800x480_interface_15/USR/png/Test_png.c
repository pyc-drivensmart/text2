#include "includes.h"
//#include "P1.c"
//#include "P2.c"
png_structp png_ptr;      //png解码结构体
png_infop   info_ptr;     //png解码信息
png_infop   end_info_ptr; //png解码结束信息

unsigned  char *image_p;
unsigned  char *image_s;
unsigned int len_p;
unsigned int len_s;

ImageSource imagesource;      //图片源
Image_inf image_inf;
/*****************************************************
** @函数名：PngReadCallback
** @描述  ：PNG读如数据回调函数
** @参数  ：png_ptr：
** @返回值：None
*****************************************************/
void PngReadCallback(png_structp png_ptr,png_byte *data,png_size_t length)
{
	ImageSource *isource = (ImageSource *)png_get_io_ptr(png_ptr);
	if((isource->image_offset + length) <= isource->image_size)
	{
		memcpy(data,isource->image_data+isource->image_offset,length);
		isource->image_offset += length;	
	}
}

/*****************************************************
** @函数名：Png_Decode
** @描述  ：PNG图片解码
** @参数  ：png_ptr：
** @返回值：None
*****************************************************/
//uint32_t *Test;

int Png_Decode_init(void)
{
	#if 0
	int i,j,temp;
	int pos = 0;
	png_bytepp row_pointers; //实际存储rgb数据的buf
	
	png_ptr  = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);   //初始化libpng，创建png读取的结构体
	if(png_ptr == NULL)
	{
		return 1;
	}
	info_ptr = png_create_info_struct(png_ptr);                                             //创建图片信息
	if(info_ptr == NULL)
	{
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return 2;
	}
	end_info_ptr = png_create_info_struct(png_ptr); 
	if(end_info_ptr == NULL)
	{
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return 3;
	}	
  if(setjmp(png_jmpbuf(png_ptr)))
  {
		png_destroy_read_struct(&png_ptr, &info_ptr,0);
		return 4;
  }
	#endif
	return 0; 
	
}
unsigned int cntt = 0;
int Png_Decode(unsigned char *image_data,unsigned int dataSize)
{
	int i,j,temp;
	int pos = 0;
	png_bytepp row_pointers; //实际存储rgb数据的buf
	cntt = Read_time_ms();
	png_ptr  = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);   //初始化libpng，创建png读取的结构体
	if(png_ptr == NULL)
	{
		return 1;
	}
	info_ptr = png_create_info_struct(png_ptr);   
  //png_set_filter(png_ptr, PNG_FILTER_TYPE_BASE, PNG_FILTER_VALUE_NONE);
	if(info_ptr == NULL)
	{
		png_destroy_read_struct(&png_ptr, NULL, NULL);
		return 2;
	}
//	end_info_ptr = png_create_info_struct(png_ptr); 
//	if(end_info_ptr == NULL)
//	{
//		png_destroy_read_struct(&png_ptr, NULL, NULL);
//		return 3;
//	}	
  if(setjmp(png_jmpbuf(png_ptr)))
  {
		png_destroy_read_struct(&png_ptr, &info_ptr,0);
		return 4;
  }
	//sysprintf("Time= %d ms\r\n",Read_time_ms());
	imagesource.image_data   = image_data;
	imagesource.image_size   = dataSize;
	imagesource.image_offset = 0;
	png_set_read_fn(png_ptr, &imagesource,PngReadCallback);                             //设置图片读取回调函数，绑定数据数据函数
	png_set_sig_bytes(png_ptr,0);
	//png_read_png(png_ptr, info_ptr,PNG_TRANSFORM_EXPAND|PNG_TRANSFORM_STRIP_ALPHA,0);   //读取文件信息，以及把数据转换为ARGB:8888格式,PNG_TRANSFORM_STRIP_ALPHA:从输入数据中删除亮度字节
	png_read_png(png_ptr, info_ptr,PNG_TRANSFORM_EXPAND,0);
	image_inf.width      = png_get_image_width(png_ptr, info_ptr); //宽
	image_inf.height     = png_get_image_height(png_ptr, info_ptr);//高
	image_inf.channels   = png_get_channels(png_ptr, info_ptr);    //通道数量
	image_inf.color_type = png_get_color_type(png_ptr, info_ptr);  //颜色类型
	image_inf.bit_depth  = png_get_bit_depth(png_ptr, info_ptr);   //位深度
	
	
	row_pointers = png_get_rows(png_ptr, info_ptr); //
	if((image_inf.channels == 4) || (image_inf.color_type == PNG_COLOR_TYPE_RGB_ALPHA))   ////判断是24位还是32位
	{
		image_inf.alpha_flag = 1;                                   //记录是否有透明通道
		image_inf.size = image_inf.width*image_inf.height*4;        //获得解码后的数据长度
		image_inf.ARGB = (png_bytep)malloc(image_inf.size); //分配解码后存储数据的空间
		if(image_inf.ARGB == NULL)
		{
		  png_read_end(png_ptr,info_ptr);
	    png_destroy_read_struct(&png_ptr, &info_ptr, 0);      //释放资源
			return -1;
		}
		for(i=0;i<image_inf.height;i++)
		{
			for(j=0;j<image_inf.width*4;)
			{
				image_inf.ARGB[pos++] = row_pointers[i][j + 2];   //R
				image_inf.ARGB[pos++] = row_pointers[i][j + 1];   //G
				image_inf.ARGB[pos++] = row_pointers[i][j + 0];   //B
				image_inf.ARGB[pos++] = row_pointers[i][j + 3];   //A：转换出来的数据是RGBA
				//sysprintf("**%x",row_pointers[i][j + 3]);
				j=j+4;
			}
		}
	}
	else if((image_inf.channels == 3) || (image_inf.color_type == PNG_COLOR_TYPE_RGB))    //24位颜色
	{
		image_inf.alpha_flag = 0; //记录是否有透明通道
		image_inf.size = image_inf.width*image_inf.height*4;        //获得解码后的数据长度
		image_inf.ARGB = (png_bytep)malloc(image_inf.size); //分配解码后存储数据的空间
		if(image_inf.ARGB == NULL)
		{
		  png_read_end(png_ptr,info_ptr);
	    png_destroy_read_struct(&png_ptr, &info_ptr, 0);      //释放资源
			return -1;
		}		
		temp = 3*image_inf.width;
		for(i=0;i<image_inf.height;i++)
		{
			for(j=0;j<temp;j+=3)
			{
				image_inf.ARGB[pos++] = row_pointers[i][j+2];	   //R
				image_inf.ARGB[pos++] = row_pointers[i][j+1];    //G
				image_inf.ARGB[pos++] = row_pointers[i][j+0];    //B
				image_inf.ARGB[pos++] = 0xFF;
			}
		}
	}
	else
	{
		return -1;
	}
	sysprintf("Time= %d ms --",Read_time_ms()-cntt);
	//Test = (uint32_t *)image_inf.ARGB;
	//LCD_Draw_Picture32_ARGB32(0,0,image_inf.width,image_inf.height,image_inf.ARGB);//显示到LCD
	//free(image_inf.ARGB);                      //释放内存
	
	png_destroy_read_struct(&png_ptr, &info_ptr, 0);   //解码完成，释放资源
	return 0; 
}

/*****************************************************
** @函数名：Test_png
** @描述  ：PNG图片解码测试
** @参数  ：
** @返回值：None
*****************************************************/
void png_dis(unsigned char *image_data,unsigned int dataSize)
{
	/*背景色*/
	//LCD_Clear_ARGB32(0xFF0000FF);
	/*前景png图片*/	
	//int time=Read_time_ms();	
	if(Png_Decode(image_data,dataSize)==0) 
	{
	  LCD_Draw_Picture32_ARGB32(0,0,image_inf.width,image_inf.height,image_inf.ARGB);//显示到LCD	  
	}
	free(image_inf.ARGB);                      //释放内存
	
	//png_dis(_acp1,sizeof(_acp1)); 
	//sysprintf("Time= %d ms\r\n",Read_time_ms()-time);
}


void png_dis_xy(png_uint_32 x_val,png_uint_32 y_val,unsigned char *image_data,unsigned int dataSize,unsigned int *layer)
{
	/*背景色*/
	//LCD_Clear_ARGB32(0xFF0000FF);
	/*前景png图片*/	
	//int time=Read_time_ms();	
	if(dataSize!=0)//空图片
	{
		if(Png_Decode(image_data,dataSize)==0) 
		{
			Virtual_LCD_Draw_Picture32_ARGB32(x_val,y_val,image_inf.width,image_inf.height,image_inf.ARGB,layer);//显示到LCD	  
		}
		free(image_inf.ARGB);                      //释放内存
		sysprintf("png display\r\n");
		//png_dis(_acp1,sizeof(_acp1)); 
		//sysprintf("Time= %d ms\r\n",Read_time_ms()-time);
 }
}

//设定显示图片范围
void png_dis_xy_form_x1y1_to_x2y2(png_uint_32 x_val,png_uint_32 y_val,\
                                	unsigned char *image_data,unsigned int dataSize,\
		                              png_uint_32 x1,png_uint_32 y1,\
	                                png_uint_32 x2,png_uint_32 y2,\
																	png_uint_32 x_offet,png_uint_32 y_offet,\
																	unsigned int *layer)
{

	if(Png_Decode(image_data,dataSize)==0) 
	{
	  Virtual_LCD_Draw_Picture32_ARGB32_from_x1y1(x_val,y_val,image_inf.width,image_inf.height,image_inf.ARGB,x1,y1,x2,y2,x_offet,y_offet,layer);//显示到LCD	  
	}
	free(image_inf.ARGB);                      //释放内存
	//sysprintf("6666666666666666666\r\n");
	//png_dis(_acp1,sizeof(_acp1)); 
	//sysprintf("Time= %d ms\r\n",Read_time_ms()-time);
}

#include <math.h>
#define PI 3.14159265358979323846
																							//×óÉÏ½ÇX£¬Y,¿í£¬¸ß£¬   cx=Ô²ÐÄX  Cy=Ô²ÐÄY £¬radius = °ë¾¶   £¬percentage = °Ù·Ö±È
void Virtual_LCD_Draw_Picture32_ARGB32_circuit(int x, int y, int w, int h, unsigned char *pic, unsigned int *layer, int cx, int cy, int radius, float percentage) 
{
	int i, l, a, b;
	unsigned int *BT = layer;
	u32 *tpic = (u32*)pic;

	if (percentage == 100.0) 
	{
		for (i = 0; i < h; i++) 
		{ // 遍历图片的高度 (y 方向)
			a = (y + i) * XSIZE_PHYS + x; // 计算在画布上的目标位置
			b = w * i; // 计算在图片数据中的位置
	
			for (l = 0; l < w; l++)
			{ // 遍历图片的宽度 (x 方向)
				int px = x + l; // 当前像素的屏幕位置 x 坐标
				int py = y + i; // 当前像素的屏幕位置 y 坐标
	
				// 计算像素点与圆心的距离
				int dx = px - cx;
				int dy = py - cy;
				float distance_squared = dx * dx + dy * dy;
	
				// 判断是否在圆形范围内
				if (distance_squared <= radius * radius) 
				{
					// 只有透明度大于阈值的像素才绘制
					if (tpic[b + l] > 0x80000000) 
					{
						BT[a + l] = tpic[b + l]; // 将图像数据复制到画布上
					}
				}
			}
		}
	
		f_need_LCD_Upgrate = TRUE; // 标记需要更新 LCD
		return; // 绘制完成，直接退出
	}
	else
	{
		float angle_start = -90.0; 
		float angle_end = angle_start+360.0*(percentage/100.0); 
		for(i = 0; i<h; i++) 
		{ 
			a = (y+i)*XSIZE_PHYS+x; 
			b = w*i;
			
			for(l=0; l<w; l++) 
			{ 
				int px = x + l; 
				int py = y + i;
				
							
				int dx = px - cx;
				int dy = py - cy;
				float distance_squared = dx * dx + dy * dy;
		
		
				if(distance_squared <= radius * radius) 
				{
					float angle = atan2(dy, dx)*180.0/PI;
					if(angle < 0) angle += 360.0; 
					
					float angle_start_norm = angle_start;
					float angle_end_norm = angle_end;
					if(angle_start_norm<0) angle_start_norm+=360.0;
					if(angle_end_norm<0) angle_end_norm+=360.0;
					if ((angle_start_norm <= angle_end_norm && angle >= angle_start_norm && angle <= angle_end_norm) || 
											(angle_start_norm > angle_end_norm && (angle >= angle_start_norm || angle <= angle_end_norm)))
					{
						if(tpic[b + l]>0x80000000) 
						{
							BT[a + l] = tpic[b + l]; 
						}
					}
				}
			}
		}
	}
}


void png_dis_xy_to_circle(png_uint_32 x_val,png_uint_32 y_val,\
													unsigned char *image_data,unsigned int dataSize,\
													png_uint_32 cx_val,png_uint_32 cy_val,\
													int radius, float percentage,\
													unsigned int *layer)
{
	if(Png_Decode(image_data,dataSize)==0) 
	{
		//(int x, int y, int w, int h, unsigned char *pic, unsigned int *layer, int cx, int cy, int radius, float percentage) 
		Virtual_LCD_Draw_Picture32_ARGB32_circuit(x_val,y_val,image_inf.width,image_inf.height,image_inf.ARGB,layer,cx_val,cy_val,radius,percentage);
	}
	free(image_inf.ARGB);
}

