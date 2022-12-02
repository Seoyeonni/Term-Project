#include "escape.h"

// 커서 이동
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
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

// 메시지 지우기
void erase_text(int x1, int y1, int x2, int y2)
{
	int i, j;

	gotoxy(x1, y1);

	for (i = 0; i < y2 - y1; i++) {
		gotoxy(x1, y1 + i);
		for (j = 0; j < x2 - x1; j++) {
			printf(" ");
		}
	}
}

// 메시지 넘기기
void show_message(int k) {
	int n = 1;
	unsigned char ch = 0;

	while (n < 5) {
		if (kbhit() == 1) {
			ch = getch();
			if (ch == SPACEBAR) {
				erase_text(21, 37, 69, 42);
				switch (k) {
				case 0:
					print_message0(n);
					break;
				case 1:
					print_message1(n);
					break;
				case 2:
					print_message2(n);
					break;
				case 3:
					print_message3(n);
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

