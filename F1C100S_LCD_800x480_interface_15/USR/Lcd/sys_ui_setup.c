#include "includes.h"



#define Setup_PAGE_ITEM_NUM  13

lcd_dis_item_t *p_home_item_5_chun_u4[Setup_PAGE_ITEM_NUM]={
      &t_page6_select                             ,
      &t_page6_select_2                          ,
      &t_page6_select_3                          ,
      &t_page6_select_4                          ,//（0~3）
    
     &t_page6_up_up                              ,//4
 &t_page6_down_up                            ,
    

    &t_page6_left_up                            ,
 &t_page6_right_up                           ,    
    
&t_page6_temp_icon                          ,
 &t_page6_time_icon                          ,
 &t_page6_upgrade_icon                       ,
 &t_page6_upgrade_icon_3                     ,
 &t_page6_Ver_icon                           ,
};						




lcd_dis_item_t *p_home_item_5_chun_d4[Setup_PAGE_ITEM_NUM]={

   &t_page6_no_select                          ,//03
      &t_page6_no_select2                          ,
      &t_page6_no_select3                          ,
      &t_page6_no_select4                          ,  

    
     &t_page6_up_d                               ,
 &t_page6_down_d                             ,
    

   &t_page6_left_d                             ,
 &t_page6_right_d                            ,  
    
 &t_page6_temp_icon                          ,
 &t_page6_time_icon                          ,
 &t_page6_upgrade_icon                       ,
 &t_page6_upgrade_icon_3                     ,
 &t_page6_Ver_icon                           ,
};						 



setup_page_t setup_page_sta2;

lcd_dis_item_t Setup_item[Setup_PAGE_ITEM_NUM];//图片缓存区



u8 setup_page_display_num2 = 4;


setup_item_info_t System_info2[];

setup_item_info_t setup_setting2[]=
{
   /// {"Temperature unit",TOUCH_TYPE_NONE,empty_father_p,System_info2,empty_fun},  //显示没有触摸
        {"Temperature unit",TOUCH_TYPE_ENTER,empty_father_p,System_info2,empty_fun},  
	{"Data&Time",TOUCH_TYPE_ENTER,empty_father_p,System_info2,empty_fun},
   // {"Data&Time",TOUCH_TYPE_ENTER,empty_father_p,Data_Time,empty_fun},

	{"Version Information",TOUCH_TYPE_ENTER,empty_father_p,System_info2,empty_fun},
	{"CanBus UpGrade",TOUCH_TYPE_ENTER,empty_father_p,System_info2,empty_fun},
	{"end",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},

};

setup_item_info_t System_info2[]=
{
	{"System info2",TOUCH_TYPE_SAVE_AND_BACK,setup_setting2,empty_son_p,empty_fun},
    
	{" no touch:",TOUCH_TYPE_NONE,setup_setting2,empty_son_p,empty_fun},    //显示没有触摸
    
	{"nex:",TOUCH_TYPE_ENTER,setup_setting2,empty_son_p,empty_fun},//正常  点一下进入下一级
//	{"MCU Software:",TOUCH_TYPE_NONE,setup_setting,empty_son_p,empty_fun},

	{"",END_OF_THE_LIST,empty_father_p,empty_son_p,empty_fun},
};








void display_column_setup_page2(bool upgrage_dispaly,bool upgrage,setup_page_t *setup_page_p,lcd_dis_item_t *setup_item_p,char* display_buf)
{
	setup_item_info_t *setup_p; 
	u8 i;
		
	if(setup_page_p->now_p==empty_son_p)//末项，无次级
	{
		setup_page_p->max_page_num = 0;//
		return;
	}
	else
	{
		for(i=0;1;i++)
		{
			if(setup_page_p->now_p[i].setup_menu_touch_type == END_OF_THE_LIST)  //结束
			{
				 setup_page_p->max_page_num = i;
				 break;
			}
		}
	}
	//PAGE_DISPLAY_ITEM_NUM
	if(setup_page_p->now_page_num==0)//判断页数，0页，翻页选项不可用
		setup_item_p[4].key_type = KEY_TYPE_TOUCH_NONE;//prepage  //不进行触摸 弹起图标当背景显示 
	else
		setup_item_p[4].key_type = KEY_TYPE_ONCE;//启用向下翻页
	 
	if((setup_page_p->now_page_num+1)*setup_page_display_num2<setup_page_p->max_page_num)
		setup_item_p[5].key_type = KEY_TYPE_ONCE;//prepage
	else
		setup_item_p[5].key_type = KEY_TYPE_TOUCH_NONE;//启用向上翻页

  	if(setup_page_p->now_p[0].father_p!=empty_father_p)	  //back
	{
		setup_item_p[26].key_type = KEY_TYPE_ONCE;// 
	}
//	else 
//	{
//		setup_item_p[26].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//  //不进行触摸 也不显示
//		setup_item_p[26].last_status = STATUS_IDLE;
//		setup_item_p[26].now_status = STATUS_IDLE;
//	}
	
	if(upgrage)
  {
		Virtual_LCD_Draw_Rectangle_ARGB32(25,50,690,400,Virtual_LCDbuff2,ARGB_clear);
		//Virtual_LCD_Draw_String_ARGB_24_4bit(297,80,display_buf,(0xFF78baf7),0,1,1);
		Virtual_LCD_Draw_String_ARGB_24_4bit(95,98,display_buf,(0xFF78baf7),0,1,1);//字体坐标？

	}
	 
	 
	for(i=0;i<setup_page_display_num2;i++)//单页选项数
	{
		setup_p = &setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num2+i];
		if((setup_page_p->now_page_num*setup_page_display_num2+i)<setup_page_p->max_page_num)
		{
			if(upgrage)
	    {
				//Virtual_LCD_Draw_Rectangle_ARGB32(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+Y_system_system_offset,700,24,Virtual_LCDbuff2,ARGB_clear);
		    if(setup_p->setup_menu_touch_type==TOUCH_TYPE_NONE_DIS_DIM)//显示没有触摸 浅色显示
				{
					if((setup_p->father_p!=empty_father_p)&&(i==0))
					//if((setup_page_p->now_p == Power_System_Setting)&&((setup_page_p->now_page_num!=1)||(i<2)))
						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+330,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num2+i].display_str,(ARGB_gray),0,1,1);
					else
						Virtual_LCD_Draw_String_ARGB_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num2+i].display_str,(ARGB_gray),0,1,1);
				}
				else
				{
					if((setup_p->father_p!=empty_father_p)&&(i==0))
					//if((setup_page_p->now_p == Power_System_Setting)&&((setup_page_p->now_page_num!=1)||(i<2)))
						Virtual_LCD_Draw_String_ARGB_align_center_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+330,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num2+i].display_str,(0xFFe2e2e4),0,1,1);
					else
						Virtual_LCD_Draw_String_ARGB_24_4bit(setup_item_p[SYSTEM_ITEM_1_OFFSET+i].x_val+X_system_system_offset,setup_item_p[SYSTEM_ITEM_1_OFFSET+i].y_val+15,setup_page_p->now_p[setup_page_p->now_page_num*setup_page_display_num2+i].display_str,(0xFFe2e2e4),0,1,1);
				}
			}
        
            
			switch(setup_p->setup_menu_touch_type)//选项属性
			{
				case TOUCH_TYPE_NORMAL://正常  
                    
                
                setup_item_p[0].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;  //不进行触摸 也不显示
                setup_item_p[1].key_type = KEY_TYPE_ONCE;
                setup_item_p[2].key_type = KEY_TYPE_ONCE;
                setup_item_p[3].key_type = KEY_TYPE_ONCE;

                
               
				break;
				case TOUCH_TYPE_ENTER://正常  点一下进入下一级
               // setup_item_p[0].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;  //不进行触摸 也不显示
               
                setup_item_p[0].key_type = KEY_TYPE_ONCE;  
     
                setup_item_p[1].key_type = KEY_TYPE_ONCE;
                setup_item_p[2].key_type = KEY_TYPE_ONCE;
                setup_item_p[3].key_type = KEY_TYPE_ONCE;
                

				break;
				
                


				case TOUCH_TYPE_UP_DOWN://显示上下选择按键 可以上下选择
                    
                
					setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_NONE;
					setup_item_p[29].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[28].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
					setup_item_p[27].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;

				break;
                

                
				case END_OF_THE_LIST://结束
                    
                                setup_item_p[0].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;  //不进行触摸 也不显示
                setup_item_p[1].key_type = KEY_TYPE_ONCE;
                setup_item_p[2].key_type = KEY_TYPE_ONCE;
                setup_item_p[3].key_type = KEY_TYPE_ONCE;

				break;
				case TOUCH_TYPE_UPGRADE://升级
                    
                                setup_item_p[0].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;  //不进行触摸 也不显示
                setup_item_p[1].key_type = KEY_TYPE_ONCE;
                setup_item_p[2].key_type = KEY_TYPE_ONCE;
                setup_item_p[3].key_type = KEY_TYPE_ONCE;
                

				break;
				case TOUCH_TYPE_BACKGROUND:
                    
                                setup_item_p[0].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;  //不进行触摸 也不显示
                setup_item_p[1].key_type = KEY_TYPE_ONCE;
                setup_item_p[2].key_type = KEY_TYPE_ONCE;
                setup_item_p[3].key_type = KEY_TYPE_ONCE;
                

				break;
				case TOUCH_TYPE_SAVE_AND_BACK://显示标题和返回
                    
                              
                setup_item_p[0].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;  //不进行触摸 也不显示
                setup_item_p[1].key_type = KEY_TYPE_ONCE;
                setup_item_p[2].key_type = KEY_TYPE_ONCE;
                setup_item_p[3].key_type = KEY_TYPE_ONCE;
				break;
				default:
					
				break;
			}



			if(upgrage)
			{
			  if(*setup_p->f!=empty_fun)
					(*setup_p->f)(setup_p,i,TO_INIT);	
				//sysprintf("\r\n======================%d",i);
		  }
			else
			{
			   if(*setup_p->f!=empty_fun)
			    (*setup_p->f)(setup_p,i,TO_DO_NOTHING);	
			}
		}
		else
		{
//            
//			setup_item_p[i+SETUP_OFFSET_LEFT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
//			setup_item_p[i+SETUP_OFFSET_RIGHT].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
//			setup_item_p[i+SETUP_OFFSET_BTN].key_type = KEY_TYPE_TOUCH_NONE;
//			setup_item_p[i+SETUP_OFFSET_ENTER_BTN].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;
			
			//setup_item_p[i+SYSTEM_ITEM_1_OFFSET].key_type = KEY_TYPE_TOUCH_NONE;//item 
			//setup_item_p[i+SYSTEM_LEFT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//left
			//setup_item_p[i+SYSTEM_RIGHT_1_OFFSET].key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//right
			//if(upgrage)
			//	Virtual_LCD_Draw_Rectangle_ARGB32(setup_item_p[1+i].x_val+32,setup_item_p[1+i].y_val+26,690,24,Virtual_LCDbuff2,ARGB_clear);
    }
  }
	if(upgrage_dispaly)
	{
		//f_need_LCD_Upgrate = TRUE;
		Virtual_LCD_Upgrate();	
	}
}


void ui_column_setup_set_info2(bool upgrage)
{
	setup_page_t *setup_page_p2;
	lcd_dis_item_t *setup_item_p2;
	static u8 last_now_item = 4;//页面按键数
	
	setup_page_p2 = &setup_page_sta2;//
	setup_item_p2 = Setup_item;//pic[]
	
	if(last_now_item!=page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item)
	{
        last_now_item = page_home.page_top_side[LEFT_SIDE_PAGE_HOME].now_item; // 更新记录为当前选中项
        setup_page_p2->now_p = setup_setting2; // 设置当前页面使用的配置数据（预设的`setup_setting2字符组`）
        setup_page_p2->now_page_deep = 0;     // 重置页面层级为0（回到顶级设置页）
        setup_page_p2->now_page_num = 0;      // 重置当前页码为0（显示第一页）
        last_show_page_level = 0;            // 记录上一次显示的层级为0
        last_show_page_num[0] = 0;           // 记录层级0的上一次显示页码为0
        last_show_page_num[1] = 0;           // 记录层级1的上一次显示页码为0（预留，用于多级页面）
                
	}
	f_display_set_info = FALSE;
	display_column_setup_page2(FALSE,upgrage,setup_page_p2,setup_item_p2,"");
}





void ui_Setup_init(void)   
{
	lcd_dis_page_t *p;
	u8 i;
	p = &page_home.page_main_item[LEFT_SIDE_PAGE_HOME][5]; //父页面
	p->fat_page = NULL; //父页面父页面为空；
	
	p->pic_back_g = t_background_1.pic_item;//poit to backgroud pic
	p->size_of_pic_back=t_background_1.size_of_pic_item;// backgroud pic size
	p->x_val=0;//for whole area   single item see "lcd_dis_item_t" 
	p->y_val=0;
	p->x_end_val=MAIN_AREA_X_END;
	p->y_end_val=MAIN_AREA_Y_END;
    
	p->item_num=Setup_PAGE_ITEM_NUM;// how many item
    
	p->now_item = 0;// for "page_left_side" and "page_top_side" only 
	p->last_item = 0xFF;//for "page_left_side" and "page_top_side" only
//	p->item = Setup_item;
//	for(i=0;i<Setup_PAGE_ITEM_NUM;i++)
//	{
//		memcpy(&(p->item[i]),p_home_item_5_chun_d4[i],sizeof(lcd_dis_item_t));
//		p->item[i].pic_item =p_home_item_5_chun_u4[i]->pic_item;//
//		p->item[i].size_of_pic_item = p_home_item_5_chun_u4[i]->size_of_pic_item ;
//	}   
       // f_ui_disply_dialog_info_5 = FALSE;
     	p->item = Setup_item;
//    	for(i=0;i<Setup_PAGE_ITEM_NUM;i++)//设置按键状态，影响显示
//	{
//		p_home_item_5_chun_d4[i]->key_type = KEY_TYPE_TOUCH_AND_DISPLAY_NONE;//不进行触摸 也不显示//不进行触摸 也不显示,意义不明
//	}
//    
    	for(i=0;i<Setup_PAGE_ITEM_NUM;i++)
	{
		memcpy(&(p->item[i]),p_home_item_5_chun_d4[i],sizeof(lcd_dis_item_t));
		p->item[i].pic_item =p_home_item_5_chun_u4[i]->pic_item;//
		p->item[i].size_of_pic_item = p_home_item_5_chun_u4[i]->size_of_pic_item ;
	}
    
    
    	p->sub_page_count = 0x00; //定义好子页面数目
	p->sub_page = NULL;//= (lcd_dis_page_t **)malloc(p->sub_page_count * sizeof(lcd_dis_page_t *));  //开辟子页面数组内存
       t_page6_no_select .key_type          =KEY_TYPE_TOUCH_NONE;  //不进行触摸 弹起图标当背景显示 

    t_page6_select.key_type = KEY_TYPE_ONCE;//选项进入
	t_page6_select_2 .key_type = KEY_TYPE_ONCE;
	t_page6_select_3 .key_type = KEY_TYPE_ONCE;
	t_page6_select_4 .key_type = KEY_TYPE_ONCE;

    
    //    //t_page6_select               .key_type          =KEY_TYPE_TOUCH_NONE;
//    //t_page6_temp_icon            .key_type          =KEY_TYPE_TOUCH_NONE;
//   // t_page6_time_icon            .key_type          =KEY_TYPE_TOUCH_NONE;
//   // t_page6_upgrade_icon         .key_type          =KEY_TYPE_TOUCH_NONE;
//   // t_page6_upgrade_icon_2       .key_type          =KEY_TYPE_TOUCH_NONE;
// //   t_page6_Ver_icon             .key_type     =KEY_TYPE_TOUCH_NONE;
//    
    	//ui_column_setup_set_info(FALSE);//首页

  ///  ui_column_setup_set_info2(FALSE);
    
}


    





