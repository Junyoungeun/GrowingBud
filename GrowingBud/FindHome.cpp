#include "FindHome.h"

const int N = HEIGHT + 1;
const int M = HEIGHT + 1;


int d[4][2] = { -2, 0, 0, 2, 2, 0, 0, -2 };
int locationN[N], locationM[M];
int maze[N][M];


void createwall() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i % 2 == 1 && j % 2 == 1)continue;
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
                gotoxy(i + 1, j + 1);
                printf("¢Ì");
            }
            else {
                gotoxy(i + 1, j + 1);
                printf(" ");
            }
            gotoxy(N - 1, M - 1);
            printf("O"); //¸ñÀûÁö
        }
    }
}