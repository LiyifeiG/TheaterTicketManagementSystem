#include "stdafx.h"
#include "TTMS_SCU_Sale_UI_ShowTicket.h"

void Sale_UI_ShowTicket(USER* user)
{
	system("cls");
	BIOS_GOTO_BOX(22, 100, 5, 25);
	BIOS_GOTO_BOX(22, 100, 8, 7);
	TTMS_GotoXY(52, 6);
	printf_s("�������ѯ���ݳ��ƻ�ID:");
	int ID;
	scanf_s("%d", &ID);
	SCHEDULE* schedule = Schedule_Srv_FetchByID(ID);
	if (!schedule)
	{
		TTMS_GotoXY(50, 24);
		printf_s("�޴��ݳ��ƻ�����Ϣ");
	}
	else
	{
		for (int i = 11; i < 21; i++)
		{
			TTMS_GotoXY(30, i);
			printf_s("*");
			TTMS_GotoXY(92, i);
			printf_s("*");
		}
		for (int i = 30; i < 92; i++)
		{
			TTMS_GotoXY(i, 11);
			printf_s("*");
			TTMS_GotoXY(i, 21);
			printf_s("*");
		}
		TTMS_GotoXY(92, 21);
		printf_s("*");
		TTMS_GotoXY(55, 13);
		printf_s("û������Ժ");
		TTMS_GotoXY(33, 15);
		PLAY* play = Play_Srv_FetchByID(schedule->data.play_id);
		switch (play->data.type)
		{
		case PLAY_TYPE_FLIM: printf_s("��Ӱ");
			break;
		case PLAY_TYPE_OPEAR: printf_s("���");
			break;
		case PLAY_TYPE_CONCERT: printf_s("���ֻ�");
			break;
		default:
			break;
		}
		printf_s("����:%s", play->data.name);
		TTMS_GotoXY(70, 15);
		printf_s("#������");
		switch (play->data.rating)
		{
		case PLAY_RATE_CHILD: printf_s("��ͯ");
			break;
		case PLAY_RATE_TEENAGE: printf_s("����");
			break;
		case PLAY_RATE_ADULT: printf_s("����");
			break;
		default:
			break;
		}
		printf_s("����#");
		TTMS_GotoXY(33, 17);
		printf_s("���ŵ�ַ:");
		STUDIO* studio = Studio_Srv_FetchByID(schedule->data.studio_id);
		printf_s("%s�ݳ���", studio->data.name);
		TTMS_GotoXY(70, 17);
		printf_s("ȫƬʱ��:%d����", play->data.duration);
		TTMS_GotoXY(33, 19);
		printf_s("��ʼʱ�� %d��%d��%d��%dʱ%d��", schedule->time.daytime.year, schedule->time.daytime.month, schedule->time.daytime.day, schedule->time.hour, schedule->time.minute);
		TTMS_GotoXY(73, 19);
		printf_s("Ʊ��:��%d", play->data.price);
	}
	_getch();
	Main_UI_MgtEntry(user);
}
