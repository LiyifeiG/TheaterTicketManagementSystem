// Theater Ticket Management System.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int main()
{
	system("color 0b");               //设置cmd显示颜色
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

