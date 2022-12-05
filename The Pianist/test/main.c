#include "escape.h"


void main()
{
	system("mode con cols=120 lines=50");
	removeCursor();
	//draw_start();
	//draw_map1();
	draw_map2();
	//draw_map3();
	//ending_scene();

	gotoxy(80, 45);
	textcolor(0, 0);
	system("pause"); // 콘솔창 유지
}