#include "escape.h"

// 오디오 바 그리기
void draw_audio_bar(int x, int y, int height, int dir)
{
    int i, j;

    if (!dir) {
        textcolor(0, 15);
        for (i = 0; i < height; i++) {
            gotoxy(x, y - i);
            for (j = 0; j < 3; j++) {
                printf(" ");
            }
        }
    }
    else {
        textcolor(0, 8);
        for (i = 0; i < height; i++) {
            gotoxy(x, y + i);
            for (j = 0; j < 3; j++) {
                printf(" ");
            }
        }
    }
    textcolor(15, 0);
}

// 오디오 바 지우기
void erase_audio_bar(int x, int y, int height, int dir)
{
    int i, j;

    textcolor(15, 0);
    if (!dir) {
        for (i = 0; i < height; i++) {
            gotoxy(x, y - i);
            for (j = 0; j < 3; j++) {
                printf(" ");
            }
        }
    }
    else {
        for (i = 0; i < height; i++) {
            gotoxy(x, y + i);
            for (j = 0; j < 3; j++) {
                printf(" ");
            }
        }
    }
}

// 오디오 바 움직이기
void draw_audio_wave(int* duration)
{
    int bars_up[10] = { 1, };
    int bars_down[10] = { 1, };
    int i, j;

    // 오디오 바 그리기
    int xPos = 34, yPos = 30;
    for (i = 0; i < 10; i++) {
        int bar_height = 1 + rand() % 7;
        bars_up[i] = bar_height;
        bars_down[i] = bar_height;
        draw_audio_bar(xPos, yPos, bar_height, 0);
        xPos += 5;
    }
    xPos = 34;
    for (i = 0; i < 10; i++) {
        //int bar_height = 1 + rand() % 4;
        //bars_down[i] = bar_height;
        draw_audio_bar(xPos, yPos + 2, bars_down[i], 1);
        xPos += 5;
    }

    // 오디오 바 전환 시간 조정
    Sleep(300);

    // 오디오 바 지우기
    xPos = 34;
    for (i = 0; i < 10; i++) {
        erase_audio_bar(xPos, yPos, bars_up[i], 0);
        xPos += 5;
    }
    xPos = 34;
    for (i = 0; i < 10; i++) {
        erase_audio_bar(xPos, yPos + 2, bars_down[i], 1);
        xPos += 5;
    }
}

// 엔딩 화면
void ending_scene()
{
    system("cls");
    gotoxy(20, 8);
    printf("C L E A R");
    gotoxy(32, 18);
    printf(" Always With Me (Itsumo Nando Demo) - Spirited Away ");
    PlaySound(TEXT("../piano/AlwaysWithMe.wav"), NULL, SND_FILENAME | SND_ASYNC);

    gotoxy(90, 43);
    printf("Restart: R");
    gotoxy(90, 45);
    printf("   Quit: ESC");

    int i;
    int xPos = 34, yPos = 30;
    for (i = 0; i < 10; i++) {
        draw_audio_bar(xPos, yPos, 1, 0);
        draw_audio_bar(xPos, yPos + 2, 1, 1);
        xPos += 5;
    }

    // 노래 시작과 함께 오디오바 동작하도록 조정
    Sleep(1500);

    // ESC키 누를 때까지 노래 재생 및 오디오 웨이브 출력
    // 또는 노래가 끝나면 자동으로 종료
    char ch = ' ';
    static int duration = 49;
    static float star_pos = 33;

    while (1) {
        if (kbhit() == 1) {
            ch = getch();
            if (ch == ESC || ch == 'r') break;
        }
        if (duration == 0) {
            int xPos = 34, yPos = 30;
            for (i = 0; i < 10; i++) {
                draw_audio_bar(xPos, yPos, 1, 0);
                draw_audio_bar(xPos, yPos + 2, 1, 1);
                xPos += 5;
            }
            break;
        }

        draw_audio_wave(&duration);

        // 곡 재생 시간
        int pos2 = star_pos;
        star_pos += 1 / 18.0f;
        if ((int)star_pos != (int)pos2) {
            gotoxy((int)pos2, 16);
            printf("-");
            duration--;
        }
        draw_star((int)star_pos, 16);
    }

    // ESC 키를 눌러 종료한 경우 게임 종료
    if (ch == ESC) {
        system("cls");
        exit(1);
    }
    // R 키를 눌러 종료한 경우 화면을 지우고 다시 map1부터 시작
    if (ch == 'r') {
        PlaySound(NULL, 0, 0);
        system("cls");
        draw_map0();
    }
    // 아무 키도 누르지 않은 상태로 노래가 끝난 경우 다시 처음부터 연주 시작 후 입력 대기 (무한 루프)
    else {
        duration = 49;
        star_pos = 33;
        ending_scene();
    }
}