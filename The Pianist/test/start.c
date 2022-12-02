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
	textcolor(15, 0);
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
	textcolor(15, 0);
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
	gotoxy(57, 27);
	printf("연습실\n");
	gotoxy(57, 30);
	printf("도움말\n");
	gotoxy(57, 33);
	printf("나가기\n");
	draw_box(50, 23, 68, 25);
}

// 메인창에서 메뉴를 선택한다
// 음표와 메뉴 입력을 동기화시키기 위해 이 함수는 사용되지 않는다.
// while문이 무한대로 반복해 음표 상태를 갱신할 수 없음
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
"@@@@@!!!!!!!!!!###@@",
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


// =============================================== 추가된 코드 ===============================================
// 음표 구조체
typedef struct Note {
	int x, y; // 음표 위치
	int num; // 음표 종류
	int lifetime; // 음표 지속 시간
}Note;

#define NOTE_NUM 12 // 음표 개수
#define NOTE_BASE_LIFE 600 // 음표 기본 생명주기
#define NOTE_RAND_LIFE 200 // 음표 추가 생명주기

// 음표
char note1[8][5] = {
"0001",
"0001",
"0001",
"0001",
"0001",
"0111",
"1111",
"0110",
};
char note2[8][10] = {
"000011000",
"000011110",
"000010011",
"000010001",
"000010010",
"011110000",
"111110000",
"011100000",
};
char note3[8][17] = {
"0000011111111111",
"0000010000000001",
"0000010000000001",
"0000010000000001",
"0000010000001111",
"0011110000011111",
"0111110000001110",
"0011100000000000",
};

// 각 종류별 음표 그리기
void draw_note1(int x, int y)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 5; j++) {
			if (note1[i][j] == '1') {
				gotoxy(x + j, y + i);
				//textcolor(0, 15);
				printf(" ");
				//textcolor(15, 0);
			}
		}
	}
}
void draw_note2(int x, int y)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 10; j++) {
			if (note2[i][j] == '1') {
				gotoxy(x + j, y + i);
				//textcolor(0, 15);
				printf(" ");
				//textcolor(15, 0);
			}
		}
	}
}
void draw_note3(int x, int y)
{
	int i, j;

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 17; j++) {
			if (note3[i][j] == '1') {
				gotoxy(x + j, y + i);
				//textcolor(0, 15);
				printf(" ");
				//textcolor(15, 0);
			}
		}
	}
}

// 음표 종합 그리기 및 지우기
void draw_note(int x, int y, int n)
{
	switch (n)
	{
	case 1:
		//draw_note1(x, y);
		gotoxy(x, y);
		printf("♩");
		break;
	case 2:
		//draw_note2(x, y);
		gotoxy(x, y);
		printf("♪");
		break;
	case 3:
		//draw_note3(x, y);
		gotoxy(x, y);
		printf("♪");
		break;
	}
	gotoxy(0, 0);
}
void erase_note(int x, int y)
{
	gotoxy(x, y);
	printf("  ");
	//int i, j;
	//
	//for (i = 0; i < 12; i++) {
	//	for (j = 0; j < 18; j++) {
	//		gotoxy(x + j, y + i);
	//		printf(" ");
	//	}
	//}
	gotoxy(0, 0);
}

// 음표 초기화
void init_notes(Note notes[])
{
	for (int i = 0; i < NOTE_NUM; i++) {
		int x, y;
		x = 2 + rand() % 100;
		y = 1 + rand() % 35;
		
		while (1) {
			// 타이틀 안 겹치게
			if (x > 4 && x < 96 && y > 0 && y < 30) {
				x = 2 + rand() % 100;
				y = 1 + rand() % 35;
			}
			// 메뉴와 겹치지 않게
			else if (x > 28 && x < 70 && y > 9 && y < 40) {
				x = 2 + rand() % 100;
				y = 1 + rand() % 35;
			}
			else break;
		}
		notes[i].x = x;
		notes[i].y = y;
		notes[i].num = 1 + rand() % 3;
		notes[i].lifetime = NOTE_BASE_LIFE + rand() % NOTE_RAND_LIFE;
	}
}

// 음표 상태 갱신
void update_notes(Note notes[])
{
	for (int i = 0; i < NOTE_NUM; i++) {
		if (notes[i].lifetime < 0) {
			textcolor(0, 0);
			erase_note(notes[i].x, notes[i].y);
			textcolor(15, 0);

			int x, y;
			x = 2 + rand() % 100;
			y = 1 + rand() % 35;
			while (1) {
				// 타이틀 안 겹치게
				if (x > 4 && x < 96 && y > 10 && y < 30) {
					x = 2 + rand() % 100;
					y = 1 + rand() % 35;
				}
				// 메뉴와 겹치지 않게
				else if (x > 38 && x < 70 && y > 9 && y < 40) {
					x = 2 + rand() % 100;
					y = 1 + rand() % 35;
				}
				else break;
			}
			notes[i].x = x;
			notes[i].y = y;
			notes[i].num = 1 + rand() % 3;
			notes[i].lifetime = NOTE_BASE_LIFE + rand() % NOTE_RAND_LIFE;
		}

		// 페이드 인, 페이드 아웃 효과
		if (notes[i].lifetime == 420) {
			textcolor(8, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 400) {
			textcolor(7, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 380) {
			textcolor(15, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 340) {
			textcolor(7, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 330) {
			textcolor(8, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}
		else if (notes[i].lifetime == 320) {
			textcolor(0, 0);
			draw_note(notes[i].x, notes[i].y, notes[i].num);
		}

		notes[i].lifetime--;
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
	Note notes[NOTE_NUM];
	init_notes(notes);

	draw_title();
	draw_menu();

	while (1)
	{
		update_notes(notes);

		unsigned char ch;
		static int n = 0;
		int tmp = -1;
		if (kbhit() == 1) // 키보드가 눌려져 있으면
		{
			ch = getch();
			if (ch == SPECIAL1 || ch == SPECIAL2) // 만약 특수키
			{ // 예를 들어 UP key의 경우 0xe0 0x48 두개의 문자가 들어온다.
				ch = getch();
				remove_box(50, 23 + n % 4 * 3, 68, 25 + n % 4 * 3);
				if (ch == UP) n += 3; // 한칸 위로
				else if (ch == DOWN) n += 1; // 한칸 아래로
				draw_box(50, 23 + n % 4 * 3, 68, 25 + n % 4 * 3);
			}
			else if (ch == ENTER)
			{
				textcolor(15, 0);
				system("cls");
				tmp = n % 4;  // 엔터키 입력하면 위치를 리턴
			}
		}

		switch (tmp)
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
		default:
			break;
		}

		// 매우 짧은 대기시간을 주어 음표가 갱신 속도가 폭주하지 않도록 함
		// 궁금하면 주석처리 후 실행
		Sleep(1);
	}
}