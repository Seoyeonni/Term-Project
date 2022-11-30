#include "escape.h"

// ����
char title[8][71] = {
"       ###                     ##                   ##           ##    ",
"######  ##            #####                                      ##    ",
"# ## #  ####   ###     ## ##  ###    ###   ## ##   ###    ####  #####  ",
"  ##    ## ## ## ##    ## ##   ##   ## ##   ## ##   ##   ###     ##    ",
"  ##    ## ## #####    ####    ##    ####   ## ##   ##    ####   ##    ",
"  ##    ## ## ##       ##      ##   ## ##   ## ##   ##      ###  ## ## ",
" ####   ## ##  ####   ####   ###### ######  ## ## ###### #####    ###  ",
};

// ���� �׸���
void draw_title()
{
    int i, j;

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 71; j++) {
            gotoxy(24 + j, 10 + i);
            if (title[i][j] == '#') {
                textcolor(0, 15);
                printf(" ");
            }
            if (title[i][j] == ' ') {
                textcolor(0, 0);
                printf(" ");
            }
        }
    }

    textcolor(15, 0);
}

// �޴��� Ŀ���� ��Ÿ���� �ڽ��� �׸���
void draw_menu_box(int x1, int y1, int x2, int y2)
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

// �޴��� Ŀ���� ��Ÿ���� �ڽ��� �����
void remove_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("  "); // �������� ������
		gotoxy(x, y2);
		printf("  ");
	}
	for (y = y1; y <= y2; y++)
	{
		gotoxy(x1, y);
		printf("  ");
		gotoxy(x2, y);
		printf("  ");
	}
}

// ���� �޴��� �׸���
void draw_menu()
{
	gotoxy(58, 24);
	printf("����\n");
	gotoxy(58, 27);
	printf("����\n");
	gotoxy(57, 30);
	printf("����\n");
	gotoxy(57, 33);
	printf("������\n");
	draw_box(50, 23, 68, 25);
}

// ����â���� �޴��� �����Ѵ�
int select_main_menu()
{
	int n = 0;
	unsigned char ch = 0;
	while (1)
	{
		if (_kbhit() == 1) // Ű���尡 ������ ������
		{
			ch = _getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // ���� Ư��Ű
			{ // ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = _getch();
				remove_box(50, 23 + n % 4 * 3, 68, 25 + n % 4 * 3);
				if (ch == UP) n += 3; // ��ĭ ����
				else if (ch == DOWN) n += 1; // ��ĭ �Ʒ���
				draw_box(50, 23 + n % 4 * 3, 68, 25 + n % 4 * 3);
			}
			else if (ch == ENTER)
			{
				textcolor(15, 0);
				system("cls");
				return n % 4;  // ����Ű �Է��ϸ� ��ġ�� ����
			}
		}
	}
}

// ���α�
char sangsang[26][20] = {
"@@@@@@@!!!!!@@@@@@@@",
"@@@@@!!!!!!!!!@@@@@@",
"@@@@!!!!   !!!!@@@@@",
"@@@!!!       !!!@@@@",
"@@!!!         !!!@@@",
"@@!!           !!@@@",
"@@!!  !   !    !!@@@",
"@!!            !!!@@",
"@!!    !!!     !!!@@",
"@!!            !!!@@",
"@@!!           !!@@@",
"@@!!!         !!!@@@",
"@@@!!!!    !!!!!@@@@",
"@@@@!!!!!!!!!!!###@@",
"@@@@@#  ! !   #####@",
"@@@@@#!  !  !!#####@",
"@@@@!#! !!! !!#!###@",
"@@@!!#!!!!!!!!#!###@",
"@@@!!#!!!!!!!!#!###@",
"@@@!!#!!!!!!!!#!###@",
"@@@  !!!!!!!!!  ###@",
"@@@@@          ###@@",
"@@@@@          @@@@@",
"@@@@@    @@    @@@@@",
"@@@@@    @@    @@@@@",
"@@@@     @     @@@@@",
};

// ���α� �׸���
void draw_sangsang()
{
	int i, j;

	for (i = 0; i < 26; i++) {
		for (j = 0; j < 20; j++) {
			gotoxy(35 + j, 9 + i);
			if (sangsang[i][j] == '@') {
				textcolor(0, 0);
				printf(" ");
			}
			if (sangsang[i][j] == ' ') {
				textcolor(0, 15);
				printf(" ");
			}
			if (sangsang[i][j] == '!') {
				textcolor(0, 1);
				printf(" ");
			}
			if (sangsang[i][j] == '#') {
				textcolor(0, 2);
				printf(" ");
			}
		}
	}

	textcolor(15, 0);
}

// �޽��� ���
void print_message0(int n)
{
    char str1[50] = "�Ѽ����Ǵ��б� �ǾƳ�� �Ǳ� ������";
    char str2[50] = "���� �� �л� ������ ��� ȯ���մϴ�.";
    char str3[50] = "�������� ���ݺ��� ���� �̼ǵ��� ����";
    char str4[50] = "�ʼ��� �Ǻ��� �ϼ��Ͽ� �����ؾ߸�";
    char str5[50] = "������ ���ָ� �� �� �ֽ��ϴ�.";
    char str6[50] = "�׷� ���ݺ��� ������ �����ϰڽ��ϴ�.";

    textcolor(15, 0);
    switch (n)
    {
    case 1:
        gotoxy(28, 39);
        printf("%s", str1);
        gotoxy(28, 40);
        printf("%s", str2);
        return;
    case 2:
        gotoxy(28, 39);
        printf("%s", str3);
        gotoxy(29, 40);
        printf("%s", str4);
        return;
    case 3:
        gotoxy(32, 39);
        printf("%s", str5);
        gotoxy(28, 40);
        printf("%s", str6);
        return;
    default:
        return;
    }
}

void draw_map0()
{
	draw_map(0);
	draw_sangsang();
	show_message(0);
	system("cls");
	draw_map1();
}

void draw_start()
{
	draw_title();
	while (1)
	{
		draw_menu();
		switch (select_main_menu())
		{
		case 0:
			system("cls");
			draw_map0();
			break;
		case 1:
			//����
			break;
		case 2:
			//����
			break;
		case 3:
			system("cls");
			exit(1);
		}
	}
}