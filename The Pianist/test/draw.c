#include "escape.h"

// ĳ���� �׸���
void draw_star(int x, int y)
{
	textcolor(15, 0);
	gotoxy(x, y);
	printf("��");
	textcolor(0, 0);
}

// ĳ���� ���ֱ�
void remove_star(int x, int y)
{
	gotoxy(x, y);
	textcolor(0, 0);
	printf(BLANK);
	textcolor(15, 0);
}

// �ڽ� �׸���
void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2) {
		gotoxy(x, y1);
		printf("��");
		gotoxy(x, y2);
		printf("��");
	}
	for (y = y1; y <= y2; y++) {
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

// ����Ű ����
void draw_key(int n)
{
	switch (n)
	{
	case 1:
		gotoxy(74, 39);
		printf("�̵�: ����Ű");
		gotoxy(74, 40);
		printf("����: ESC");
		return;
	case 2:
		gotoxy(74, 39);
		printf("�̵�: ����Ű");
		gotoxy(74, 40);
		printf("����: ESC");
		return;
	case 3:
		gotoxy(74, 39);
		printf("1: MAP1�� �̵�");
		gotoxy(74, 40);
		printf("2: MAP2�� �̵�");
		return;
	default:
		return;
	}
}

// �� �׸���
void draw_map(int n)
{
	textcolor(15, 0);
	draw_box(20, 5, 70, 35); // ����â
	gotoxy(22, 6);
	printf("======================MAP%d======================", n);
	draw_box(20, 36, 70, 43); // �޽���â
	textcolor(8, 0);
	gotoxy(37, 39);
	printf("Space bar�� ����");
	gotoxy(35, 40);
	printf("�޽����� Ȯ���ϼ���");
	textcolor(15, 0);
	draw_box(72, 5, 91, 35); // �κ��丮
	gotoxy(74, 6);
	printf("====Inventory====");
	draw_box(72, 36, 91, 43); // ����Ű ����
	draw_key(n);
}

// �� �׸���
void draw_door(int x, int y)
{
	gotoxy(x, y);
	printf("����������");
	gotoxy(x, y + 1);
	printf("��   ��");
	gotoxy(x, y + 2);
	printf("����������");
}

// ������ �׸���
void draw_item(int x, int y, int n)
{
	gotoxy(x, y);
	switch (n) {
	case 1:
		textcolor(14, 0);
		printf("��");
		break;
	case 2:
		textcolor(11, 0);
		printf("��");
		break;
	case 3:
		textcolor(11, 0);
		printf("��");
		break;
	case 4:
		textcolor(11, 0);
		printf("��");
		break;
	}
	textcolor(15, 0);
}

void draw_inventory(int inven[], int iCnt)
{
	if (iCnt == 0) return;
	int i;
	int invenX = 74, invenY = 8;

	for (i = 0; i < iCnt; i++) {
		gotoxy(invenX, invenY);
		switch (inven[i])
		{
		case KEY1:
			textcolor(14, 0);
			printf("1�� ����");
			textcolor(15, 0);
			break;
		case KEY2:
			textcolor(14, 0);
			printf("2�� ����");
			textcolor(15, 0);
			break;
		case B_MINOR:
			textcolor(11, 0);
			printf("Item: ��");
			textcolor(15, 0);
			break;
		case NOTE_1:
			textcolor(11, 0);
			printf("�ļֵ��ļ�");
			textcolor(15, 0);
			break;
		case NOTE_2:
			textcolor(11, 0);
			printf("��ֵ���");
			textcolor(15, 0);
			break;
		case NOTE_3:
			textcolor(11, 0);
			printf("�ķ����ķ�");
			textcolor(15, 0);
			break;
		case NOTE_4:
			textcolor(11, 0);
			printf("��");
			textcolor(15, 0);
			break;
		case NOTE_5:
			textcolor(11, 0);
			printf("�����ļֵ���");
			textcolor(15, 0);
			break;
		case NOTE_6:
			textcolor(13, 0);
			printf("�ֶ�ýö���ļ�");
			textcolor(15, 0);
			break;
		case NOTE_7:
			textcolor(13, 0);
			printf("�ֶ��");
			textcolor(15, 0);
			break;
		case NOTE_8:
			textcolor(13, 0);
			printf("�ּ�����");
			textcolor(15, 0);
			break;
		}
		invenY += 2;
	}
}