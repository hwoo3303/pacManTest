#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "init.h"
#include "ghost.h"
#include "imageProcessing.h"
#include "packMan.h"
#include "playGame.h"
#include "recordData.h"
#include "GameIntro.h"
#include "PacmanEngine.h"
#include "DrawMap.h"
#include "DrawBitmap.h"

#include "resource.h"

#define UP_KEY		72
#define DOWN_KEY	80
#define LEFT_KEY	75
#define RIGHT_KEY	77
#define ENTER		13

typedef void(*FUNCPTR)(void *);

void Controller();
//void menuController();			// 컨트롤러 함수
//void menuSelect();
void gotoxy(int idx_X, int idx_Y);
void setcolor(int color, int bgcolor);

#endif