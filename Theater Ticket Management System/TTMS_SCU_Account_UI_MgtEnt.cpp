#include "stdafx.h"
#include "TTMS_SCU_Account_UI_MgtEnt.h"

void Account_UI_MgtEntry(USER *user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(53, 6);
	printf_s("欢迎回来,%s", user->USER_NAME);
	TTMS_GotoXY(45, 24);
	printf_s("按UP/DOWN选择,ENTER确认,ESC注销登录");
	BIOS_GOTO_BOX(22, 100, 23, 22);
		TTMS_GotoXY(47, 9);
		printf_s("NO1:添加系统用户");
		TTMS_GotoXY(47, 11);
		printf_s("NO2:删除系统用户");
		TTMS_GotoXY(47, 13);
		printf_s("NO3:修改系统用户密码");
		TTMS_GotoXY(47, 15);
		printf_s("NO4:查询系统用户");
		TTMS_GotoXY(47, 17);
		printf_s("NO5:浏览系统用户");
		TTMS_GotoXY(47,19);
		int flag = GET_OC(44, 9, 44, 17, 2, 1, "->", 0, 1);
		if (flag == 1)
		{
			switch (GET_CURSOR_Y())
			{
			case 9: Account_UI_Add(user); break;
			case 11:Account_UI_DeleteByName(user); break;
			case 13:Account_UI_ModPassword(user); break;
			case 15:Account_UI_Que(user); break;
			case 17:Account_UI_Browe(user); break;
			}
		}
		else if (flag == 0)
		{
			Main_UI_MgtEntry(user);
		}
	
}
