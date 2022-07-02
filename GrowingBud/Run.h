#pragma once
#include "main.h"
#include <time.h>
#define ObsN 2
struct Obstacle {
	int x;
	int y;
};

void initRunGame();
void initObstacle(int budY);
bool isCollision();
void moveObstacle();
void runningScore();
void DrawScore();