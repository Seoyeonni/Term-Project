#include "escape.h"

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
    /*switch (n)
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
    }*/
}

void draw_start()
{
    show_message(0);
}