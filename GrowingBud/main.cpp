#include "main.h"
int gogo = 0;
int x = FirstX, y = FirstY;
char c = 0;
int j = -1;
int budVersion = 1, budVersionOne = 1, budVersionTwo = 1, budVersionThree = 1;
int score[4] = { 0 };
bool isGameEnd = false;
Obstacle obstacle[ObsN];

int main() {
    CursorView();

    while (!isGameEnd) {
        FirstScene();
        if (gogo == 1) {
            gogoOne();
        }
        else if (gogo == 2) {
            gogoTwo();

        }
        else if (gogo == 3) {
            gogoThree();
        }
    }
    system("pause");
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

//키보드의 입력을 받고, 입력된 키의 값을 반환하는 함수
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


    if (budVersion == 1) {
        gotoxy(budX, budY);
        printf("♣");
    }
    else if (budVersion == 2) {
        gotoxy(budX, budY);
        printf("■■ ■■");
        gotoxy(budX, budY + 1);
        printf(" ■■■");
        gotoxy(budX, budY + 2);
        printf("   ■");

    }
    else if (budVersion == 3) {
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
    else if (budVersion == 5) {
        gotoxy(budX, budY - 4);
        printf("   ■■■■■■\n");
        gotoxy(budX, budY - 3);
        printf("  ■         ■\n");
        gotoxy(budX, budY - 2);
        printf("  ■■■■■■■\n");
        gotoxy(budX, budY - 1);
        printf("        ■\n");
        gotoxy(budX, budY);
        printf("  ■■ ■■ ■■■■\n");
        gotoxy(budX, budY + 1);
        printf("■   ■■■■    ■  \n");
        gotoxy(budX, budY + 2);
        printf("  ■■  ■  ■■\n");
        gotoxy(budX, budY + 3);
        printf("        ■\n");
        gotoxy(budX, budY + 4);
        printf("        ■\n");

    }
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
    //if (budVersion > 3)
    //    //while (1)
    //        FinishGame();
    //printf("새싹 키우기 성공");
    gogo = 0;
    MarkOne();
    MarkTwo();
    MarkThree();
    DrawBud(x, y);
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
        return j = 1;
    }
    else if (isinTwo(x, y)) {
        gogo = 2;
        return j = 1;
    }
    else if (isinThree(x, y)) {
        gogo = 3;
        return j = 1;
    }
    else return j = 0;
    if (gogo == 1) {
        gogoOne();
        //gogo가 1,2,3일때로 이동
        //
    }
    else if (gogo == 2) {
        gogoTwo();

    }
    else if (gogo == 3) {
        gogoThree();
    }

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
    gogo = 0;
    srand(time(NULL));
    budVersionOne = budVersion;
    budVersion = 1;
    initKillerGame();
    do {
        CreateKiller();
        FallKiller();
        DelKiller();
        MoveBudOne();
        PrintKillerGame();
        runningTimeOne();
        DrawTimeOne();
        if (DamagedBud()) {
            if (budVersionOne == 1)
                budVersion = budVersionOne;
            else if (budVersionOne > 1)
                budVersion = budVersionOne - 1;
        }
        if (FinishGameOne()) {
            score[1] = 0;
            budVersion = budVersionOne;
            budVersion += 1;
            break;
        }
        Sleep(10);
    } while (!(DamagedBud()));
    system("cls");
    x = FirstX, y = FirstY;
    if (budVersion >= 4)
        FinishGame();
    return;
    /*while (true) {
        FirstScene();
        if (j)break;
    }*/
    /*if (gogo == 1) {
        gogoOne();
    }
    else if (gogo == 2) {
        gogoTwo();

    }
    else if (gogo == 3) {
        gogoThree();
    }*/
}
void gogoTwo() {
    gogo = 0;
    srand(time(NULL));
    budVersionTwo = budVersion;
    budVersion = 1;
    score[2] = 0;
    createwall();
    gotoxy(30, HEIGHT-1);
    createmaze(1, 1);
    gotoxy(30, HEIGHT);

    x = 1, y = 2;
    drawMaze();
    while (1) {
        DrawBud(x, y);
        int xOld = x;
        int yOld = y;
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
            gotoxy(xOld, yOld);
            printf("  ");
        }
        if (finishMaze(x, y)) {
            system("cls");
            x = FirstX, y = FirstY;
            budVersion = budVersionTwo + 1;
            break;
        }
        runningTimeTwo();
        DrawTimeTwo();
        if (score[2] == 40) {
            if (budVersionTwo == 1)
                budVersion = budVersionTwo;
            else if (budVersionTwo > 1)
                budVersion = budVersionTwo - 1;
            system("cls");
            break;
        }
        

    }
    x = FirstX, y = FirstY;
    if (budVersion >= 4)
        FinishGame();
    return;
    /*while (true) {
        FirstScene();
        if (j)break;
    }
    if (gogo == 1) {
        gogoOne();
    }
    else if (gogo == 2) {
        gogoTwo();

    }
    else if (gogo == 3) {
        gogoThree();
    }*/
}
void gogoThree() {
    budVersionThree = budVersion;
    budVersion = 3;
    x = 32;
    y = HEIGHT;

    bool isJumping = false;
    bool isBottom = true;
    const int gravity = 3;

    clock_t startthree, currthree;
    startthree = clock();

    initObstacle(y);
    while (1) {
        gotoxy(0, 0);

        if (isCollision()) {
            score[3] = 0;
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

        DrawBud(x, y - 4);
        //printf("%d", score[3]);
        if (score[3] < 5)
            moveObstacleOne();
        else if (5 <= score[3]&& score[3] < 15)
            moveObstacleTwo();
        else if (15 <= score[3]&& score[3] <= 25)
            moveObstacleThree();
        else if (score[3] > 25)
            break;
        Sleep(30);
        system("cls");

        if (y <= HEIGHT - 9)
            isJumping = false;

        runningTimeThree();
        DrawTimeThree();
    }
    if (score[3] >= 20) {
        system("cls");
        budVersion = budVersionThree + 1;
    }
    else {
        system("cls");
        if(budVersionThree==1)
            budVersion = budVersionThree;
        else if(budVersionThree > 1)
            budVersion = budVersionThree - 1;
    }
    if (budVersion == 5)
        FinishGame();
        //FirstScene();
    x = FirstX, y = FirstY;
    return;
   /* while (true) {
        FirstScene();
        if (j)break;
    }
    if (gogo == 1) {
        gogoOne();
    }
    else if (gogo == 2) {
        gogoTwo();

    }
    else if (gogo == 3) {
        gogoThree();
    }*/

}

void FinishGame() {
    system("cls");
    isGameEnd = true;
    budVersion = 5;
    DrawBud(x, y);
    gotoxy(26, 4);
    printf("＃＃＃＃＃＃＃＃＃＃");
    gotoxy(26, 5);
    printf("＃새싹 키우기 성공＃");
    gotoxy(26, 6);
    printf("＃＃＃＃＃＃＃＃＃＃");

    gotoxy(25, 10);
    printf("창을 종료하세요");
    return;
    //system("pause<null");
}