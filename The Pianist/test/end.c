#include "escape.h"

// ����� �� �׸���
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

// ����� �� �����
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

// ����� �� �����̱�
void draw_audio_wave(int* duration)
{
    int bars_up[10] = { 1, };
    int bars_down[10] = { 1, };
    int i, j;

    // ����� �� �׸���
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

    // ����� �� ��ȯ �ð� ����
    Sleep(300);

    // ����� �� �����
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

// ���� ȭ��
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

    // �뷡 ���۰� �Բ� ������� �����ϵ��� ����
    Sleep(1500);

    // ESCŰ ���� ������ �뷡 ��� �� ����� ���̺� ���
    // �Ǵ� �뷡�� ������ �ڵ����� ����
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

        // �� ��� �ð�
        int pos2 = star_pos;
        star_pos += 1 / 18.0f;
        if ((int)star_pos != (int)pos2) {
            gotoxy((int)pos2, 16);
            printf("-");
            duration--;
        }
        draw_star((int)star_pos, 16);
    }

    // ESC Ű�� ���� ������ ��� ���� ����
    if (ch == ESC) {
        system("cls");
        exit(1);
    }
    // R Ű�� ���� ������ ��� ȭ���� ����� �ٽ� map1���� ����
    if (ch == 'r') {
        PlaySound(NULL, 0, 0);
        system("cls");
        draw_map0();
    }
    // �ƹ� Ű�� ������ ���� ���·� �뷡�� ���� ��� �ٽ� ó������ ���� ���� �� �Է� ��� (���� ����)
    else {
        duration = 49;
        star_pos = 33;
        ending_scene();
    }
}