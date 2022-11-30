#include "escape.h"

// 캐릭터 그리기
void draw_star(int x, int y)
{
	textcolor(15, 0);
	gotoxy(x, y);
	printf("★");
	textcolor(0, 0);
}

// 캐릭터 없애기
void remove_star(int x, int y)
{
	gotoxy(x, y);
	textcolor(0, 0);
	printf(BLANK);
	textcolor(15, 0);
}

// 박스 그리기
void draw_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2) {
		gotoxy(x, y1);
		printf("─");
		gotoxy(x, y2);
		printf("─");
	}
	for (y = y1; y <= y2; y++) {
		gotoxy(x1, y);
		printf("│");
		gotoxy(x2, y);
		printf("│");
	}
	gotoxy(x1, y1);
	printf("┌");
	gotoxy(x2, y1);
	printf("┐");
	gotoxy(x1, y2);
	printf("└");
	gotoxy(x2, y2);
	printf("┘");
}

// 맵 그리기
void draw_map(int n)
{
	textcolor(15, 0);
	draw_box(20, 5, 70, 35); // 게임창
	gotoxy(22, 6);
	printf("======================MAP%d======================", n);
	draw_box(20, 36, 70, 43); // 메시지창
	draw_box(72, 5, 91, 35); // 인벤토리
	gotoxy(74, 6);
	printf("====Inventory====");
	draw_box(72, 36, 91, 43); // 조작키 설명
	gotoxy(74, 37);
	printf("이동: 방향키");
	gotoxy(74, 38);
	printf("클릭: G");
	gotoxy(74, 38);
	printf("메시지 넘기기:");
	gotoxy(74, 39);
	printf("  Space bar");
	gotoxy(74, 40);
	printf("아이템 사용:");
	gotoxy(74, 41);
	printf("  숫자키");
	gotoxy(74, 42);
	printf("종료: ESC");
}

// 문 그리기
void draw_door(int x, int y)
{
	gotoxy(x, y);
	printf("┌───┐");
	gotoxy(x, y + 1);
	printf("│   │");
	gotoxy(x, y + 2);
	printf("└───┘");
}

// 아이템 그리기
void draw_item(int x, int y, int n)
{
	gotoxy(x, y);
	switch (n) {
	case 1:
		textcolor(14, 0);
		printf("♂");
		break;
	case 2:
		textcolor(11, 0);
		printf("♩");
		break;
	case 3:
		textcolor(11, 0);
		printf("♬");
		break;
	case 4:
		textcolor(11, 0);
		printf("♪");
		break;
	}
	textcolor(15, 0);
}