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

// �� �׸���
void draw_map(int n)
{
	textcolor(15, 0);
	draw_box(20, 5, 70, 35); // ����â
	gotoxy(22, 6);
	printf("======================MAP%d======================", n);
	draw_box(20, 36, 70, 43); // �޽���â
	draw_box(72, 5, 91, 35); // �κ��丮
	gotoxy(74, 6);
	printf("====Inventory====");
	draw_box(72, 36, 91, 43); // ����Ű ����
	gotoxy(74, 37);
	printf("�̵�: ����Ű");
	gotoxy(74, 38);
	printf("Ŭ��: G");
	gotoxy(74, 38);
	printf("�޽��� �ѱ��:");
	gotoxy(74, 39);
	printf("  Space bar");
	gotoxy(74, 40);
	printf("������ ���:");
	gotoxy(74, 41);
	printf("  ����Ű");
	gotoxy(74, 42);
	printf("����: ESC");
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