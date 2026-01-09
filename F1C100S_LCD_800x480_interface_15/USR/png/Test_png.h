#ifndef _JPEG_TYPE_H_
#define _JPEG_TYPE_H_

#include "png.h"
#include "zlib.h"
//自定义输入数据结构体
typedef struct
{
	unsigned char *image_data;    //图像存储地址
	unsigned int image_size;      //图像尺寸
	unsigned int image_offset;    //图像偏移
}ImageSource;


typedef struct
{
	png_uint_32 width;        //图片宽度
	png_uint_32 height;       //图片高度
	png_color_16p pBackground;//图片背景色
	int bit_depth;            //位深度
	int color_type;           //颜色类型
	int alpha_flag;           //是否有透明通道
	int channels;             //通道数
	double gamma;
	int size;                 //解码后数据大小
	unsigned char *ARGB;      //存储颜色的地址
}Image_inf;


extern int Png_Decode_init(void);
extern int Png_Decode(unsigned char *image_data,unsigned int dataSize);
extern void png_dis(unsigned char *image_data,unsigned int dataSize);
extern void png_dis_xy(png_uint_32 x_val,png_uint_32 y_val,unsigned char *image_data,unsigned int dataSize,unsigned int *layer);

extern void png_dis_xy_form_x1y1_to_x2y2(png_uint_32 x_val,png_uint_32 y_val,\
                                	unsigned char *image_data,unsigned int dataSize,\
		                              png_uint_32 x1,png_uint_32 y1,\
	                                png_uint_32 x2,png_uint_32 y2,\
																	png_uint_32 x_offet,png_uint_32 y_offet,\
																	unsigned int *layer);

extern void png_dis_xy_to_circle(png_uint_32 x_val,png_uint_32 y_val,\
													unsigned char *image_data,unsigned int dataSize,\
													png_uint_32 cx_val,png_uint_32 cy_val,\
													int radius, float percentage,\
													unsigned int *layer);

#endif



