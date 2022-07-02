#include "Run.h"
bool isJumping;
bool isBottom;

int startthree, currthree;
extern int score[3];
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
		printf("��");
	}
}

bool isCollision() {
	gotoxy(0, 0);
	/*printf("X %d, Y %d\n", x, y);
	printf("ObstacleX %d, ObstacleY %d\n", obstacle[0].x, obstacle[0].y);
	printf("ObstacleX %d, ObstacleY %d\n", obstacle[1].x, obstacle[1].y);*/

	for (int i = 0; i < ObsN; i++) {
		if (obstacle[i].x ==36&& y ==obstacle[i].y) {
			return true;
		}
	}
	return false;
}

void moveObstacleOne() {
	for (int i = 0; i < ObsN; i++) {
		obstacle[i].x -= levelOne;
		if (obstacle[i].x <= 0)
			obstacle[i].x = WIDTH;
		gotoxy(obstacle[i].x, obstacle[i].y);
		printf("��");
	}
}

void moveObstacleTwo() {
	for (int i = 0; i < ObsN; i++) {
		obstacle[i].x -= levelTwo;
		if (obstacle[i].x <= 0)
			obstacle[i].x = WIDTH;
		gotoxy(obstacle[i].x, obstacle[i].y);
		printf("��");
	}
}
void moveObstacleThree() {
	for (int i = 0; i < ObsN; i++) {
		obstacle[i].x -= levelThree;
		if (obstacle[i].x <= 0)
			obstacle[i].x = WIDTH;
		gotoxy(obstacle[i].x, obstacle[i].y);
		printf("��");
	}
}

void runningScoreThree() {
	currthree = clock();
	if ((currthree - startthree) / CLOCKS_PER_SEC >= 1) {
		score[3]++;
		startthree = clock();
	}
}

void DrawScoreThree() {
	gotoxy(WIDTH - 15, 1);
	printf("Score : %d", score[3]);
}

