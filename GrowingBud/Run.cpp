#include "Run.h"
bool isJumping;
bool isBottom;

int startthree, currthree;
extern int score[4];
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
		printf("¡ã");
	}
}

bool isCollision() {

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
		printf("¡ã");
	}
}

void moveObstacleTwo() {
	for (int i = 0; i < ObsN; i++) {
		obstacle[i].x -= levelTwo;
		if (obstacle[i].x <= 0)
			obstacle[i].x = WIDTH;
		gotoxy(obstacle[i].x, obstacle[i].y);
		printf("¡ã");
	}
}
void moveObstacleThree() {
	for (int i = 0; i < ObsN; i++) {
		obstacle[i].x -= levelThree;
		if (obstacle[i].x <= 0)
			obstacle[i].x = WIDTH;
		gotoxy(obstacle[i].x, obstacle[i].y);
		printf("¡ã");
	}
}

void runningTimeThree() {
	currthree = clock();
	if ((currthree - startthree) / CLOCKS_PER_SEC >= 1) {
		score[3]++;
		startthree = clock();
	}
}

void DrawTimeThree() {
	gotoxy(WIDTH - 15, 1);
	printf("Time : %d/25", score[3]);
}

void DrawBug() {
	gotoxy(2, FirstY - 2);
	printf("¢Â¢Â¢Â¢Â");
	gotoxy(2, FirstY - 1);
	printf("¢Â¢Â¢Â¢Â");
	gotoxy(2, FirstY);
	printf("£ü£ü£ü£ü");
}

