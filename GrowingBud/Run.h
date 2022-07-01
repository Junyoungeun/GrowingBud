#pragma once
#include "main.h"
#include <time.h>

void initRunGame();
void budJump(int x, int y);
void initObstacle();
bool isCollision(const int ObstacleX, const int budY, int x);
void moveObstacle();
void runningScore();
void DrawScore();