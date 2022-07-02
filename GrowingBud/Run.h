#pragma once
#include "main.h"
#include <time.h>
#define ObsN 2
#define levelOne 2
#define levelTwo 4
#define levelThree 12

struct Obstacle {
	int x;
	int y;
};

void initRunGame();
void initObstacle(int budY);
bool isCollision();
void moveObstacleOne();
void moveObstacleTwo();
void moveObstacleThree();
void runningScoreThree();
void DrawScoreThree();