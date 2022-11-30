#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#pragma comment (lib, "winmm.lib")

#define ROW_MAX_SIZE1 22
#define COL_MAX_SIZE1 50

#define ROW_MAX_SIZE2 28
#define COL_MAX_SIZE2 50

#define BLANK "  "

#define ESC 0x1b

#define SPECIAL1 0xe0 // 특수키는 0xe0 + key 값으로 구성된다.
#define SPECIAL2 0x00 // keypad 경우 0x00 + key 로 구성된다.

#define UP  0x48 // Up key는 0xe0 + 0x48 두개의 값이 들어온다.
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d

#define SPACEBAR 0x20

#define MAP_X1 20
#define MAP_Y1 6
#define MAP_X2 75
#define MAP_Y2 35

#define PLAYER_SIGHT_X 4
#define PLAYER_SIGHT_Y 2

#define MAP2_START_X 22
#define MAP2_START_Y 7

int check_maze_start_collision(int x, int y, char ch);
int check_door_collision1(int x, int y, char ch);
void show_message(int k);
void erase_text(int x1, int y1, int x2, int y2);
void print_message0(int n);
void print_message1(int n);
void print_message2(int n);
void print_message3(int n);
int map1_check1();
int map1_check2();
void draw_random_item();
int check_item_collision2(int x, int y, char ch);
void print_quiz1(int n);
void draw_start();

// basic
void gotoxy(int x, int y);
void removeCursor(void);
void textcolor(int fg_color, int bg_color);

// draw
void draw_map(int n);
void draw_star(int x, int y);
void remove_star(int x, int y);
void draw_box(int x1, int y1, int x2, int y2);
void draw_door(int x, int y);
void draw_item(int x, int y, int n);

// map1
void draw_map1();
void draw_maze();
void move_star();
int check_map1_collision(int x, int y, char ch);
int check_maze_collision(int x, int y, char ch);
int check_item_collision1(int x, int y, char ch);

// map2
void draw_map2();

// map3
void draw_map3();
void play_piano();