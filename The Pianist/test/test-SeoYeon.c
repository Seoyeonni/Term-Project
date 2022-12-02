#include "test.h"

int Delay = 100; // 100 msec delay, �� ���� ���̸� �ӵ��� ��������.

// Ŀ�� �̵�
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
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

// ���� ����
void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

// ĳ���� �����̱�
void move_star()
{
	unsigned char ch; // Ư��Ű 0xe0 �� �Է¹������� unsigned char �� �����ؾ� ��
	int oldx = 22, oldy = 7, newx = 22, newy = 7;
	int keep_moving;

	ch = 0; // �ʱⰪ ��������
	keep_moving = 0;
	while (1) {
		if (kbhit() == 1) {  // Ű���尡 ������ ������
			ch = getch(); // key ���� �д´�
			// ESC ������ ���α׷� ���� �߰�
			/*if (ch == ESC)
				break;*/
			if (ch == SPECIAL1 || ch == SPECIAL2) { // ���� Ư��Ű
				// ���� ��� UP key�� ��� 0xe0 0x48 �ΰ��� ���ڰ� ���´�.
				ch = getch();
				switch (ch) {
				case UP:
				case DOWN:
				case LEFT:
				case RIGHT:
					keep_moving = 1;
					break;
				default: // ����Ű�� �ƴϸ� �����
					keep_moving = 0;
				}
			}
		}
		if (keep_moving) { // �����̰� ������
			switch (ch) {
			case UP:
				if (oldy > Y1 - 1)
					newy = oldy - 1;
				/*else {
					newy = oldy + 1;
					ch = DOWN;
				}*/
				break;
			case DOWN:
				if (oldy < Y2 - 1)
					newy = oldy + 1;
				/*else {
					newy = oldy - 1;
					ch = UP;
				}*/
				break;
			case LEFT:
				if (oldx > X1 - 1)
					newx = oldx - 1;
				/*else {
					newx = oldx + 1;
					ch = RIGHT;
				}*/
				break;
			case RIGHT:
				if (oldx < X2 - 1)
					newx = oldx + 1;
				/*else {
					newx = oldx - 1;
					ch = LEFT;
				}*/
				break;
			}
			remove_star(oldx, oldy); // ������ ��ġ�� STAR�� �����
			draw_star(newx, newy); // ���ο� ��ġ���� STAR�� ǥ���Ѵ�.
			oldx = newx; // ������ ��ġ�� ����Ѵ�.
			oldy = newy;
			keep_moving = 1; //1:����̵�, 0:�ѹ��� ��ĭ���̵�
		}
		Sleep(Delay); // Delay�� ���̸� �ӵ��� ��������.
	}
}

// �̷�
char maze[ROW_MAX_SIZE][COL_MAX_SIZE] = {
	"111100001111111111111111111111111111111111111111",
	"111100001111111111111111111111111111111111111111",
	"111100000000111100000000000011110000000000001111",
	"111100000000111100000000000011110000000000001111",
	"111111110000111100001111000000000000111100001111",
	"111111110000111100001111000000000000111100001111",
	"111100000000111100001111111111111111111111111111",
	"111100000000111100001111111111111111111111111111",
	"111100001111111100001111000000000000000000001111",
	"111100001111111100001111000000000000000000001111",
	"111100001111000000001111000011111111111100001111",
	"111100001111000000001111000011111111111100001111",
	"111100000000000011111111000011110000000000001111",
	"111100000000000011111111000011110000000000001111",
	"111100001111111111110000000011110000111111111111",
	"111100001111111111110000000011110000111111111111",
	"111100001111000011110000111111110000111100001111",
	"111100001111000011110000111111110000111100001111",
	"111100000000000000000000111111110000000000001111",
	"111100000000000000000000111111110000000000001111",
	"111111111111111111111111111111111111111111111111",
	"111111111111111111111111111111111111111111111111",
};

// �̷� �׸���
void draw_maze()
{
	int i, j;

	for (i = 0; i < ROW_MAX_SIZE; i++) {
		for (j = 0; j < COL_MAX_SIZE; j++) {
			gotoxy(22 + j, 13 + i);
			if (maze[i][j] == '1') {
				textcolor(0, 15);
				printf(" ");
			}
			if (maze[i][j] == '0') {
				textcolor(0, 0);
				printf(" ");
			}
		}
	}

	textcolor(15, 0);
}

// ��1 �׸���
void draw_map1()
{
	draw_map(1);
	draw_door(64, 7);
	draw_maze();
	draw_item(63, 29, 1);
	draw_item(63, 18, 2);
	draw_star(22, 7);
	move_star();
}


void main()
{
	draw_map1();
	gotoxy(80, 45);
	textcolor(0, 0);
	system("pause"); // �ܼ�â ����
}