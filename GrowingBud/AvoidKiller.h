#pragma once
#include "main.h"

typedef struct {
	int x;
	int y;
	//������ ����(TRUE, FALSE)�� ��Ʈ��
	int con;
}Killer;

typedef struct {
	int x;
}Bud;

void MoveBudOne();
void initKillerGame();
void CreateKiller();
void FallKiller();
void DelKiller();
int DamagedBud();
void PrintKillerGame();
void runningTimeOne();
void DrawTimeOne();
bool FinishGameOne();