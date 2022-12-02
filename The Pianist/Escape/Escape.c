#include <stdio.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <process.h>
#include <mmsystem.h>

// ���� �޴� �ƽ�Ű��Ʈ
char geometry_dash[10][82] = {
		"		  ####                                               #####              ##     ",
		"		 #   #                            #                   #   #              #     ",
		"		#                                 #                   #    #             #     ",
		"		#        ##   ##  # ## ##    ##  ###  ## # ### ###    #    #  ##    ###  ###   ",
		"		#   ### #  # #  #  #  #  #  #  #  #    ##   #   #     #    # #  #  #     #  #  ",
		"		#    #  #### #  #  #  #  #  ####  #    #     # #      #    #  ###   ##   #  #  ",
		"		 #   #  #    #  #  #  #  #  #     #    #     # #      #   #  #  #     #  #  #  ",
		"		  ###    ###  ##  ### ## ##  ###   ## ###     #      #####   ##### ###   ## ## ",
		"		                                              #                                ",
		"		                                            ##                                 " };

// ���� ���ϴ� ��ġ�� Ŀ�� �̵�
void gotoxy(int x, int y)
{
	COORD pos; // Windows.h �� ����
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Ŀ�� �� ���̰�
void removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

// �޴��� Ŀ���� ��Ÿ���� �ڽ��� �׸���
void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("��");
		gotoxy(x, y2);
		printf("��");
	}
	for (y = y1; y <= y2; y++)
	{
		gotoxy(x1, y);
		printf("��");
		gotoxy(x2, y);
		printf("��");
	}
	gotoxy(x1, y1);
	printf("��");
	gotoxy(x2, y1);
	printf("��");
	gotoxy(x1, y2);
	printf("��");
	gotoxy(x2, y2);
	printf("��");
}

// ���� �޴��� �׸���
void draw_main_menu()
{
	int j;
	textcolor(0, 0);
	for (j = 0; j < 10; j++)
	{
		for (int i = 0; i < 82; i++)
		{
			if (geometry_dash[j][i] == '#') {

				gotoxy(i, j);
				printf(" ");
			}
			//printf("%c", geometry_dash[j][i]);
		}
	}
	textcolor(0, 15);
	gotoxy(46, 24);
	printf("����\n");
	gotoxy(46, 27);
	printf("����\n");
	gotoxy(45, 30);
	printf("����\n");
	gotoxy(45, 33);
	printf("������\n");
	draw_box(30, 23, 64, 25);
}

void main()
{
	//printf("����");


	gotoxy(0, 1);
	printf("^");

	gotoxy(2, 0);
	printf("/");

	gotoxy(2, 1);
	printf("\\");

	gotoxy(4, 1);
	printf("��");

	// ���� �޴� ����
	removeCursor();
	/*while (1) {
		draw_main_menu();
	}*/
}