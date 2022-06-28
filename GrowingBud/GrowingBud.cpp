#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>    // kbhit(), getch()
#include <time.h>     // Sleep()
#define MAGIC_KEY 224    //상하좌우 화살표가 들어올때 선행되어 들어오는 숫자
#define SPACE 32        //스페이스 키 값
#define DOWN 72
#define LEFT 75
#define RIGHT 77
#define UP 80

void SetConsoleView();
void gotoxy(int x, int y);
int GetKeyDown();
void CursorView();
void DrawBud(int budX, int budY);
void MarkOne();
void MarkTwo();
void MarkThree();
bool isinOne();
bool isinTwo();
bool isinThree();

int main() {
    CursorView();
    char c = 0;
    int x = 30, y = 26;
    //56 26 왼쪽 위부터
    while (true) {
        MarkOne();
        MarkTwo();
        MarkThree();
        DrawBud(x, y);
        //printf("■");
        //gotoxy(x, y);
        //printf("%d %d",x, y);
        if (_kbhit()) {        //키보드 입력 확인 (true / false)
            c = _getch();// 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
            switch (c) {
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            case UP:
                y++;
                break;
            case DOWN:
                y--;
                break;
            }
            Sleep(30);
            system("cls");
        }
    }
}

void SetConsoleView() {
    system("mode con:conls=100 lines=25");
    system("title GrowingBud. By JYE");
}

void gotoxy(int x, int y)
{
    COORD Pos;        //x, y를 가지고 있는 구조체
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
int GetKeyDown() {
    if (_kbhit() != 0) {
        return _getch();
    }
}
void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void DrawBud(int budX, int budY) {
    printf("\n");
    gotoxy(budX, budY);
    /*printf("  ■■    ■■■■\n");
    printf("■   ■■■■    ■  \n");
    printf("  ■■  ■  ■■\n");
    printf("        ■\n");*/
    //printf("  ■■    ■■■■\n■   ■■■■    ■  \n  ■■  ■  ■■\n        ■\n");
    printf("♣");
}
void MarkOne() {
    //10~18&21~23
    gotoxy(10, 20);
    printf("\n");
    printf("                    ================\n");
    printf("                    ==제초제 피하기==\n");
    printf("                    ================\n");
}
void MarkTwo() {
    //22~30&11~13
    gotoxy(25, 10);
    printf("\n");
    printf("                                             ================\n");
    printf("                                             =====집 찾기=====\n");
    printf("                                             ================\n");
}
void MarkThree() {
    //32~40&16~18
    gotoxy(35, 15);
    printf("\n");
    printf("                                                                 ================\n");
    printf("                                                                 ===벌레 피하기===\n");
    printf("                                                                 ================\n");
}
