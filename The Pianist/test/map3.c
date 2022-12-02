#include "escape.h"

#define NOTES_X 23
#define NOTES_Y 19

// ���� ���� ���� 1�� ��� Ŭ����
int CLEAR = 0;

// �ʼ��� �Ǻ�
char song[4][16] = {
    "fghfkhgkgfshfdd",
    "sdfgafghjjhgfg",
    "fghfkhgkgfshfdd",
    "sdfgafghgggff"
};

// �޽��� ���
void print_message3(int n) {
    char str1[50] = "�� ��° �̼��� �ʼ��� �����Դϴ�.";
    char str2[50] = "�տ� �̼ǵ��� ���Ͽ� ���� ��Ʈ��";
    char str3[50] = "�Ǻ��� �ϼ��Ͽ� �ʼ����� �����ϼ���.";
    char str4[50] = "���� Ƚ�� ������ ������";
    char str5[50] = "�������� �� ����ؾ� �մϴ�.";
    char str6[50] = "�Ƹ��ٿ� ���� ����ϰڽ��ϴ�.";

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

// �ǾƳ� �׸���
void draw_piano(int x, int y)
{
	int i;
	for (i = 0; i < 4; i++) {
		gotoxy(x, y + i);
		printf("��  ��   ����   ��  ��  ��   ����   ����   ��  ��  ��   ����   ��");
	}
	gotoxy(x, y + 4);
	printf("��  ��������������������  ��  ������������������������������  ��  ��������������������");
	for (i = 5; i < 7; i++) {
		gotoxy(x, y + i);
		printf("��    ��    ��    ��    ��    ��    ��    ��    ��    �� ");
	}
	gotoxy(x, y + 7);
	printf("��  A ��  S ��  D ��  F ��  G ��  H ��  J ��  K ��  L �� ");
	gotoxy(x, y + 8);
	printf("������������������������������������������������������������������������������������������������ ");
}

// �ǾƳ� �ǹ� ������ ��
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

// �ǾƳ� �ǹ� ���� ��
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

// �ǹ� Ȯ��
int check_note(char ch, int line, int index)
{
    if (ch != song[line][index]) return 0;
    else return 1;
}

// �ǹ� ���
void draw_note_pressed(int x, int y, char key)
{
    textcolor(15, 0);

    gotoxy(x, y);
    
    switch (key)
    {
    case 'a':
        printf("%s", "��");
        break;
    case 's':
        printf("%s", "��");
        break;
    case 'd':
        printf("%s", "��");
        break;
    case 'f':
        printf("%s", "��");
        break;
    case 'g':
        printf("%s", "��");
        break;
    case 'h':
        printf("%s", "��");
        break;
    case 'j':
        printf("%s", "��");
        break;
    case 'k':
        textcolor(3, 0);
        printf("%s", "��");
        textcolor(15, 0);
        break;
    case 'l':
        textcolor(3, 0);
        printf("%s", "��");
        textcolor(15, 0);
        break;
    }
    
    gotoxy(0, 0); // �ǹ��� ������� ���� �ذ�
}

// �ǹ� ��� �����
void clear_pressed_notes(int x, int y)
{
    int i, j;

    for (i = 0; i < 4; i++) {
        gotoxy(x, y + i * 2);
        for (j = 0; j < 23; j++) { // �� ���� ����� ��� j �ִ� ���̱�
            printf("  ");
        }
    }
}

// ���� �� �׸���
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

// ���� �� �����
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

// ���൵ �ۼ�Ʈ ���
void draw_progress_percentage(int x, int y, float progress)
{
    gotoxy(x + 1, y);
    if (progress < 10.0f) printf("0");
    printf("%.f%%", progress);

    gotoxy(0, 0);
}

// �ǹ� �Է�, ó��
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

        // ���� Ȯ��
        if (*line == 3 && *index == 13) {
            CLEAR = 1;
        }

        // 2���� ���� ������ ���� �ٷ� �̵�
        if (song[*line][*index] == '\0') {
            (*line)++;
            *index = 0;
            *noteX = NOTES_X;
            (*noteY) += 2;
        }
    }
    // Ʋ�� ���� �Է��� �� ó������ ���ư���
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

// �ǾƳ� �Ҹ�
void play_piano()
{
    int xPosNew = 23;
    int xPosOld = 23;
    int yPos = 13;
    char prevKey = 'a';

    // ����� �迭 �� �ε���
    int line = 0;
    int index = 0;
    int noteX = NOTES_X, noteY = NOTES_Y;
    float progressX = NOTES_X / 1.0f;
    float progress = 0.0f;

    // �ۼ�Ʈ ���
    draw_progress_percentage(NOTES_X + 21, 30, progress);

    // �ۼ�Ʈ �� ���� �� ����
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
        if (kbhit() == 1) {  // Ű���尡 ������ ������
            ch = getch(); // key ���� �д´�
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
            case 'j': // ��# (�â�)
                if (map1_check2() == 2) {
                    PlaySound(TEXT("../piano/a-5.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    xPosNew = 53;
                    update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                }
                else {
                    PlaySound(TEXT("../piano/b5.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    xPosNew = 53;
                    ch = 'J'; // Ű �Է��� �����Ͽ� Ʋ�� ������ ó��
                    update_input(ch, &line, &index, &noteX, &noteY, &progress, &progressX);
                    ch = 'j'; // ���� Ű�� �ǵ��� ���� �ǹ��� ���������� ǥ�õǵ��� ��
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

// ��3 �׸���
void draw_map3(int inven[], int iCnt)
{
    draw_map(3);
	draw_piano(21, 8);
    draw_inventory(inven, iCnt);
    show_message(3);
    play_piano();
}