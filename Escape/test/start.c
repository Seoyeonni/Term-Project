#include "escape.h"

// �޽��� ���
void print_message0(int n)
{
    char str1[50] = "�Ѽ����Ǵ��б� �ǾƳ�� �Ǳ� ������";
    char str2[50] = "���� �� �л� ������ ��� ȯ���մϴ�.";
    char str3[50] = "�������� ���ݺ��� ���� �̼ǵ��� ����";
    char str4[50] = "�ʼ��� �Ǻ��� �ϼ��Ͽ� �����ؾ߸�";
    char str5[50] = "������ ���ָ� �� �� �ֽ��ϴ�.";
    char str6[50] = "�׷� ���ݺ��� ������ �����ϰڽ��ϴ�.";

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