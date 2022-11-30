#include "escape.h"

// 메시지 출력
void print_message2(int n) {
	char str1[50] = "두 번째 미션은 두뇌테스트입니다.";
	char str2[50] = "그저 틀에 박혀 문제를 푼다면 어렵겠지만";
	char str3[50] = "새로운 시각으로 문제를 본다면 쉽게";
	char str4[50] = "필수곡 악보 조각을 모을 수 있습니다.";
	char str5[50] = "단 악보 조각 위치는 1초만 보여줍니다.";
	char str6[50] = "뛰어난 기억력과 지적인 모습 기대하겠습니다.";

	textcolor(15, 0);
	switch (n)
	{
	case 1:
		gotoxy(31, 39);
		printf("%s", str1);
		gotoxy(27, 40);
		printf("%s", str2);
		return;
	case 2:
		gotoxy(29, 39);
		printf("%s", str3);
		gotoxy(29, 40);
		printf("%s", str4);
		return;
	case 3:
		gotoxy(28, 39);
		printf("%s", str5);
		gotoxy(25, 40);
		printf("%s", str6);
		return;
	default:
		return;
	}
}

// map2
char map2[ROW_MAX_SIZE2][COL_MAX_SIZE2] = {
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000000",
};

// 보물찾기맵 그리기
void draw_site()
{
	int i, j;

	for (i = 0; i < ROW_MAX_SIZE2; i++) {
		for (j = 0; j < COL_MAX_SIZE2; j++) {
			gotoxy(MAP2_START_X + j, MAP2_START_Y + i);
			if (map2[i][j] == '1') {
				textcolor(0, 15);
				printf(" ");
			}
			if (map2[i][j] == '0') {
				textcolor(0, 3);
				printf(" ");
			}
		}
	}

	textcolor(15, 0);
}

// 보물찾기맵 지우기
void erase_site()
{
	int i, j;

	for (i = 0; i < ROW_MAX_SIZE2; i++) {
		for (j = 0; j < COL_MAX_SIZE2; j++) {
			gotoxy(MAP2_START_X + j, MAP2_START_Y + i);
			textcolor(0, 0);
			printf(" ");
		}
	}

	textcolor(15, 0);
}

// 캐릭터 시야 그리기
void draw_player_sight(int x, int y)
{
	int i, j;

	// 배열에서의 별 위치
	int xPos = x - MAP2_START_X;
	int yPos = y - MAP2_START_Y;

	for (i = 0; i < PLAYER_SIGHT_Y * 2 + 1; i++) {
		for (j = 0; j < PLAYER_SIGHT_X * 2 + 2; j++) {
			gotoxy(x + j - PLAYER_SIGHT_X, y + i - PLAYER_SIGHT_Y);
			int xx = xPos + j - PLAYER_SIGHT_X;
			int yy = yPos + i - PLAYER_SIGHT_Y;

			if (xx < 0 || yy < 0 || xx >= COL_MAX_SIZE2 || yy >= ROW_MAX_SIZE2)
				continue;

			if (map2[yy][xx] == '0') {
				textcolor(0, 0);
				printf(" ");
			}
			else if (map2[yy][xx] == '1') {
				draw_item(xx + MAP2_START_X, yy + MAP2_START_Y, 1);
			}
			else if (map2[yy][xx] == '3') {
				draw_item(xx + MAP2_START_X, yy + MAP2_START_Y, 3);
			}
			else if (map2[yy][xx] == '4') {
				draw_item(xx + MAP2_START_X, yy + MAP2_START_Y, 4);
			}
		}
	}

	textcolor(15, 0);
}

// 캐릭터 시야 지우기
void remove_player_sight(int x, int y)
{
	int i, j;
	int xPos = x - MAP2_START_X;
	int yPos = y - MAP2_START_Y;

	for (i = 0; i < PLAYER_SIGHT_Y * 2 + 1; i++) {
		for (j = 0; j < PLAYER_SIGHT_X * 2 + 2; j++) {
			gotoxy(x + j - PLAYER_SIGHT_X, y + i - PLAYER_SIGHT_Y);

			int xx = xPos + j - PLAYER_SIGHT_X;
			int yy = yPos + i - PLAYER_SIGHT_Y;
			if (map2[yy][xx] == '1') {
				textcolor(0, 0);
				printf(" ");
			}
			if (map2[yy][xx] == '0') {
				textcolor(0, 0);
				printf(" ");
			}
		}
	}

	textcolor(15, 0);
}

// 아이템 랜덤 위치 변수
int key_x = 0, key_y = 0;
int item1_x = 0, item1_y = 0;
int item2_x = 0, item2_y = 0;
int item3_x = 0, item3_y = 0;
int item4_x = 0, item4_y = 0;
int item5_x = 0, item5_y = 0;
int item6_x = 0, item6_y = 0;
int item7_x = 0, item7_y = 0;
int item8_x = 0, item8_y = 0;

// 아이템 랜덤하게 그리기
void draw_random_item()
{
	// x 짝수
	// 중복 제거

	// x 44 ~ 74
	// y 9 ~ 34
	srand(time(NULL));

	while (1) {
		key_x = rand() % 31 + 22;
		if ((key_x % 2) == 1) {
			break;
		}
	}
	key_y = rand() % 25 + 10;
	while (1) {
		item1_x = rand() % 31 + 22;
		if ((item1_x % 2) == 1) {
			break;
		}
	}
	item1_y = rand() % 25 + 10;
	while (1) {
		item2_x = rand() % 31 + 22;
		if ((item2_x % 2) == 1) {
			break;
		}
	}
	item2_y = rand() % 25 + 10;
	while (1) {
		item3_x = rand() % 31 + 22;
		if ((item3_x % 2) == 1) {
			break;
		}
	}
	item3_y = rand() % 25 + 10;
	while (1) {
		item4_x = rand() % 31 + 22;
		if ((item4_x % 2) == 1) {
			break;
		}
	}
	item4_y = rand() % 25 + 10;
	while (1) {
		item5_x = rand() % 31 + 22;
		if ((item5_x % 2) == 1) {
			break;
		}
	}
	item5_y = rand() % 25 + 10;
	while (1) {
		item6_x = rand() % 31 + 22;
		if ((item6_x % 2) == 1) {
			break;
		}
	}
	item6_y = rand() % 25 + 10;
	while (1) {
		item7_x = rand() % 31 + 22;
		if ((item7_x % 2) == 1) {
			break;
		}
	}
	item7_y = rand() % 25 + 10;
	while (1) {
		item8_x = rand() % 31 + 22;
		if ((item8_x % 2) == 1) {
			break;
		}
	}
	item8_y = rand() % 25 + 10;

	map2[key_y - MAP2_START_Y][key_x - MAP2_START_X] = '1';
	map2[item1_y - MAP2_START_Y][item1_x - MAP2_START_X] = '3';
	map2[item2_y - MAP2_START_Y][item2_x - MAP2_START_X] = '3';
	map2[item3_y - MAP2_START_Y][item3_x - MAP2_START_X] = '3';
	map2[item4_y - MAP2_START_Y][item4_x - MAP2_START_X] = '3';
	map2[item5_y - MAP2_START_Y][item5_x - MAP2_START_X] = '3';
	map2[item6_y - MAP2_START_Y][item6_x - MAP2_START_X] = '4';
	map2[item7_y - MAP2_START_Y][item7_x - MAP2_START_X] = '4';
	map2[item8_y - MAP2_START_Y][item8_x - MAP2_START_X] = '4';

	draw_item(key_x, key_y, 1);
	draw_item(item1_x, item1_y, 3);
	draw_item(item2_x, item2_y, 3);
	draw_item(item3_x, item3_y, 3);
	draw_item(item4_x, item4_y, 3);
	draw_item(item5_x, item5_y, 3);
	draw_item(item6_x, item6_y, 4);
	draw_item(item7_x, item7_y, 4);
	draw_item(item8_x, item8_y, 4);

	// 아이템 중복처리

	textcolor(8, 0);
}

int check_map2_key = 0; // 아이템 얻었는지 확인
int check_map2_item1 = 0;
int check_map2_item2 = 0;
int check_map2_item3 = 0;
int check_map2_item4 = 0;
int check_map2_item5 = 0;
int check_map2_item6 = 0;
int check_map2_item7 = 0;
int check_map2_item8 = 0;
// 아이템 충돌 감지
int check_item_collision2(int x, int y, char ch)
{
	// 열쇠
	if (x == key_x && y == key_y) {
		check_map2_key = 1;
		return 9;
	}

	// 아이템1
	if (x == item1_x && y == item1_y) {
		check_map2_item1 = 1;
		return 1;
	}

	// 아이템2
	if (x == item2_x && y == item2_y) {
		check_map2_item2 = 1;
		return 2;
	}

	// 아이템3
	if (x == item3_x && y == item3_y) {
		check_map2_item3 = 1;
		return 3;
	}

	// 아이템4
	if (x == item4_x && y == item4_y) {
		check_map2_item4 = 1;
		return 4;
	}

	// 아이템5
	if (x == item5_x && y == item5_y) {
		check_map2_item5 = 1;
		return 5;
	}

	// 아이템6
	if (x == item6_x && y == item6_y) {
		check_map2_item6 = 1;
		return 6;
	}

	// 아이템7
	if (x == item7_x && y == item7_y) {
		check_map2_item7 = 1;
		return 7;
	}

	// 아이템8
	if (x == item8_x && y == item8_y) {
		check_map2_item8 = 1;
		return 8;
	}

	return 0;
}

// 퀴즈
void print_quiz1(int n)
{
	// 1. 힌트: 동전, 정답: 600
	char quiz1_1[50] = "물음표에 들어갈 것은?";
	char quiz1_2[50] = "10 50 60 ? 110 150 160";
	char quiz1_3[50] = "? 510 550 560 ? 610";
	char answer[50];

	textcolor(15, 0);
	switch(n) {
	case 1:
		gotoxy(30, 38);
		printf("%s", quiz1_1);
		gotoxy(30, 39);
		printf("%s", quiz1_2);
		gotoxy(30, 40);
		printf("%s", quiz1_3);
		gotoxy(27, 41); // 힌트 출력, 정답 입력 기능 추가
		scanf("%s", answer);
		return;
	default:
		return;
	}
}
void print_quiz2()
{
	// 2. 힌트: 교차점, 정답: 0
	char quiz2_1[50] = "물음표에 들어갈 것은?";
	char quiz2_2[50] = "+ → 1, & → 2, $ → 3, % → ?";
	char quiz2_3[50] = "";
}
void print_quiz3()
{
	// 3. 힌트: 시간, 정답: 2
	char quiz3_1[50] = "물음표에 들어갈 것은?";
	char quiz3_2[50] = "9 - 6 = 3, 9 + 6 = 3, 8 + 6 = ?";
	char quiz3_3[50] = "";
}
void print_quiz4()
{
	// 4. 힌트: 주차장, 정답: 87
	char quiz4_1[50] = "물음표에 들어갈 것은?";
	char quiz4_2[50] = "16 06 68 88 ? 98";
	char quiz4_3[50] = "";
}
void print_quiz5()
{
	// 5. 힌트: 대각선, 정답: 545 + 5 = 550
	char quiz5_1[50] = "직선을 하나만 그어 올바른 식을 완성하시오";
	char quiz5_2[50] = "(단 등호는 건드리지 않는다)";
	char quiz5_3[50] = "5 + 5 + 5 = 500";
}
void print_quiz6()
{
	// 6. 힌트: 다섯글자, 정답: 가위바위보
	char quiz6_1[50] = "5는 0보다 강하고, 0은 2보다 강하고,";
	char quiz6_2[50] = "2는 5보다 강하다. 왜일까?";
	char quiz6_3[50] = "";
}
void print_quiz7()
{
	// 7. 힌트: 방정식, 정답: 아직 태어나지 않았다.
	char quiz7_1[50] = "어머니는 아들보다 21세 더 많다.";
	char quiz7_2[50] = "6년 후에 아들은 어머니보다 5배 연하가 된다.";
	char quiz7_3[50] = "아들의 나이는 몇살인가?";
}
void print_quiz8()
{
	// 8. 힌트: 양순음, 정답: 입술
	char quiz8_1[50] = "이것은 서울, 대구에서는 만날 수 없지만";
	char quiz8_2[50] = "마포 마산에서는 마날 수 있다.";
	char quiz8_3[50] = "";
}

// 퀴즈 출력
void show_quiz(int k)
{
	int n = 1;
	unsigned char ch = 0;

	while (n < 9) {
		if (kbhit() == 1) {
			ch = getch();
			if (ch == SPACEBAR) {
				erase_text(21, 37, 69, 42);
				switch (k) {
				case 1:
					print_quiz1(n);
					break;
				case 2:
					print_quiz2(n);
					break;
				case 3:
					print_quiz3(n);
					break;
				case 4:
					print_quiz4(n);
					break;
				case 5:
					print_quiz5(n);
					break;
				case 6:
					print_quiz6(n);
					break;
				case 7:
					print_quiz7(n);
					break;
				case 8:
					print_quiz8(n);
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

// 문 충돌 감지
// 랜덤 위치 설정 추가
int check_door_collision2(int x, int y, char ch)
{
	if (x == 67 && y == 8) {
		if (check_map2_key == 1) {
			return 1;
		}
	}

	return 0;
}

// 열쇠 확인
//int map2_check2()
//{
//	return check_map2_key;
//}

// 맵2 충돌 감지
int check_map2_collision(int x, int y, char ch)
{
	if (x < MAP2_START_X || y < MAP2_START_Y || x >= MAP2_START_X + COL_MAX_SIZE2 - 1 || y >= MAP2_START_Y + ROW_MAX_SIZE2)
		return 1;


	switch (ch) {
	case UP: case DOWN:
		if (map2[y - MAP2_START_Y][x - (MAP2_START_X - 2)] == '1')
		{
			return 1;
		}
		if (map2[y - MAP2_START_Y][x - MAP2_START_X] == '1')
		{
			return 1;
		}
		break;
	case LEFT:
		x -= 1;

		if (map2[y - MAP2_START_Y][x - MAP2_START_X] == '1')
		{
			return 1;
		}
		break;
	case RIGHT:
		x += 2;

		if (map2[y - MAP2_START_Y][x - MAP2_START_X] == '1')
		{
			return 1;
		}
		break;
	}
	return 0;
}

// 캐릭터 움직이기
void move_star2()
{
	unsigned char ch; // 특수키 0xe0 을 입력받으려면 unsigned char 로 선언해야 함
	int oldx = MAP2_START_X + 5, oldy = MAP2_START_Y + 1, newx = MAP2_START_Y + 5, newy = MAP2_START_Y + 1;
	int invenX = 74, invenY = 8;
	int keep_moving;

	ch = 0; // 초기값 정지상태
	keep_moving = 0;

	while (1) {
		if (kbhit() == 1) {  // 키보드가 눌려져 있으면
			ch = getch(); // key 값을 읽는다
			// ESC 누르면 프로그램 종료 추가
			if (ch == ESC)
				break;
			if (ch == SPECIAL1 || ch == SPECIAL2) { // 만약 특수키
				// 예를 들어 UP key의 경우 0xe0 0x48 두개의 문자가 들어온다.
				ch = getch();
				switch (ch) {
				case UP:
				case DOWN:
				case LEFT:
				case RIGHT:
					keep_moving = 1;
					break;
				default: // 방향키가 아니면 멈춘다
					keep_moving = 0;
				}
			}
		}

		if (keep_moving) { // 움직이고 있으면
			switch (ch) {
			case UP:
				if (oldy > MAP_Y1)
					newy = oldy - 1;
				break;
			case DOWN:
				if (oldy < MAP_Y2)
					newy = oldy + 1;
				break;
			case LEFT:
				if (oldx > MAP_X1)
					newx = oldx - 2;
				break;
			case RIGHT:
				if (oldx < MAP_X2)
					newx = oldx + 2;
				break;
			}

			// 모든 충돌을 감지할 때 별이 2칸을 차지한다는 것을 기억
			// 이때 별의 첫번째 칸(별의 왼쪽 절반)이 충돌을 처리하는 좌표의 기준이 된다는 것을 주의

			// 미로 밖에 있는 경우
			// map의 경계와 충돌하는 경우 벗어나지 않도록 다음 위치를 현재 위치로 수정
			if (check_map2_collision(newx, newy, ch)) {
				newx = oldx;
				newy = oldy;
			}

			// 아이템 충돌 시 인벤토리 창에 뜨게 하기
			int item = check_item_collision2(newx, newy, ch);

			// 아이템이 존재하는 경우 ( 1 또는 2 )
			if (item) {
				gotoxy(invenX, invenY); // 인벤 위치로 이동
				if (item == 9) {
					textcolor(14, 0);
					printf("열쇠");
				}
				else if (item == 1) {
					textcolor(11, 0);
					printf("FGKFK");
				}
				else if (item == 2) {
					textcolor(11, 0);
					printf("HGKG");
				}
				else if (item == 3) {
					textcolor(11, 0);
					printf("FSHFD");
				}
				else if (item == 4) {
					textcolor(11, 0);
					printf("D");
				}
				else if (item == 5) {
					textcolor(11, 0);
					printf("SDFGAF");
				}
				else if (item == 6) {
					textcolor(11, 0);
					printf("GHJJHGFG");
				}
				else if (item == 7) {
					textcolor(11, 0);
					printf("GHG");
				}
				else if (item == 8) {
					textcolor(11, 0);
					printf("GGFF");
				}
				invenY += 2; // 다음 인벤 공간으로 이동
			}

			// 문 충돌 시 다음 맵으로
			if (check_door_collision2(newx, newy, ch) == 1) {
				if (check_map2_key == 1) { // 열쇠를 얻었다면
					system("cls");
					textcolor(15, 0);
					draw_map3();
					// 인벤토리 불러오기
					return;
				}
				/*else {
					newx = 27;
					newy = 12;
				}*/
			}

			remove_player_sight(oldx, oldy);
			remove_star(oldx, oldy); // 마지막 위치의 STAR를 지우고
			draw_player_sight(newx, newy);
			draw_star(newx, newy); // 새로운 위치에서 STAR를 표시한다.
			// 마지막 위치를 기억한다.
			oldx = newx;
			oldy = newy;
			keep_moving = 0; //1:계속이동, 0:한번에 한칸씩이동
		}
	}
}

// 맵2 그리기
void draw_map2()
{
	draw_map(2);
	show_message(2);
	// 맵을 1초동안 보여준 뒤 사라짐
	draw_site();
	draw_door(64, 7);
	draw_random_item();
	Sleep(1000);
	erase_site();
	draw_player_sight(MAP2_START_X + 5, MAP2_START_Y + 1);
	draw_star(MAP2_START_X + 5, MAP2_START_Y + 1);
	move_star2();
}