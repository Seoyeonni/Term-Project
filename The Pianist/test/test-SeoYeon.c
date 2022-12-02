#include "test.h"

int Delay = 100; // 100 msec delay, 이 값을 줄이면 속도가 빨라진다.

// 커서 이동
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 커서 안 보이게
void removeCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

// 글자 색상
void textcolor(int fg_color, int bg_color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fg_color | bg_color << 4);
}

// 캐릭터 움직이기
void move_star()
{
	unsigned char ch; // 특수키 0xe0 을 입력받으려면 unsigned char 로 선언해야 함
	int oldx = 22, oldy = 7, newx = 22, newy = 7;
	int keep_moving;

	ch = 0; // 초기값 정지상태
	keep_moving = 0;
	while (1) {
		if (kbhit() == 1) {  // 키보드가 눌려져 있으면
			ch = getch(); // key 값을 읽는다
			// ESC 누르면 프로그램 종료 추가
			/*if (ch == ESC)
				break;*/
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
		if (keep_moving) { // 움직이고 있으면
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
			remove_star(oldx, oldy); // 마지막 위치의 STAR를 지우고
			draw_star(newx, newy); // 새로운 위치에서 STAR를 표시한다.
			oldx = newx; // 마지막 위치를 기억한다.
			oldy = newy;
			keep_moving = 1; //1:계속이동, 0:한번에 한칸씩이동
		}
		Sleep(Delay); // Delay를 줄이면 속도가 빨라진다.
	}
}

// 미로
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

// 미로 그리기
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

// 맵1 그리기
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
	system("pause"); // 콘솔창 유지
}