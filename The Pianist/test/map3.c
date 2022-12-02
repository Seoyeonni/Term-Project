#include "escape.h"

#define NOTES_X 23
#define NOTES_Y 19

// 게임 종료 조건 1인 경우 클리어
int CLEAR = 0;

// 필수곡 악보
char song[4][16] = {
    "fghfkhgkgfshfdd",
    "sdfgafghjjhgfg",
    "fghfkhgkgfshfdd",
    "sdfgafghgggff"
};

// 메시지 출력
void print_message3(int n) {
    char str1[50] = "세 번째 미션은 필수곡 연주입니다.";
    char str2[50] = "앞에 미션들을 통하여 얻은 힌트로";
    char str3[50] = "악보를 완성하여 필수곡을 연주하세요.";
    char str4[50] = "연주 횟수 제한은 없으며";
    char str5[50] = "아이템은 꼭 사용해야 합니다.";
    char str6[50] = "아름다운 연주 기대하겠습니다.";

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
        gotoxy(34, 40);
        printf("%s", str4);
        return;
    case 3:
        gotoxy(32, 39);
        printf("%s", str5);
        gotoxy(32, 40);
        printf("%s", str6);
        return;
    default:
        return;
    }
}

// 피아노 그리기
void draw_piano(int x, int y)
{
	int i;
	for (i = 0; i < 4; i++) {
		gotoxy(x, y + i);
		printf("│  │   ││   │  │  │   ││   ││   │  │  │   ││   │");
	}
	gotoxy(x, y + 4);
	printf("│  └─┬─┘└─┬─┘  │  └─┬─┘└─┬─┘└─┬─┘  │  └─┬─┘└─┬─┘");
	for (i = 5; i < 7; i++) {
		gotoxy(x, y + i);
		printf("│    │    │    │    │    │    │    │    │    │ ");
	}
	gotoxy(x, y + 7);
	printf("│  A │  S │  D │  F │  G │  H │  J │  K │  L │ ");
	gotoxy(x, y + 8);
	printf("└────┴────┴────┴────┴────┴────┴────┴────┴────┴── ");
}

// 피아노 건반 눌렀을 때
void draw_piano_pressed(int x, int y, char key)
{
    int i, j;

    textcolor(0, 15);

    for (i = 0; i < 2; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 3; j++) {
            printf(" ");
        }
    }

    gotoxy(x, y + i);
    printf(" %c ", key - 'a' + 'A');

    textcolor(15, 0);
}

// 피아노 건반 뗐을 때
void erase_piano_pressed(int x, int y, char key)
{
    int i, j;

    textcolor(15, 0);

    for (i = 0; i < 2; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 3; j++) {
            printf(" ");
        }
    }

    gotoxy(x, y + i);
    printf(" %c ", key - 'a' + 'A');
}

// 건반 확인
int check_note(char ch, int line, int index)
{
    if (ch != song[line][index]) return 0;
    else return 1;
}

// 건반 기록
void draw_note_pressed(int x, int y, char key)
{
    textcolor(15, 0);

    gotoxy(x, y);
    
    switch (key)
    {
    case 'a':
        printf("%s", "도");
        break;
    case 's':
        printf("%s", "레");
        break;
    case 'd':
        printf("%s", "미");
        break;
    case 'f':
        printf("%s", "파");
        break;
    case 'g':
        printf("%s", "솔");
        break;
    case 'h':
        printf("%s", "라");
        break;
    case 'j':
        printf("%s", "시");
        break;
    case 'k':
        textcolor(3, 0);
        printf("%s", "도");
        textcolor(15, 0);
        break;
    case 'l':
        textcolor(3, 0);
        printf("%s", "레");
        textcolor(15, 0);
        break;
    }
    
    gotoxy(0, 0); // 건반이 사라지는 버그 해결
}

// 건반 기록 지우기
void clear_pressed_notes(int x, int y)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        gotoxy(x, y + i * 2);
        for (j = 0; j < 23; j++) { // 맵 영역 벗어나는 경우 j 최댓값 줄이기
            printf("  ");
        }
    }
}

// 진행 바 그리기
void draw_note_progress(int x, int y)
{
    int i, j;

    textcolor(0, 15);
    for (i = 0; i < 2; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 1; j++) {
            printf(" ");
        }
    }
    textcolor(15, 0);

    gotoxy(0, 0);
}

// 진행 바 지우기
void erase_note_progress(int x, int y)
{
    int i, j;

    for (i = 0; i < 2; i++) {
        gotoxy(x, y + i);
        for (j = 0; j < 60; j++) {
            printf(" ");
        }
    }

    gotoxy(0, 0);
}

// 진행도 퍼센트 계산
void draw_progress_percentage(int x, int y, float progress)
{
    gotoxy(x + 1, y);
    if (progress < 10.0f) printf("0");
    printf("%.f%%", progress);

    gotoxy(0, 0);
}

// 건반 입력, 처리
void update_input(int ch, int* line, int* index, int* noteX, int* noteY, float* progress, float* progressX)
{
    if (check_note(ch, *line, *index)) {
        (*index)++;
        draw_note_pressed(*noteX, *noteY, ch);
        *noteX += 3;
        draw_note_progress((int)(*progressX), 32);
        *progressX += 47 / 57.0f;
        *progress += 100 / 57.0f;
        draw_progress_percentage(NOTES_X + 21, 30, *progress);

        // 정답 확인
        if (*line == 3 && *index == 13) {
            CLEAR = 1;
        }

        // 2개의 마디가 끝나면 다음 줄로 이동
        if (song[*line][*index] == '\0') {
            (*line)++;
            *index = 0;
            *noteX = NOTES_X;
            (*noteY) += 2;
        }
    }
    // 틀린 음을 입력할 시 처음으로 돌아간다
    else {
        *line = 0;
        *index = 0;
        *noteX = NOTES_X;
        *noteY = NOTES_Y;
        clear_pressed_notes(NOTES_X, NOTES_Y);

        erase_note_progress(NOTES_X - 1, 32);
        *progressX = NOTES_X;
        *progress = 0.0f;
        draw_progress_percentage(NOTES_X + 21, 30, *progress);
    }
}

// 피아노 소리
void play_piano()
{
    int xPosNew = 23;
    int xPosOld = 23;
    int yPos = 13;
    char prevKey = 'a';

    // 정답용 배열 및 인덱스
    int line = 0;
    int index = 0;
    int noteX = NOTES_X, noteY = NOTES_Y;
    float progressX = NOTES_X / 1.0f;
    float progress = 0.0f;

    // 퍼센트 출력
    draw_progress_percentage(NOTES_X + 21, 30, progress);

    // 퍼센트 바 양쪽 끝 지정
    gotoxy(NOTES_X, 30);
    textcolor(0, 8);
    int i;
    for (i = 0; i < 20; i++) {
        printf(" ");
    }
    gotoxy(NOTES_X + 27, 30);
    for (i = 0; i < 20; i++) {
        printf(" ");
    }
    textcolor(15, 0);

    char ch;
    while (1) {
        if (kbhit() == 1) {  // 키보드가 눌려져 있으면
            ch = getch(); // key 값을 읽는다
            if (ch == ESC)
                break;
            else if (ch == '1') {
                system("cls");
                draw_map1();
            }
            else if (ch == '2') {
                system("cls");
                draw_map2();
            }
            
            switch (ch) {
            case 'a':
                PlaySound(TEXT("../piano/c4.wav"), NULL, SND_FILENAME | SND_ASYNC);
                xPosNew = 23;
                update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                break;
            case 's':
                PlaySound(TEXT("../piano/d4.wav"), NULL, SND_FILENAME | SND_ASYNC);
                xPosNew = 28;
                update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                break;
            case 'd':
                PlaySound(TEXT("../piano/e4.wav"), NULL, SND_FILENAME | SND_ASYNC);
                xPosNew = 33;
                update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                break;
            case 'f':
                PlaySound(TEXT("../piano/f4.wav"), NULL, SND_FILENAME | SND_ASYNC);
                xPosNew = 38;
                update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                break;
            case 'g':
                PlaySound(TEXT("../piano/g4.wav"), NULL, SND_FILENAME | SND_ASYNC);
                xPosNew = 43;
                update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                break;
            case 'h':
                PlaySound(TEXT("../piano/a5.wav"), NULL, SND_FILENAME | SND_ASYNC);
                xPosNew = 48;
                update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                break;
            case 'j': // 라# (시♭)
                if (map1_check2() == 2) {
                    PlaySound(TEXT("../piano/a-5.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    xPosNew = 53;
                    update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                }
                else {
                    PlaySound(TEXT("../piano/b5.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    xPosNew = 53;
                    ch = 'J'; // 키 입력을 변경하여 틀린 음으로 처리
                    update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                    ch = 'j'; // 원래 키로 되돌려 누른 건반이 정상적으로 표시되도록 함
                }
                break;
            case 'k':
                PlaySound(TEXT("../piano/c5.wav"), NULL, SND_FILENAME | SND_ASYNC);
                xPosNew = 58;
                update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                break;
            case 'l':
                PlaySound(TEXT("../piano/d5.wav"), NULL, SND_FILENAME | SND_ASYNC);
                xPosNew = 63;
                update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                break;
            }

            erase_piano_pressed(xPosOld, yPos, prevKey);
            draw_piano_pressed(xPosNew, yPos, ch);
            xPosOld = xPosNew;
            prevKey = ch;

            if (CLEAR) {
                Sleep(1000);
                ending_scene();
                break;
            }
        }
    }
}

// 맵3 그리기
void draw_map3(int inven[], int iCnt)
{
    draw_map(3);
	draw_piano(21, 8);
    draw_inventory(inven, iCnt);
    show_message(3);
    play_piano();
}