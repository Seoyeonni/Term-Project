#include "escape.h"

// �޽��� ���
void print_message2(int n) {
	char str1[50] = "�� ��° �̼��� �γ��׽�Ʈ�Դϴ�.";
	char str2[50] = "���� Ʋ�� ���� ������ Ǭ�ٸ� ��ư�����";
	char str3[50] = "���ο� �ð����� ������ ���ٸ� ����";
	char str4[50] = "�ʼ��� �Ǻ� ������ ���� �� �ֽ��ϴ�.";
	char str5[50] = "�� �Ǻ� ���� ��ġ�� 1�ʸ� �����ݴϴ�.";
	char str6[50] = "�پ ���°� ������ ��� ����ϰڽ��ϴ�.";

	textcolor(15, 0);
	switch (n)
	{
	case 1:
		gotoxy(31, 39);
		printf("%s", str1);
		gotoxy(27, 40);
		printf("%s", str2);
		return;
	case 2:
		gotoxy(29, 39);
		printf("%s", str3);
		gotoxy(29, 40);
		printf("%s", str4);
		return;
	case 3:
		gotoxy(28, 39);
		printf("%s", str5);
		gotoxy(25, 40);
		printf("%s", str6);
		return;
	default:
		return;
	}
}

// map2
char map2[ROW_MAX_SIZE2][COL_MAX_SIZE2] = {
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
};

// ����ã��� �׸���
void draw_site()
{
	int i, j;

	for (i = 0; i < ROW_MAX_SIZE2; i++) {
		for (j = 0; j < COL_MAX_SIZE2; j++) {
			gotoxy(MAP2_START_X + j, MAP2_START_Y + i);
			if (map2[i][j] == '1') {
				textcolor(0, 15);
				printf(" ");
			}
			if (map2[i][j] == '0') {
				textcolor(0, 3);
				printf(" ");
			}
		}
	}

	textcolor(15, 0);
}

// ����ã��� �����
void erase_site()
{
	int i, j;

	for (i = 0; i < ROW_MAX_SIZE2; i++) {
		for (j = 0; j < COL_MAX_SIZE2; j++) {
			gotoxy(MAP2_START_X + j, MAP2_START_Y + i);
			textcolor(0, 0);
			printf(" ");
		}
	}

	textcolor(15, 0);
}

// ĳ���� �þ� �׸���
void draw_player_sight(int x, int y)
{
	int i, j;

	// �迭������ �� ��ġ
	int xPos = x - MAP2_START_X;
	int yPos = y - MAP2_START_Y;

	for (i = 0; i < PLAYER_SIGHT_Y * 2 + 1; i++) {
		for (j = 0; j < PLAYER_SIGHT_X * 2 + 2; j++) {
			gotoxy(x + j - PLAYER_SIGHT_X, y + i - PLAYER_SIGHT_Y);
			int xx = xPos + j - PLAYER_SIGHT_X;
			int yy = yPos + i - PLAYER_SIGHT_Y;

			if (xx < 0 || yy < 0 || xx >= COL_MAX_SIZE2 || yy >= ROW_MAX_SIZE2)
				continue;

			if (map2[yy][xx] == '0') {
				textcolor(0, 0);
				printf(" ");
			}
			else if (map2[yy][xx] == '1') {
				draw_item(xx + MAP2_START_X, yy + MAP2_START_Y, 1);
			}
			else if (map2[yy][xx] == '3') {
				draw_item(xx + MAP2_START_X, yy + MAP2_START_Y, 3);
			}
			else if (map2[yy][xx] == '4') {
				draw_item(xx + MAP2_START_X, yy + MAP2_START_Y, 4);
			}
		}
	}

	textcolor(15, 0);
}

// ĳ���� �þ� �����
void remove_player_sight(int x, int y)
{
	int i, j;
	int xPos = x - MAP2_START_X;
	int yPos = y - MAP2_START_Y;

	for (i = 0; i < PLAYER_SIGHT_Y * 2 + 1; i++) {
		for (j = 0; j < PLAYER_SIGHT_X * 2 + 2; j++) {
			gotoxy(x + j - PLAYER_SIGHT_X, y + i - PLAYER_SIGHT_Y);

			int xx = xPos + j - PLAYER_SIGHT_X;
			int yy = yPos + i - PLAYER_SIGHT_Y;
			if (map2[yy][xx] == '1') {
				textcolor(0, 0);
				printf(" ");
			}
			if (map2[yy][xx] == '0') {
				textcolor(0, 0);
				printf(" ");
			}
		}
	}

	textcolor(15, 0);
}

// ������ ���� ��ġ ����
int key_x = 0, key_y = 0;
int item1_x = 0, item1_y = 0;
int item2_x = 0, item2_y = 0;
int item3_x = 0, item3_y = 0;
int item4_x = 0, item4_y = 0;
int item5_x = 0, item5_y = 0;
int item6_x = 0, item6_y = 0;
int item7_x = 0, item7_y = 0;
int item8_x = 0, item8_y = 0;

// ������ �����ϰ� �׸���
void draw_random_item()
{
	// x ¦��
	// �ߺ� ����

	// x 44 ~ 74
	// y 9 ~ 34
	srand(time(NULL));

	while (1) {
		key_x = rand() % 31 + 22;
		if ((key_x % 2) == 1) {
			break;
		}
	}
	key_y = rand() % 25 + 10;
	while (1) {
		item1_x = rand() % 31 + 22;
		if ((item1_x % 2) == 1) {
			break;
		}
	}
	item1_y = rand() % 25 + 10;
	while (1) {
		item2_x = rand() % 31 + 22;
		if ((item2_x % 2) == 1) {
			break;
		}
	}
	item2_y = rand() % 25 + 10;
	while (1) {
		item3_x = rand() % 31 + 22;
		if ((item3_x % 2) == 1) {
			break;
		}
	}
	item3_y = rand() % 25 + 10;
	while (1) {
		item4_x = rand() % 31 + 22;
		if ((item4_x % 2) == 1) {
			break;
		}
	}
	item4_y = rand() % 25 + 10;
	while (1) {
		item5_x = rand() % 31 + 22;
		if ((item5_x % 2) == 1) {
			break;
		}
	}
	item5_y = rand() % 25 + 10;
	while (1) {
		item6_x = rand() % 31 + 22;
		if ((item6_x % 2) == 1) {
			break;
		}
	}
	item6_y = rand() % 25 + 10;
	while (1) {
		item7_x = rand() % 31 + 22;
		if ((item7_x % 2) == 1) {
			break;
		}
	}
	item7_y = rand() % 25 + 10;
	while (1) {
		item8_x = rand() % 31 + 22;
		if ((item8_x % 2) == 1) {
			break;
		}
	}
	item8_y = rand() % 25 + 10;

	map2[key_y - MAP2_START_Y][key_x - MAP2_START_X] = '1';
	map2[item1_y - MAP2_START_Y][item1_x - MAP2_START_X] = '3';
	map2[item2_y - MAP2_START_Y][item2_x - MAP2_START_X] = '3';
	map2[item3_y - MAP2_START_Y][item3_x - MAP2_START_X] = '3';
	map2[item4_y - MAP2_START_Y][item4_x - MAP2_START_X] = '3';
	map2[item5_y - MAP2_START_Y][item5_x - MAP2_START_X] = '3';
	map2[item6_y - MAP2_START_Y][item6_x - MAP2_START_X] = '4';
	map2[item7_y - MAP2_START_Y][item7_x - MAP2_START_X] = '4';
	map2[item8_y - MAP2_START_Y][item8_x - MAP2_START_X] = '4';

	draw_item(key_x, key_y, 1);
	draw_item(item1_x, item1_y, 3);
	draw_item(item2_x, item2_y, 3);
	draw_item(item3_x, item3_y, 3);
	draw_item(item4_x, item4_y, 3);
	draw_item(item5_x, item5_y, 3);
	draw_item(item6_x, item6_y, 4);
	draw_item(item7_x, item7_y, 4);
	draw_item(item8_x, item8_y, 4);

	// ������ �ߺ�ó��

	textcolor(8, 0);
}

int check_map2_key = 0; // ������ ������� Ȯ��
int check_map2_item1 = 0;
int check_map2_item2 = 0;
int check_map2_item3 = 0;
int check_map2_item4 = 0;
int check_map2_item5 = 0;
int check_map2_item6 = 0;
int check_map2_item7 = 0;
int check_map2_item8 = 0;
// ������ �浹 ����
int check_item_collision2(int x, int y, char ch)
{
	// ����
	if (x == key_x && y == key_y) {
		check_map2_key = 1;
		return 9;
	}

	// ������1
	if (x == item1_x && y == item1_y) {
		check_map2_item1 = 1;
		return 1;
	}

	// ������2
	if (x == item2_x && y == item2_y) {
		check_map2_item2 = 1;
		return 2;
	}

	// ������3
	if (x == item3_x && y == item3_y) {
		check_map2_item3 = 1;
		return 3;
	}

	// ������4
	if (x == item4_x && y == item4_y) {
		check_map2_item4 = 1;
		return 4;
	}

	// ������5
	if (x == item5_x && y == item5_y) {
		check_map2_item5 = 1;
		return 5;
	}

	// ������6
	if (x == item6_x && y == item6_y) {
		check_map2_item6 = 1;
		return 6;
	}

	// ������7
	if (x == item7_x && y == item7_y) {
		check_map2_item7 = 1;
		return 7;
	}

	// ������8
	if (x == item8_x && y == item8_y) {
		check_map2_item8 = 1;
		return 8;
	}

	return 0;
}

// ����
void print_quiz1(int n)
{
	// 1. ��Ʈ: ����, ����: 600
	char quiz1_1[50] = "����ǥ�� �� ����?";
	char quiz1_2[50] = "10 50 60 ? 110 150 160";
	char quiz1_3[50] = "? 510 550 560 ? 610";
	char answer[50];

	textcolor(15, 0);
	switch(n) {
	case 1:
		gotoxy(30, 38);
		printf("%s", quiz1_1);
		gotoxy(30, 39);
		printf("%s", quiz1_2);
		gotoxy(30, 40);
		printf("%s", quiz1_3);
		gotoxy(27, 41); // ��Ʈ ���, ���� �Է� ��� �߰�
		scanf("%s", answer);
		return;
	default:
		return;
	}
}
void print_quiz2()
{
	// 2. ��Ʈ: ������, ����: 0
	char quiz2_1[50] = "����ǥ�� �� ����?";
	char quiz2_2[50] = "+ �� 1, & �� 2, $ �� 3, % �� ?";
	char quiz2_3[50] = "";
}
void print_quiz3()
{
	// 3. ��Ʈ: �ð�, ����: 2
	char quiz3_1[50] = "����ǥ�� �� ����?";
	char quiz3_2[50] = "9 - 6 = 3, 9 + 6 = 3, 8 + 6 = ?";
	char quiz3_3[50] = "";
}
void print_quiz4()
{
	// 4. ��Ʈ: ������, ����: 87
	char quiz4_1[50] = "����ǥ�� �� ����?";
	char quiz4_2[50] = "16 06 68 88 ? 98";
	char quiz4_3[50] = "";
}
void print_quiz5()
{
	// 5. ��Ʈ: �밢��, ����: 545 + 5 = 550
	char quiz5_1[50] = "������ �ϳ��� �׾� �ùٸ� ���� �ϼ��Ͻÿ�";
	char quiz5_2[50] = "(�� ��ȣ�� �ǵ帮�� �ʴ´�)";
	char quiz5_3[50] = "5 + 5 + 5 = 500";
}
void print_quiz6()
{
	// 6. ��Ʈ: �ټ�����, ����: ����������
	char quiz6_1[50] = "5�� 0���� ���ϰ�, 0�� 2���� ���ϰ�,";
	char quiz6_2[50] = "2�� 5���� ���ϴ�. ���ϱ�?";
	char quiz6_3[50] = "";
}
void print_quiz7()
{
	// 7. ��Ʈ: ������, ����: ���� �¾�� �ʾҴ�.
	char quiz7_1[50] = "��Ӵϴ� �Ƶ麸�� 21�� �� ����.";
	char quiz7_2[50] = "6�� �Ŀ� �Ƶ��� ��ӴϺ��� 5�� ���ϰ� �ȴ�.";
	char quiz7_3[50] = "�Ƶ��� ���̴� ����ΰ�?";
}
void print_quiz8()
{
	// 8. ��Ʈ: �����, ����: �Լ�
	char quiz8_1[50] = "�̰��� ����, �뱸������ ���� �� ������";
	char quiz8_2[50] = "���� ���꿡���� ���� �� �ִ�.";
	char quiz8_3[50] = "";
}

// ���� ���
void show_quiz(int k)
{
	int n = 1;
	unsigned char ch = 0;

	while (n < 9) {
		if (kbhit() == 1) {
			ch = getch();
			if (ch == SPACEBAR) {
				erase_text(21, 37, 69, 42);
				switch (k) {
				case 1:
					print_quiz1(n);
					break;
				case 2:
					print_quiz2(n);
					break;
				case 3:
					print_quiz3(n);
					break;
				case 4:
					print_quiz4(n);
					break;
				case 5:
					print_quiz5(n);
					break;
				case 6:
					print_quiz6(n);
					break;
				case 7:
					print_quiz7(n);
					break;
				case 8:
					print_quiz8(n);
					break;
				default:
					break;
				}
				n++;
			}
		}
	}
	erase_text(21, 37, 69, 42);
	return;
}

// �� �浹 ����
// ���� ��ġ ���� �߰�
int check_door_collision2(int x, int y, char ch)
{
	if (x == 67 && y == 8) {
		if (check_map2_key == 1) {
			return 1;
		}
	}

	return 0;
}

// ���� Ȯ��
//int map2_check2()
//{
//	return check_map2_key;
//}

// ��2 �浹 ����
int check_map2_collision(int x, int y, char ch)
{
	if (x < MAP2_START_X || y < MAP2_START_Y || x >= MAP2_START_X + COL_MAX_SIZE2 - 1 || y >= MAP2_START_Y + ROW_MAX_SIZE2)
		return 1;


	switch (ch) {
	case UP: case DOWN:
		if (map2[y - MAP2_START_Y][x - (MAP2_START_X - 2)] == '1')
		{
			return 1;
		}
		if (map2[y - MAP2_START_Y][x - MAP2_START_X] == '1')
		{
			return 1;
		}
		break;
	case LEFT:
		x -= 1;

		if (map2[y - MAP2_START_Y][x - MAP2_START_X] == '1')
		{
			return 1;
		}
		break;
	case RIGHT:
		x += 2;

		if (map2[y - MAP2_START_Y][x - MAP2_START_X] == '1')
		{
			return 1;
		}
		break;
	}
	return 0;
}

// ĳ���� �����̱�
void move_star2()
{
	unsigned char ch; // Ư��Ű 0xe0 �� �Է¹������� unsigned char �� �����ؾ� ��
	int oldx = MAP2_START_X + 5, oldy = MAP2_START_Y + 1, newx = MAP2_START_Y + 5, newy = MAP2_START_Y + 1;
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

		if (keep_moving) { // �����̰� ������
			switch (ch) {
			case UP:
				if (oldy > MAP_Y1)
					newy = oldy - 1;
				break;
			case DOWN:
				if (oldy < MAP_Y2)
					newy = oldy + 1;
				break;
			case LEFT:
				if (oldx > MAP_X1)
					newx = oldx - 2;
				break;
			case RIGHT:
				if (oldx < MAP_X2)
					newx = oldx + 2;
				break;
			}

			// ��� �浹�� ������ �� ���� 2ĭ�� �����Ѵٴ� ���� ���
			// �̶� ���� ù��° ĭ(���� ���� ����)�� �浹�� ó���ϴ� ��ǥ�� ������ �ȴٴ� ���� ����

			// �̷� �ۿ� �ִ� ���
			// map�� ���� �浹�ϴ� ��� ����� �ʵ��� ���� ��ġ�� ���� ��ġ�� ����
			if (check_map2_collision(newx, newy, ch)) {
				newx = oldx;
				newy = oldy;
			}

			// ������ �浹 �� �κ��丮 â�� �߰� �ϱ�
			int item = check_item_collision2(newx, newy, ch);

			// �������� �����ϴ� ��� ( 1 �Ǵ� 2 )
			if (item) {
				gotoxy(invenX, invenY); // �κ� ��ġ�� �̵�
				if (item == 9) {
					textcolor(14, 0);
					printf("����");
				}
				else if (item == 1) {
					textcolor(11, 0);
					printf("FGKFK");
				}
				else if (item == 2) {
					textcolor(11, 0);
					printf("HGKG");
				}
				else if (item == 3) {
					textcolor(11, 0);
					printf("FSHFD");
				}
				else if (item == 4) {
					textcolor(11, 0);
					printf("D");
				}
				else if (item == 5) {
					textcolor(11, 0);
					printf("SDFGAF");
				}
				else if (item == 6) {
					textcolor(11, 0);
					printf("GHJJHGFG");
				}
				else if (item == 7) {
					textcolor(11, 0);
					printf("GHG");
				}
				else if (item == 8) {
					textcolor(11, 0);
					printf("GGFF");
				}
				invenY += 2; // ���� �κ� �������� �̵�
			}

			// �� �浹 �� ���� ������
			if (check_door_collision2(newx, newy, ch) == 1) {
				if (check_map2_key == 1) { // ���踦 ����ٸ�
					system("cls");
					textcolor(15, 0);
					draw_map3();
					// �κ��丮 �ҷ�����
					return;
				}
				/*else {
					newx = 27;
					newy = 12;
				}*/
			}

			remove_player_sight(oldx, oldy);
			remove_star(oldx, oldy); // ������ ��ġ�� STAR�� �����
			draw_player_sight(newx, newy);
			draw_star(newx, newy); // ���ο� ��ġ���� STAR�� ǥ���Ѵ�.
			// ������ ��ġ�� ����Ѵ�.
			oldx = newx;
			oldy = newy;
			keep_moving = 0; //1:����̵�, 0:�ѹ��� ��ĭ���̵�
		}
	}
}

// ��2 �׸���
void draw_map2()
{
	draw_map(2);
	show_message(2);
	// ���� 1�ʵ��� ������ �� �����
	draw_site();
	draw_door(64, 7);
	draw_random_item();
	Sleep(1000);
	erase_site();
	draw_player_sight(MAP2_START_X + 5, MAP2_START_Y + 1);
	draw_star(MAP2_START_X + 5, MAP2_START_Y + 1);
	move_star2();
}