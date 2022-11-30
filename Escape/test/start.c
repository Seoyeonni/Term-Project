#include "escape.h"

// 제목
char title[8][71] = {
"       ###                     ##                   ##           ##    ",
"######  ##            #####                                      ##    ",
"# ## #  ####   ###     ## ##  ###    ###   ## ##   ###    ####  #####  ",
"  ##    ## ## ## ##    ## ##   ##   ## ##   ## ##   ##   ###     ##    ",
"  ##    ## ## #####    ####    ##    ####   ## ##   ##    ####   ##    ",
"  ##    ## ## ##       ##      ##   ## ##   ## ##   ##      ###  ## ## ",
" ####   ## ##  ####   ####   ###### ######  ## ## ###### #####    ###  ",
};

// 제목 그리기
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

// 메뉴의 커서를 나타내는 박스를 그린다
void draw_menu_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("─");
		gotoxy(x, y2);
		printf("─");
	}
	for (y = y1; y <= y2; y++)
	{
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

// 메뉴의 커서를 나타내는 박스를 지운다
void remove_box(int x1, int y1, int x2, int y2)
{
	int x, y;
	for (x = x1; x <= x2; x += 2)
	{
		gotoxy(x, y1);
		printf("  "); // 공백으로 덮어씌우기
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

// 메인 메뉴를 그린다
void draw_menu()
{
	gotoxy(58, 24);
	printf("시작\n");
	gotoxy(58, 27);
	printf("설정\n");
	gotoxy(57, 30);
	printf("도움말\n");
	gotoxy(57, 33);
	printf("나가기\n");
	draw_box(50, 23, 68, 25);
}

// 메인창에서 메뉴를 선택한다
int select_main_menu()
{
	int n = 0;
	unsigned char ch = 0;
	while (1)
	{
		if (_kbhit() == 1) // 키보드가 눌려져 있으면
		{
			ch = _getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // 만약 특수키
			{ // 예를 들어 UP key의 경우 0xe0 0x48 두개의 문자가 들어온다.
				ch = _getch();
				remove_box(50, 23 + n % 4 * 3, 68, 25 + n % 4 * 3);
				if (ch == UP) n += 3; // 한칸 위로
				else if (ch == DOWN) n += 1; // 한칸 아래로
				draw_box(50, 23 + n % 4 * 3, 68, 25 + n % 4 * 3);
			}
			else if (ch == ENTER)
			{
				textcolor(15, 0);
				system("cls");
				return n % 4;  // 엔터키 입력하면 위치를 리턴
			}
		}
	}
}

// 상상부기
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
"@@@@@          ###@@",
"@@@@@          @@@@@",
"@@@@@    @@    @@@@@",
"@@@@@    @@    @@@@@",
"@@@@     @     @@@@@",
};

// 상상부기 그리기
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

// 메시지 출력
void print_message0(int n)
{
    char str1[50] = "한성음악대학교 피아노과 실기 시험을";
    char str2[50] = "보러 온 학생 여러분 모두 환영합니다.";
    char str3[50] = "여러분은 지금부터 여러 미션들을 통해";
    char str4[50] = "필수곡 악보를 완성하여 연주해야만";
    char str5[50] = "자유곡 연주를 할 수 있습니다.";
    char str6[50] = "그럼 지금부터 시험을 시작하겠습니다.";

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
	draw_title();
	while (1)
	{
		draw_menu();
		switch (select_main_menu())
		{
		case 0:
			system("cls");
			draw_map0();
			break;
		case 1:
			//설정
			break;
		case 2:
			//도움말
			break;
		case 3:
			system("cls");
			exit(1);
		}
	}
}