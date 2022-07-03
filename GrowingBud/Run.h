#pragma once
#include "main.h"
#include <time.h>
#define ObsN 2
#define levelOne 1
#define levelTwo 2
#define levelThree 4

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
void runningTimeThree();
void DrawTimeThree();
void DrawBug();