#include "main.h"

int gogo=0;
int x = FirstX, y = FirstY;
char c = 0;
int j = -1;
Obstacle obstacle[ObsN];

int main() {
    CursorView();

    //while (true) {
    //    FirstScene();
    //    if (j)break;
    //}
    gogo = 3;
    if (gogo == 1) {
        gogoOne();
        //gogo가 1,2,3일때로 이동
        //
    }
    else if (gogo == 2) {
        gogoTwo();

    }
    else if (gogo == 3) {
        x = 32;
        y = HEIGHT;

        bool isJumping = false;
        bool isBottom = true;
        const int gravity = 3;
        int score = 0;
        clock_t start, curr;
        start = clock();

        initObstacle(y);
        while (1) {
            if (isCollision()) {
                gotoxy(0, 5);
                printf("충돌");
                break;
            }
            if (_kbhit()) {        //키보드 입력 확인 (true / false)
                c = _getch();// 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰
                switch (c) {
                case SPACE:
                    if (isBottom) {                      
                        isJumping = true;
                        isBottom = false;
                    }
                    break;
                }
            }
            
            if (isJumping)
                y -= gravity;
            else
                y += gravity;

            for (int i = 0; i < ObsN; i++) {
                if (y >= obstacle[i].y) {
                    y = obstacle[i].y;
                    isBottom = true;
                }
            }
            DrawBigBud(x, y - 4);
            moveObstacle();
            Sleep(30);
            system("cls");

            if (y <= HEIGHT-9)
                isJumping = false;


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
    return 0;
}
void CursorView()
{
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
    cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}
void DrawBud(int budX, int budY) {
    gotoxy(budX, budY);
   /* printf("  ■■    ■■■■\n");
    printf("■   ■■■■    ■  \n");
    printf("  ■■  ■  ■■\n");
    printf("        ■\n");*/
    //printf("  ■■    ■■■■\n■   ■■■■    ■  \n  ■■  ■  ■■\n        ■\n");
    printf("♣");
}
void DrawBigBud(int budX, int budY) {
    gotoxy(budX, budY);
    printf("  ■■    ■■■■\n");
    gotoxy(budX, budY + 1);
    printf("■   ■■■■    ■  \n");
    gotoxy(budX, budY + 2);
    printf("  ■■  ■  ■■\n");
    gotoxy(budX, budY + 3);
    printf("        ■\n");
    gotoxy(budX, budY + 4);
    printf("        ■\n");
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
int FirstScene() {
    MarkOne();
    MarkTwo();
    MarkThree();
    DrawBud(x, y);
    //DrawBigBud(x, y);
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
        if (x < 0)
            x = 0;
        if (x > WIDTH - 1)
            x = WIDTH - 1;
        Sleep(30);
        system("cls");
    }
    if (isinOne(x, y)) {
        gogo = 1;
        return j=1;
    }
    else if (isinTwo(x, y)) {
        gogo = 2;
        return j=1;
    }
    else if (isinThree(x, y)) {
        gogo = 3;
        return j=1;
    }
    else return j=0;

}
bool isinOne(const int budX, const int budY) {
    //10~18&21~23
    if (10 <= budX && budX <= 18 && 21 <= budY && budY <= 23) {
        system("cls");
        return TRUE;
    }
    else return FALSE;
}
bool isinTwo(const int budX, const int budY) {
    //22~30&11~13
    if (22 <= budX && budX <= 30 && 11 <= budY && budY <= 13) {
        system("cls");
        return TRUE;
    }
    else return FALSE;
}
bool isinThree(const int budX, const int budY) {
    //32~40&16~18
    if (32 <= budX && budX <= 40 && 16 <= budY && budY <= 18) {
        system("cls");
        return TRUE;
    }
    else return FALSE;
}
void gogoOne() {
    gogo == 0;
    srand(time(NULL));
    initKillerGame();
    do {
        CreateKiller();
        FallKiller();
        DelKiller();
        MoveBudOne();
        PrintKillerGame();
        Sleep(10);
    } while (!(DamagedBud()));
    system("cls");
    x = FirstX, y = FirstY;
    while (true) {
        FirstScene();
        if (isinOne(x, y)) {
            gogo = 1;
            break;
        }
        if (isinTwo(x, y)) {
            gogo = 2;
            break;
        }
        if (isinThree(x, y)) {
            gogo = 3;
            break;
        }
    }
}
void gogoTwo() {
    gogo = 0;
    srand(time(NULL));
    createwall();
    createmaze(1, 1);
    x = 1, y = 2;
    while (1) {
        drawMaze();
        DrawBud(x, y);

        if (_kbhit()) {        //키보드 입력 확인 (true / false)
            c = _getch();// 방향키 입력시 224 00이 들어오게 되기에 앞에 있는 값 224를 없앰

            switch (c) {
            case LEFT:
                if (ismoveable(x - 1, y))
                    x--;
                break;
            case RIGHT:
                if (ismoveable(x + 1, y))
                    x++;
                break;
            case UP:
                if (ismoveable(x, y + 1))
                    y++;
                break;
            case DOWN:
                if (ismoveable(x, y - 1))
                    y--;
                break;
            }
            if (x < 0)
                x = 0;
            if (x > WIDTH - 1)
                x = WIDTH - 1;
            Sleep(30);
            system("cls");
        }
        if (finishMaze(x, y)) {
            system("cls");
            x = FirstX, y = FirstY;
            break;
        }
    }
    while (true) {
        FirstScene();
        if (isinOne(x, y)) {
            gogo = 1;
            break;
        }
        if (isinTwo(x, y)) {
            gogo = 2;
            break;
        }
        if (isinThree(x, y)) {
            gogo = 3;
            break;
        }
    }

}