#include "includes.h"
//read me:copy the new item to 'ui_func.c'





void func_keyboard_0_d(void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('0');
	}
}



void func_keyboard_0_u(void* p,u8 sn)
{

}



void func_keyboard_1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('1');
	}
}



void func_keyboard_1_u(void* p,u8 sn)
{

}



void func_keyboard_2_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('2');
  }
}



void func_keyboard_2_u(void* p,u8 sn)
{

}



void func_keyboard_3_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('3');
	}
}



void func_keyboard_3_u(void* p,u8 sn)
{

}



void func_keyboard_4_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('4');
	}
}



void func_keyboard_4_u(void* p,u8 sn)
{

}



void func_keyboard_5_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('5');
	}
}



void func_keyboard_5_u(void* p,u8 sn)
{

}



void func_keyboard_6_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('6');
	}
}



void func_keyboard_6_u(void* p,u8 sn)
{

}



void func_keyboard_7_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('7');
	}
}



void func_keyboard_7_u(void* p,u8 sn)
{

}



void func_keyboard_8_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('8');
	}
}



void func_keyboard_8_u(void* p,u8 sn)
{

}



void func_keyboard_9_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('9');
	}
}



void func_keyboard_9_u(void* p,u8 sn)
{

}

void func_keyboard_symbol1_d (void* p,u8 sn)
{
	u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('-');
	}

}
void func_keyboard_symbol1_u (void* p,u8 sn)
{

}

void func_keyboard_symbol2_d (void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('.');
	}
}

void func_keyboard_symbol2_u (void* p,u8 sn)
{

}






void func_keyboard_a1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('A');
	}
}



void func_keyboard_a1_u(void* p,u8 sn)
{

}



void func_keyboard_a_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('a');
	}
}



void func_keyboard_a_u(void* p,u8 sn)
{

}



void func_keyboard_b1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('B');
	}
}



void func_keyboard_b1_u(void* p,u8 sn)
{

}



void func_keyboard_bg(void* p,u8 sn)
{

}



void func_keyboard_b_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('b');
	}
}



void func_keyboard_b_u(void* p,u8 sn)
{

}



void func_keyboard_c1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('C');
	}
}



void func_keyboard_c1_u(void* p,u8 sn)
{

}



void func_keyboard_c_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('c');
	}
}



void func_keyboard_c_u(void* p,u8 sn)
{

}



void func_keyboard_d1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('D');
	}
}



void func_keyboard_d1_u(void* p,u8 sn)
{

}



void func_keyboard_delete_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input(0x8);
	}
}



void func_keyboard_delete_u(void* p,u8 sn)
{

}



void func_keyboard_d_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('d');
	}
}



void func_keyboard_d_u(void* p,u8 sn)
{

}



void func_keyboard_e1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('E');
	}
}



void func_keyboard_e1_u(void* p,u8 sn)
{

}



void func_keyboard_enter_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input(0x0D);
	}
}



void func_keyboard_enter_u(void* p,u8 sn)
{

}



void func_keyboard_e_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('e');
	}
}



void func_keyboard_e_u(void* p,u8 sn)
{

}



void func_keyboard_f1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('F');
	}
}



void func_keyboard_f1_u(void* p,u8 sn)
{

}



void func_keyboard_f_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('f');
	}
}



void func_keyboard_f_u(void* p,u8 sn)
{

}



void func_keyboard_g1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('G');
	}
}



void func_keyboard_g1_u(void* p,u8 sn)
{

}



void func_keyboard_g_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('g');
	}
}



void func_keyboard_g_u(void* p,u8 sn)
{

}



void func_keyboard_h1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('H');
	}
}



void func_keyboard_h1_u(void* p,u8 sn)
{

}



void func_keyboard_h_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('h');
	}
}



void func_keyboard_h_u(void* p,u8 sn)
{

}



void func_keyboard_i1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('I');
	}
}



void func_keyboard_i1_u(void* p,u8 sn)
{

}



void func_keyboard_i_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('i');
	}
}



void func_keyboard_i_u(void* p,u8 sn)
{

}



void func_keyboard_j1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('J');
	}
}



void func_keyboard_j1_u(void* p,u8 sn)
{

}



void func_keyboard_j_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('j');
	}
}



void func_keyboard_j_u(void* p,u8 sn)
{

}



void func_keyboard_k1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('K');
	}
}



void func_keyboard_k1_u(void* p,u8 sn)
{

}



void func_keyboard_k_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('k');
	}
}



void func_keyboard_k_u(void* p,u8 sn)
{

}



void func_keyboard_l1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('L');
	}
}



void func_keyboard_l1_u(void* p,u8 sn)
{

}



void func_keyboard_lock_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input(0xF);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
		keyboard_input(0xE);
	}
}



void func_keyboard_lock_u(void* p,u8 sn)
{

}



void func_keyboard_l_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('l');
	}
}



void func_keyboard_l_u(void* p,u8 sn)
{

}



void func_keyboard_m1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('M');
	}
}



void func_keyboard_m1_u(void* p,u8 sn)
{

}



void func_keyboard_m_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('m');
	}
}



void func_keyboard_m_u(void* p,u8 sn)
{

}



void func_keyboard_n1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('N');
	}
}



void func_keyboard_n1_u(void* p,u8 sn)
{

}



void func_keyboard_num_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input(0xFF);
	}
	else if(p1->item[SN].now_status==STATUS_IDLE)
	{     
		keyboard_input(0xFE);
	}
}



void func_keyboard_num_u(void* p,u8 sn)
{

}



void func_keyboard_n_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('n');
	}
}



void func_keyboard_n_u(void* p,u8 sn)
{

}



void func_keyboard_o1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('O');
	}
}



void func_keyboard_o1_u(void* p,u8 sn)
{

}



void func_keyboard_o_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('o');
	}
}



void func_keyboard_o_u(void* p,u8 sn)
{

}



void func_keyboard_p1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('P');
	}
}



void func_keyboard_p1_u(void* p,u8 sn)
{

}



void func_keyboard_p_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('p');
	}
}



void func_keyboard_p_u(void* p,u8 sn)
{

}



void func_keyboard_q1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('Q');
	}
}



void func_keyboard_q1_u(void* p,u8 sn)
{

}



void func_keyboard_q_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('q');
	}
}



void func_keyboard_q_u(void* p,u8 sn)
{

}



void func_keyboard_r1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('R');
	}
}



void func_keyboard_r1_u(void* p,u8 sn)
{

}



void func_keyboard_r_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('r');
	}
}



void func_keyboard_r_u(void* p,u8 sn)
{

}



void func_keyboard_s1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('S');
	}
}



void func_keyboard_s1_u(void* p,u8 sn)
{

}



void func_keyboard_space_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input(' ');
	}
}



void func_keyboard_space_u(void* p,u8 sn)
{

}



void func_keyboard_s_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('s');
	}
}



void func_keyboard_s_u(void* p,u8 sn)
{

}



void func_keyboard_t1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('T');
	}
}



void func_keyboard_t1_u(void* p,u8 sn)
{

}



void func_keyboard_t_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('t');
	}
}



void func_keyboard_t_u(void* p,u8 sn)
{

}



void func_keyboard_u1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('U');
	}
}



void func_keyboard_u1_u(void* p,u8 sn)
{

}



void func_keyboard_u_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('u');
	}
}



void func_keyboard_u_u(void* p,u8 sn)
{

}



void func_keyboard_v1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('V');
	}
}



void func_keyboard_v1_u(void* p,u8 sn)
{

}



void func_keyboard_v_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('v');
	}
}



void func_keyboard_v_u(void* p,u8 sn)
{

}



void func_keyboard_w1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('W');
	}
}



void func_keyboard_w1_u(void* p,u8 sn)
{

}



void func_keyboard_w_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('w');
	}
}



void func_keyboard_w_u(void* p,u8 sn)
{

}



void func_keyboard_x1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('X');
	}
}



void func_keyboard_x1_u(void* p,u8 sn)
{

}



void func_keyboard_x_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('x');
	}
}



void func_keyboard_x_u(void* p,u8 sn)
{

}



void func_keyboard_y1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('Y');
	}
}



void func_keyboard_y1_u(void* p,u8 sn)
{

}



void func_keyboard_y_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('y');
	}
}



void func_keyboard_y_u(void* p,u8 sn)
{

}



void func_keyboard_z1_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('Z');
	}
}



void func_keyboard_z1_u(void* p,u8 sn)
{

}



void func_keyboard_z_d(void* p,u8 sn)
{
  u8 SN = sn;//图标在当前页面列表的序号
  lcd_dis_page_t* p1 = (lcd_dis_page_t*)p;
	if(p1->item[SN].now_status==STATUS_SELECT)
	{     
		keyboard_input('z');
	}
}



void func_keyboard_z_u(void* p,u8 sn)
{

}



