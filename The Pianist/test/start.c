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
	textcolor(15, 0);
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
	textcolor(15, 0);
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
	gotoxy(57, 27);
	printf("������\n");
	gotoxy(57, 30);
	printf("����\n");
	gotoxy(57, 33);
	printf("������\n");
	draw_box(50, 23, 68, 25);
}

// ����â���� �޴��� �����Ѵ�
// ��ǥ�� �޴� �Է��� ����ȭ��Ű�� ���� �� �Լ��� ������ �ʴ´�.
// while���� ���Ѵ�� �ݺ��� ��ǥ ���¸� ������ �� ����
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
"@@@@@!!!!!!!!!!###@@",
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


// =============================================== �߰��� �ڵ� ===============================================
// ��ǥ ����ü
typedef struct Note {
	int x, y; // ��ǥ ��ġ
	int num; // ��ǥ ����
	int lifetime; // ��ǥ ���� �ð�
}Note;

#define NOTE_NUM 12 // ��ǥ ����
#define NOTE_BASE_LIFE 600 // ��ǥ �⺻ �����ֱ�
#define NOTE_RAND_LIFE 200 // ��ǥ �߰� �����ֱ�

// ��ǥ
char note1[8][5] = {
"0001",
"0001",
"0001",
"0001",
"0001",
"0111",
"1111",
"0110",
};
char note2[8][10] = {
"000011000",
"000011110",
"000010011",
"000010001",
"000010010",
"011110000",
"111110000",
"011100000",
};
char note3[8][17] = {
"0000011111111111",
"0000010000000001",
"0000010000000001",
"0000010000000001",
"0000010000001111",
"0011110000011111",
"0111110000001110",
"0011100000000000",
};

// �� ������ ��ǥ �׸���
void draw_note1(int x, int y)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 5; j++) {
			if (note1[i][j] == '1') {
				gotoxy(x + j, y + i);
				//textcolor(0, 15);
				printf(" ");
				//textcolor(15, 0);
			}
		}
	}
}
void draw_note2(int x, int y)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 10; j++) {
			if (note2[i][j] == '1') {
				gotoxy(x + j, y + i);
				//textcolor(0, 15);
				printf(" ");
				//textcolor(15, 0);
			}
		}
	}
}
void draw_note3(int x, int y)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 17; j++) {
			if (note3[i][j] == '1') {
				gotoxy(x + j, y + i);
				//textcolor(0, 15);
				printf(" ");
				//textcolor(15, 0);
			}
		}
	}
}

// ��ǥ ���� �׸��� �� �����
void draw_note(int x, int y, int n)
{
	switch (n)
	{
	case 1:
		//draw_note1(x, y);
		gotoxy(x, y);
		printf("��");
		break;
	case 2:
		//draw_note2(x, y);
		gotoxy(x, y);
		printf("��");
		break;
	case 3:
		//draw_note3(x, y);
		gotoxy(x, y);
		printf("��");
		break;
	}
	gotoxy(0, 0);
}
void erase_note(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
	//int i, j;
	//
	//for (i = 0; i < 12; i++) {
	//	for (j = 0; j < 18; j++) {
	//		gotoxy(x + j, y + i);
	//		printf(" ");
	//	}
	//}
	gotoxy(0, 0);
}

// ��ǥ �ʱ�ȭ
void init_notes(Note notes[])
{
	for (int i = 0; i < NOTE_NUM; i++) {
		int x, y;
		x = 2 + rand() % 100;
		y = 1 + rand() % 35;
		
		while (1) {
			// Ÿ��Ʋ �� ��ġ��
			if (x > 4 && x < 96 && y > 0 && y < 30) {
				x = 2 + rand() % 100;
				y = 1 + rand() % 35;
			}
			// �޴��� ��ġ�� �ʰ�
			else if (x > 28 && x < 70 && y > 9 && y < 40) {
				x = 2 + rand() % 100;
				y = 1 + rand() % 35;
			}
			else break;
		}
		notes[i].x = x;
		notes[i].y = y;
		notes[i].num = 1 + rand() % 3;
		notes[i].lifetime = NOTE_BASE_LIFE + rand() % NOTE_RAND_LIFE;
	}
}

// ��ǥ ���� ����
void update_notes(Note notes[])
{
	for (int i = 0; i < NOTE_NUM; i++) {
		if (notes[i].lifetime < 0) {
			textcolor(0, 0);
			erase_note(notes[i].x, notes[i].y);
			textcolor(15, 0);

			int x, y;
			x = 2 + rand() % 100;
			y = 1 + rand() % 35;
			while (1) {
				// Ÿ��Ʋ �� ��ġ��
				if (x > 4 && x < 96 && y > 10 && y < 30) {
					x = 2 + rand() % 100;
					y = 1 + rand() % 35;
				}
				// �޴��� ��ġ�� �ʰ�
				else if (x > 38 && x < 70 && y > 9 && y < 40) {
					x = 2 + rand() % 100;
					y = 1 + rand() % 35;
				}
				else break;
			}
			notes[i].x = x;
			notes[i].y = y;
			notes[i].num = 1 + rand() % 3;
			notes[i].lifetime = NOTE_BASE_LIFE + rand() % NOTE_RAND_LIFE;
		}

		// ���̵� ��, ���̵� �ƿ� ȿ��
		if (notes[i].lifetime == 420) {
			textcolor(8, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 400) {
			textcolor(7, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 380) {
			textcolor(15, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 340) {
			textcolor(7, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 330) {
			textcolor(8, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 320) {
			textcolor(0, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}

		notes[i].lifetime--;
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
	Note notes[NOTE_NUM];
	init_notes(notes);

	draw_title();
	draw_menu();

	while (1)
	{
		update_notes(notes);

		unsigned char ch;
		static int n = 0;
		int tmp = -1;
		if (kbhit() == 1) // Ű���尡 ������ ������
		{
			ch = getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // ���� Ư��Ű
			{ // ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = getch();
				remove_box(50, 23 + n % 4 * 3, 68, 25 + n % 4 * 3);
				if (ch == UP) n += 3; // ��ĭ ����
				else if (ch == DOWN) n += 1; // ��ĭ �Ʒ���
				draw_box(50, 23 + n % 4 * 3, 68, 25 + n % 4 * 3);
			}
			else if (ch == ENTER)
			{
				textcolor(15, 0);
				system("cls");
				tmp = n % 4;  // ����Ű �Է��ϸ� ��ġ�� ����
			}
		}

		switch (tmp)
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
		default:
			break;
		}

		// �ſ� ª�� ���ð��� �־� ��ǥ�� ���� �ӵ��� �������� �ʵ��� ��
		// �ñ��ϸ� �ּ�ó�� �� ����
		Sleep(1);
	}
}