#include "escape.h"

// �޽��� ���
void print_message1(int n) {
	char str1[50] = "ù ��° �̼��� ���߷� �̷� ã�� �Դϴ�.";
	char str2[50] = "�� �̼��� �ܼ��� ���� ã�� ���� �ƴ϶�";
	char str3[50] = "Ÿ�ֿ̹� �°� ����Ű�� ����";
	char str4[50] = "���� �̼ǹ����� �Ѿ �� �ִ� �����";
	char str5[50] = "���߿� �ʿ��� �������� ���� �մϴ�.";
	char str6[50] = "ħ���ϰ� ���߷� �ִ� ��� ����ϰڽ��ϴ�.";

	textcolor(15, 0);
	switch (n) {
	case 1:
		gotoxy(27, 39);
		printf("%s", str1);
		gotoxy(27, 40);
		printf("%s", str2);
		return;
	case 2:
		gotoxy(32, 39);
		printf("%s", str3);
		gotoxy(27, 40);
		printf("%s", str4);
		return;
	case 3:
		gotoxy(27, 39);
		printf("%s", str5);
		gotoxy(25, 40);
		printf("%s", str6);
		return;
	default:
		return;
	}
}

// �̷�
char maze[ROW_MAX_SIZE1][COL_MAX_SIZE1] = {
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

	for (i = 0; i < ROW_MAX_SIZE1; i++) {
		for (j = 0; j < COL_MAX_SIZE1; j++) {
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

// �̷� �浹 ����
int check_maze_collision(int x, int y, char ch)
{
	// �迭�� ������ ��� ������ �߻����� �ʵ��� ����
	if (x - 22 < 0 || y - 13 < 0 || x > COL_MAX_SIZE1 + 22 - 1 || y > ROW_MAX_SIZE1 + 13 - 1) {
		return 0;
	}

	// Ư�������� ���� �̷� �¿쿡 ���� �浹ó���� ��ǥ ����
	// �̷��� �迭�� (0,0)���� �����ϰ� ������ �̷ΰ� �׷����� ��ǥ�� (22, 13)�̹Ƿ� ������ ��ǥ�� ���
	// �迭�� ���� '1'�� ��� ���̹Ƿ� �̶� 1�� ��ȯ�Ͽ� �浹�� �Ͼ�ٴ� ���� ��ȯ
	switch (ch) {
	case UP: case DOWN:
		if (maze[y - 13][x - 20] == '1')
		{
			return 1;
		}
		if (maze[y - 13][x - 22] == '1')
		{
			return 1;
		}
		break;
	case LEFT:
		x -= 1;

		if (maze[y - 13][x - 22] == '1')
		{
			return 1;
		}
		break;
	case RIGHT:
		x += 2;

		if (maze[y - 13][x - 22] == '1')
		{
			return 1;
		}
		break;
	}

	return 0;
}

int check_map1_key = 0; // ������ ������� Ȯ��
int check_map1_item = 0;
// ������ �浹 ����
int check_item_collision1(int x, int y, char ch)
{
	// ����
	if (x == 63 && y == 29) {
		check_map1_key = 1;
		return 1;
	}

	// ������1
	if (x == 63 && y == 18) {
		check_map1_item = 2;
		return 2;
	}

	return 0;
}

// �� ������ Ȯ��
int map1_check2()
{
	return check_map1_item;
}

// �̷� ������ ����
int check_maze_start_collision(int x, int y, char ch)
{
	if (x >= 22 && x <= 72 && y >= 13  && y <= 68) {
		return 1;
	}

	return 0;
}

// �� �浹 ����
int check_door_collision1(int x, int y, char ch)
{
	if (x == 67 && y == 8) {
		if (map1_check1() == 1) {
			return 1;
		}
	}

	return 0;
}

// ���� Ȯ��
int map1_check1()
{
	return check_map1_key;
}

// ��1 �浹 ����
int check_map1_collision(int x, int y, char ch)
{
	// map�� ������ ��� ������ �߻����� �ʵ��� ����
	if (x <= MAP_X1 + 1 || y <= MAP_Y1 || x >= MAP_X2 - 5 || y >= MAP_Y2) {
		return 1;
	}

	// Ư�������� ���� �̷� �¿쿡 ���� �浹ó���� ��ǥ ����
	switch (ch) {
	case UP: case DOWN:
		if (maze[y - 13][x - 20] == '1')
		{
			return 1;
		}
		if (maze[y - 13][x - 22] == '1')
		{
			return 1;
		}
		break;
	}

	return 0;
}

// ĳ���� �����̱�
int Delay = 200; // 100 msec delay, �� ���� ���̸� �ӵ��� ��������.
void move_star()
{
	unsigned char ch; // Ư��Ű 0xe0 �� �Է¹������� unsigned char �� �����ؾ� ��
	int oldx = 23, oldy = 8, newx = 23, newy = 8;
	int invenX = 74, invenY = 8;
	int keep_moving;

	ch = 0; // �ʱⰪ ��������
	keep_moving = 0;

	while (1) {
		if (kbhit() == 1) {  // Ű���尡 ������ ������
			ch = getch(); // key ���� �д´�
			// ESC ������ ���α׷� ���� �߰�
			if (ch == ESC)
				break;
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

		// �̷� ���������� �̵� ��� �ٲٱ�
		if (check_maze_start_collision(newx, newy, ch) == 1) {
			keep_moving = 1;
		}

		if (keep_moving) { // �����̰� ������
			switch (ch) {
			case UP:
				if (oldy > MAP_Y1 - 1)
					newy = oldy - 1;
				break;
			case DOWN:
				if (oldy < MAP_Y2 - 1)
					newy = oldy + 1;
				break;
			case LEFT:
				if (oldx > MAP_X1 - 1)
					newx = oldx - 2;
				break;
			case RIGHT:
				if (oldx < MAP_X2 - 1)
					newx = oldx + 2;
				break;
			}

			//���� �׸��� ���� ���� �浹�ߴ��� Ȯ���Ͽ� �浹�� ��� ���� �ٸ� ������ �̵�
			if (check_maze_collision(newx, newy, ch)) {
				// �浹�� �̷� ���������� ���ư�
				newx = 27;
				newy = 12;
			}

			// ������ �浹 �� �κ��丮 â�� �߰� �ϱ�
			int item = check_item_collision1(newx, newy, ch);

			// �������� �����ϴ� ��� ( 1 �Ǵ� 2 )
			if (item) {
				gotoxy(invenX, invenY); // �κ� ��ġ�� �̵�
				if (item == 1) {
					textcolor(14, 0);
					printf("����");
				}
				else if (item == 2) {
					textcolor(11, 0);
					printf("Item: ��");
				}
				invenY += 1; // ���� �κ� �������� �̵�
			}

			//int check* = 0;

			// �� �浹 �� ���� ������
			if (check_door_collision1(newx, newy, ch) == 1) {
				if (check_map1_key == 1) { // ���踦 ����ٸ�
					system("cls");
					textcolor(15, 0);
					draw_map2();
					// �κ��丮 �ҷ�����
					return;
				}
				else {
					newx = 27;
					newy = 12;
				}
			}

			remove_star(oldx, oldy); // ������ ��ġ�� STAR�� �����
			draw_star(newx, newy); // ���ο� ��ġ���� STAR�� ǥ���Ѵ�.
			// ������ ��ġ�� ����Ѵ�.
			oldx = newx;
			oldy = newy;
			keep_moving = 0; //1:����̵�, 0:�ѹ��� ��ĭ���̵�
		}
		Sleep(Delay); // Delay�� ���̸� �ӵ��� ��������.
	}
}

// ��1 �׸���
void draw_map1()
{
	draw_map(1);
	draw_door(64, 7);
	draw_maze();
	draw_item(63, 29, 1);
	draw_item(63, 18, 2);
	draw_star(23, 8);
	show_message(1);
	move_star();
}