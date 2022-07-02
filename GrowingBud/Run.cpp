#include "Run.h"
bool isJumping;
bool isBottom;

int start, curr, score;
extern int x, y;
extern Obstacle obstacle[ObsN];


void initRunGame() {
	bool isJumping = false;
	bool isBottom = true;

}

void initObstacle(int budY) {
	int ObsX = WIDTH -8;
	for (int i = 0; i < ObsN; i++) {
		obstacle[i].x = ObsX;
		obstacle[i].y = budY;
		ObsX += 12;
		gotoxy(obstacle[i].x, obstacle[i].y);
		printf("бу");
	}
}

bool isCollision() {
	gotoxy(0, 0);
	printf("X %d, Y %d\n", x, y);
	printf("ObstacleX %d, ObstacleY %d\n", obstacle[0].x, obstacle[0].y);
	printf("ObstacleX %d, ObstacleY %d\n", obstacle[1].x, obstacle[1].y);

	for (int i = 0; i < ObsN; i++) {
		if (obstacle[i].x ==36&& y ==obstacle[i].y) {
			return true;
		}
	}
	return false;
}
//36-2<=obstacle[i].x &&obstacle[i].x <= 36+2 

void moveObstacle() {
	for (int i = 0; i < ObsN; i++) {
		obstacle[i].x -= 4;
		if (obstacle[i].x <= 0)
			obstacle[i].x = WIDTH;
		gotoxy(obstacle[i].x, obstacle[i].y);
		printf("бу");
	}

}

void runningScore() {
	curr = clock();
	if ((curr - start) / CLOCKS_PER_SEC >= 1) {
		score++;
		start = clock();
	}
}

void DrawScore() {
	gotoxy(WIDTH - 15, 1);
	printf("Score : %d", score);
}

