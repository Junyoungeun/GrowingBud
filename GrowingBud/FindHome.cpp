#include "FindHome.h"

int starttwo, currtwo;
extern int score[4];
//const int N = HEIGHT + 1;
//const int M = HEIGHT + 1;
const int N = 7;
const int M = 7;



int d[4][2] = { -2, 0, 0, 2, 2, 0, 0, -2 };
int locationN[N], locationM[M];
int maze[N][M];


void createwall() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i % 2 == 1 && j % 2 == 1) maze[i][j] = 0;
            else maze[i][j] = 1;
        }
    }

}

void createmaze(int x, int y) {
    maze[x][y] = -1;
    int i = rand() % 4;
    for (int j = 0; j < 4; j++, i++) {
        i %= 4;
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        if (0 < dx && dx < N && 0 < dy && dy < M && maze[dx][dy] == 0) {
            maze[(x + dx) / 2][(y + dy) / 2] = 0;
            createmaze(dx, dy);
        }
    }
}

void drawMaze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == 1) {
                gotoxy(i , j + 1);
                printf("¢Ì");
                //¢Ì,¢Æ
            }
            else {
                gotoxy(i + 1, j + 1);
                printf(" ");
            }
            gotoxy(N - 2, M - 1);
            printf("¡Ú"); //¸ñÀûÁö
        }
    }
}

bool ismoveable(int x, int y) {
    if (maze[x][y-1] == 1)return false;
    else return true;
}

bool finishMaze(int x, int y) {
    if (x == N - 2 && y == M - 1)
        return true;
    else return false;
}

void runningTimeTwo() {
    currtwo = clock();
    if ((currtwo - starttwo) / CLOCKS_PER_SEC >= 1) {
        score[2]++;
        starttwo = clock();
    }
}

void DrawTimeTwo() {
    gotoxy(WIDTH - 15, 1);
    printf("Time : %d/40", score[2]);
    //printf("Time : %d", 21 - score[2]);
}
