#include "AvoidKiller.h"

Killer killer[WIDTH];
Bud bud;
int startone, currone;
extern int score[3];

void MoveBudOne() {
    int c = 0;
    if (_kbhit()) {        //Ű���� �Է� Ȯ�� (true / false)
        c = _getch();// ����Ű �Է½� 224 00�� ������ �Ǳ⿡ �տ� �ִ� �� 224�� ����
        switch (c) {
        case LEFT:
            bud.x--;
            break;
        case RIGHT:
            bud.x++;
            break;
        }
        if (bud.x < 0)
            bud.x = 0;
        if (bud.x > WIDTH - 1)
            bud.x = WIDTH - 1;
    }
}

void initKillerGame(){
    for (int i = 0; i < WIDTH; i++)
        killer[i].con = FALSE;
    bud.x = WIDTH / 2;
}

void CreateKiller() {
    for (int i = 0; i < WIDTH; i++) {
        if (!killer[i].con) {
            killer[i].x = rand() % WIDTH;
            killer[i].y = HEIGHT - 1;
            killer[i].con = TRUE;
            return;
        }
    }
}

void FallKiller(){
    for (int i = 0; i < WIDTH; i++) {
        if (killer[i].con)
            killer[i].y--;
    }
}

void DelKiller() {
    for (int i = 0; i < WIDTH; i++) {
        if (killer[i].con && killer[i].y < 0)
            killer[i].con = FALSE;
    }
}

int DamagedBud() {
    for (int i = 0; i < WIDTH; i++) {
        //�� ����:TRUE&&����ġ �ٴ�&&�� x����ġ==�÷��̾� x����ġ
        if ((killer[i].con && killer[i].y == 0) && (killer[i].x == bud.x))
            return TRUE;
    }
    return FALSE;
}

void PrintKillerGame() {
    system("cls");
    for (int i = 0; i < WIDTH; i++) {
        if (killer[i].con) {
            gotoxy(killer[i].x, HEIGHT - killer[i].y);
            printf("��");
        }
    }
    DrawBud(bud.x, HEIGHT);
    gotoxy(0, HEIGHT + 1);
    for (int i = 0; i < WIDTH; i++)
        printf("��");
}

void runningTimeOne() {
    currone = clock();
    if ((currone - startone) / CLOCKS_PER_SEC >= 1) {
        score[1]++;
        startone = clock();
    }
}

void DrawTimeOne() {
    gotoxy(WIDTH - 15, 1);
    printf("Time : %d/20", score[1]);
}

bool FinishGameOne() {
    if (score[1] >= 20) {
        return true;
    }
    else return false;
}