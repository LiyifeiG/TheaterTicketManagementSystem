#include "stdafx.h"
#include "TTMS_SCU_Account_UI_QUE.h"

void Account_UI_Que(USER * user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	BIOS_GOTO_BOX(22, 100, 23, 22);
	TTMS_GotoXY(52, 6);
	printf_s("û�������Ժ");
	TTMS_GotoXY(43, 9);
	printf_s("%s���ã�������Ҫ���ҵ��û�����", user->USER_NAME);
	TTMS_GotoXY(54, 11);
	char FindName[USER_LEN];
	scanf_s("%s", FindName, USER_LEN);
	if (Account_Perst_CheckAccout(FindName) == 1)
	{
		USER *user = Account_Perst_FetchByName(FindName);
		TTMS_GotoXY(47, 13);
		printf_s("����:%s", user->USER_NAME);
		TTMS_GotoXY(47, 15);
		printf_s("�˺�:%s", user->USER_ACCOUT);
		TTMS_GotoXY(47, 17);
		printf_s("����:");
		if (user->power == 1)
		{
			printf_s("��Ʊ����");
		}
		else if (user->power == 2)
		{
			printf_s("��ƱԱ");
		}
		else if (user->power == 0)
		{
			printf_s("ϵͳ����Ա");
		}
		Account_Srv_Back(user);
	}
	else
	{
		TTMS_GotoXY(43, 20);
		printf_s("û���ҵ���ϵͳ�û�����Enter���Ի�Esc����");
	}
	char key[15];
	strcpy_s(key, 15, GET_KEY());
	if (strcmp(key, "Esc") == 0)
	{
		Account_UI_MgtEntry(user);
	}
	else
	{
		Account_UI_Que(user);
	}
}