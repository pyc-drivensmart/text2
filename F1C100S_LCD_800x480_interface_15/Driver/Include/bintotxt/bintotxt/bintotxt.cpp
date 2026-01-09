// bintotxt.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
int cntt = 0;
int hexCharToValue(char ch)
{
  int result = 0;

  if(ch >= '0' && ch <= '9')
  {
    result = (int)(ch - '0');
  }
  else if(ch >= 'a' && ch <= 'z')
  {
    result = (int)(ch - 'a') + 10;
  }
  else if(ch >= 'A' && ch <= 'Z')
  {
    result = (int)(ch - 'A') + 10;
  }
  else
  {
    result = -1;
  }
  return result;
}
 
int main (int argc, char *argv[]) 
{ 
  FILE *fid_in, *fid_out; 
  unsigned char data[32]; 
  unsigned char data_temp;
  int i, cnt; 

  argv[1]=".\\D2AUDIO_MCU_PROJECT.hex";
  argv[2]=".\\MCU_UPGRATE.dat";
   
  fid_in = fopen(argv[1], "rt");   
  fid_out = fopen(argv[2], "w+");  
 
  if(fid_in == 0)  
  { 
    printf("\n没有找到D2AUDIO_MCU_PROJECT.hex !"); 
	getchar();
    exit(0); 
  } 
  if(fid_out == 0)  
  { 
    printf("\n没法输出MCU_UPGRATE.dat!"); 
	getchar();
    exit(0); 
  } 
    
  while(1) 
  { 
    cnt = fread(&data, 1, 16, fid_in); 
    if(cnt == 0)break;  
    for(i=0; i<cnt; i++) 
    { 
	  
	 /* if((data[i]&0x01)!=0) data_temp=0x80;
	  else data_temp=0x00;
	  if((data[i]&0x02)!=0) data_temp+=0x40;
	  if((data[i]&0x04)!=0) data_temp+=0x20;
	  if((data[i]&0x08)!=0) data_temp+=0x10;
	  if((data[i]&0x10)!=0) data_temp+=0x08;
	  if((data[i]&0x20)!=0) data_temp+=0x04;
	  if((data[i]&0x40)!=0) data_temp+=0x02;
	  if((data[i]&0x80)!=0) data_temp+=0x01;*/

      fprintf(fid_out, "0x%02X,", data[i]); 
    } 
    fprintf(fid_out, "\n"); 
  } 
  
  fclose(fid_in); 
  fclose(fid_out); 
  printf("\D2AUDIO_MCU_PROJECT.hex转换完成，输出文件为MCU_UPGRATE.dat!\n");  
  //exit(0); 



  argv[1]=".\\boot.d2e";
  argv[2]=".\\DSP_UPGRATE.dat";
   
  fid_in = fopen(argv[1], "rt");   
  fid_out = fopen(argv[2], "w+");  
 
  if(fid_in == 0)  
  { 
    printf("\n没有找到boot.d2e !"); 
	getchar();
    exit(0); 
  } 
  if(fid_out == 0)  
  { 
    printf("\n没法输出DSP_UPGRATE.dat!");
	getchar();
    exit(0); 
  } 


    
  while(1) 
  { 
    cnt = fread(&data, 1, 7, fid_in); 
    if(cnt == 0)break;  
    for(i=0; i<(cnt-1); i+=2) 
    {

		data_temp = ((hexCharToValue(data[i])<<4)&0xF0) + (hexCharToValue(data[i+1])&0x0F);
      fprintf(fid_out, "0x%02X,", data_temp); 
    } 
    fprintf(fid_out, "\n"); 
  } 
  
  fclose(fid_in); 
  fclose(fid_out); 
  printf("\nboot.d2e转换完成，输出文件为DSP_UPGRATE.dat!\n"); 
  //getchar();
  //exit(0); 


  argv[1]=".\\d2audio.hex";
  argv[2]=".\\ROM_UPGRATE.dat";
   
  fid_in = fopen(argv[1], "rb");   
  fid_out = fopen(argv[2], "w+");  
 
  if(fid_in == 0)  
  { 
    printf("\n没有找到d2audio.hex !"); 
	getchar();
    exit(0); 
  } 
  if(fid_out == 0)  
  { 
    printf("\n没法输出ROM_UPGRATE.dat!");
	getchar();
    exit(0); 
  } 
    fseek(fid_in,0x4e00*128,0);
	cntt = 0x4e00*128;//32*32的：*128    64*64的：*512 太大
  while(1) 
  { 
    /*cnt = fread(&data, 1, 16, fid_in); 
    if(cnt == 0)break;  
    for(i=0; i<cnt; i++) 
    {
	  if((data[i]&0x01)!=0) data_temp=0x80;
	  else data_temp=0x00;
	  if((data[i]&0x02)!=0) data_temp+=0x40;
	  if((data[i]&0x04)!=0) data_temp+=0x20;
	  if((data[i]&0x08)!=0) data_temp+=0x10;
	  if((data[i]&0x10)!=0) data_temp+=0x08;
	  if((data[i]&0x20)!=0) data_temp+=0x04;
	  if((data[i]&0x40)!=0) data_temp+=0x02;
	  if((data[i]&0x80)!=0) data_temp+=0x01;
      fprintf(fid_out, "0x%02X,", data_temp); 
    } */
	cnt = fread(&data, 1,4, fid_in); 
    
    if(cnt == 0)break;  
	cntt+=cnt;
	
    for(i=0; i<(cnt); i++) 
    {

		//data_temp = ((hexCharToValue(data[i])<<4)&0xF0) + (hexCharToValue(data[i+1])&0x0F);
      fprintf(fid_out, "0x%02X,", data[i]); 
    } 

    fprintf(fid_out, "\n"); 
	if(cntt>=0x9FCF*128)
		break;
  } 
  
  fclose(fid_in); 
  fclose(fid_out); 
  printf("\nd2audio.hex转换完成，输出文件为ROM_UPGRATE.dat!\n"); 
  getchar();
  exit(0); 
 
} 



#if 0
#include <stdio.h>    
#include <stdlib.h>    
#include <string.h>    
   
   
int main (int argc, char *argv[])   
{   
  FILE *fid_in, *fid_out;   
  unsigned int data[8];   
  int i, cnt;   
  char *ptr1;   
     
  fid_in = fopen(argv[1], "rb");     
  fid_out = fopen(argv[2], "w+");    
   
  if(fid_in == 0)    
  {   
    printf("\n input open NG !");   
    exit(0);   
  }   
  if(fid_out == 0)    
  {   
    printf("\n output open NG !");   
    exit(0);   
  }   
   
    ptr1 = argv[1];       
    fprintf(fid_out, "unsigned int %s[] = {\n", ptr1);   
     
  while(1)   
  {   
    cnt = fread(&data, 4, 8, fid_in);   
    /*end with 0*/   
    if(cnt == 0) break;   
   
    for(i=0; i<cnt; i++)   
    {   
      fprintf(fid_out, "0x%08X, ", data[i]);   
    }   
    fprintf(fid_out, "\n");   
  }   
   
  fprintf(fid_out, "};\n");   
   
  fclose(fid_in);   
  fclose(fid_out);   
  exit(0);   
   
}
#endif