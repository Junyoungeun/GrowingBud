#include "Run.h"
bool isJumping;
bool isBottom;
const int gravity = 3;
int ObstacleX=WIDTH, ObstacleY=HEIGHT;
int start, curr, score;

void initRunGame() {
	bool isJumping = false;
	bool isBottom = true;

}

void budJump(int x, int y) {
	if (GetKeyDown() == SPACE && isBottom) {
		isJumping = true;
		isBottom = false;
	}
	if (isJumping)
		y -= gravity;
	else
		y += gravity;
	
	if (y >= HEIGHT) {
		y = HEIGHT;
		isBottom = true;
	}
	if (y <= 3)
		isJumping = false;
}

void initObstacle() {
	gotoxy(ObstacleX, ObstacleY);
	printf("бс");
	gotoxy(ObstacleX, ObstacleY-1);
	printf("бу");
}

bool isCollision(const int ObstacleX, const int budY, int x) {
	gotoxy(0, 0);
	printf("ObstacleX: %d, budY: %d", ObstacleX, budY);
	if (x - 2 <= ObstacleX && ObstacleX <= x + 2 && budY > ObstacleY - 1)
		return true;
	return false;


}

void moveObstacle() {
	ObstacleX -= 2;
	if (ObstacleX <= 0)
		ObstacleX = WIDTH;

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

