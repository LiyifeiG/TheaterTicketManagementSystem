// Theater Ticket Management System.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	system("color 0b");               //����cmd��ʾ��ɫ
 	if (Account_Perst_CheckAccFile() == 1)
	{
		SysLogin();
	}
	else
	{
		Account_UI_InitSys();
	}
    return 0;
}

