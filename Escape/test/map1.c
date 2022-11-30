#include "escape.h"

// 메시지 출력
void print_message1(int n) {
	char str1[50] = "첫 번째 미션은 순발력 미로 찾기 입니다.";
	char str2[50] = "이 미션은 단순히 길을 찾는 것이 아니라";
	char str3[50] = "타이밍에 맞게 방향키를 눌러";
	char str4[50] = "다음 미션방으로 넘어갈 수 있는 열쇠와";
	char str5[50] = "나중에 필요할 아이템을 얻어야 합니다.";
	char str6[50] = "침착하고 집중력 있는 모습 기대하겠습니다.";

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

// 미로
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

// 미로 그리기
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

// 미로 충돌 감지
int check_maze_collision(int x, int y, char ch)
{
	// 배열의 범위를 벗어나 오류가 발생하지 않도록 조정
	if (x - 22 < 0 || y - 13 < 0 || x > COL_MAX_SIZE1 + 22 - 1 || y > ROW_MAX_SIZE1 + 13 - 1) {
		return 0;
	}

	// 특수문자인 경우로 미로 좌우에 대한 충돌처리시 좌표 조정
	// 미로의 배열은 (0,0)부터 시작하고 실제로 미로가 그려지는 좌표는 (22, 13)이므로 동일한 좌표로 취급
	// 배열의 값이 '1'인 경우 벽이므로 이때 1을 반환하여 충돌이 일어났다는 것을 반환
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

int check_map1_key = 0; // 아이템 얻었는지 확인
int check_map1_item = 0;
// 아이템 충돌 감지
int check_item_collision1(int x, int y, char ch)
{
	// 열쇠
	if (x == 63 && y == 29) {
		check_map1_key = 1;
		return 1;
	}

	// 아이템1
	if (x == 63 && y == 18) {
		check_map1_item = 2;
		return 2;
	}

	return 0;
}

// ♭ 아이템 확인
int map1_check2()
{
	return check_map1_item;
}

// 미로 시작점 감지
int check_maze_start_collision(int x, int y, char ch)
{
	if (x >= 22 && x <= 72 && y >= 13  && y <= 68) {
		return 1;
	}

	return 0;
}

// 문 충돌 감지
int check_door_collision1(int x, int y, char ch)
{
	if (x == 67 && y == 8) {
		if (map1_check1() == 1) {
			return 1;
		}
	}

	return 0;
}

// 열쇠 확인
int map1_check1()
{
	return check_map1_key;
}

// 맵1 충돌 감지
int check_map1_collision(int x, int y, char ch)
{
	// map의 범위를 벗어나 오류가 발생하지 않도록 조정
	if (x <= MAP_X1 + 1 || y <= MAP_Y1 || x >= MAP_X2 - 5 || y >= MAP_Y2) {
		return 1;
	}

	// 특수문자인 경우로 미로 좌우에 대한 충돌처리시 좌표 조정
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

// 캐릭터 움직이기
int Delay = 200; // 100 msec delay, 이 값을 줄이면 속도가 빨라진다.
void move_star()
{
	unsigned char ch; // 특수키 0xe0 을 입력받으려면 unsigned char 로 선언해야 함
	int oldx = 23, oldy = 8, newx = 23, newy = 8;
	int invenX = 74, invenY = 8;
	int keep_moving;

	ch = 0; // 초기값 정지상태
	keep_moving = 0;

	while (1) {
		if (kbhit() == 1) {  // 키보드가 눌려져 있으면
			ch = getch(); // key 값을 읽는다
			// ESC 누르면 프로그램 종료 추가
			if (ch == ESC)
				break;
			if (ch == SPECIAL1 || ch == SPECIAL2) { // 만약 특수키
				// 예를 들어 UP key의 경우 0xe0 0x48 두개의 문자가 들어온다.
				ch = getch();
				switch (ch) {
				case UP:
				case DOWN:
				case LEFT:
				case RIGHT:
					keep_moving = 1;
					break;
				default: // 방향키가 아니면 멈춘다
					keep_moving = 0;
				}
			}
		}

		// 미로 시작점에서 이동 방법 바꾸기
		if (check_maze_start_collision(newx, newy, ch) == 1) {
			keep_moving = 1;
		}

		if (keep_moving) { // 움직이고 있으면
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

			//별을 그리기 전에 벽과 충돌했는지 확인하여 충돌한 경우 별을 다른 곳으로 이동
			if (check_maze_collision(newx, newy, ch)) {
				// 충돌시 미로 시작점으로 돌아감
				newx = 27;
				newy = 12;
			}

			// 아이템 충돌 시 인벤토리 창에 뜨게 하기
			int item = check_item_collision1(newx, newy, ch);

			// 아이템이 존재하는 경우 ( 1 또는 2 )
			if (item) {
				gotoxy(invenX, invenY); // 인벤 위치로 이동
				if (item == 1) {
					textcolor(14, 0);
					printf("열쇠");
				}
				else if (item == 2) {
					textcolor(11, 0);
					printf("Item: ♭");
				}
				invenY += 1; // 다음 인벤 공간으로 이동
			}

			//int check* = 0;

			// 문 충돌 시 다음 맵으로
			if (check_door_collision1(newx, newy, ch) == 1) {
				if (check_map1_key == 1) { // 열쇠를 얻었다면
					system("cls");
					textcolor(15, 0);
					draw_map2();
					// 인벤토리 불러오기
					return;
				}
				else {
					newx = 27;
					newy = 12;
				}
			}

			remove_star(oldx, oldy); // 마지막 위치의 STAR를 지우고
			draw_star(newx, newy); // 새로운 위치에서 STAR를 표시한다.
			// 마지막 위치를 기억한다.
			oldx = newx;
			oldy = newy;
			keep_moving = 0; //1:계속이동, 0:한번에 한칸씩이동
		}
		Sleep(Delay); // Delay를 줄이면 속도가 빨라진다.
	}
}

// 맵1 그리기
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