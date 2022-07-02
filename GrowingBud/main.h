#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>    // kbhit(), getch()
#include <time.h>     // Sleep()
#include "AvoidKiller.h"
#include "FindHome.h"
#include "Run.h"
#define WIDTH 56
#define HEIGHT 26
#define MAGIC_KEY 224    //상하좌우 화살표가 들어올때 선행되어 들어오는 숫자
#define SPACE 32        //스페이스 키 값
#define DOWN 72
#define LEFT 75
#define RIGHT 77
#define UP 80
#define TRUE 1
#define FALSE 0
//56 26
#define FirstX 30
#define FirstY 26


void SetConsoleView();
void gotoxy(int x, int y);
int GetKeyDown();
void CursorView();
void DrawBud(int budX, int budY);
void DrawBigBud(int budX, int budY);
void MarkOne();
void MarkTwo();
void MarkThree();
int FirstScene();
bool isinOne(const int budX, const int budY);
bool isinTwo(const int budX, const int budY);
bool isinThree(const int budX, const int budY);
void gogoOne();
void gogoTwo();