#include <windows.h>
#include <stdio.h>
#include <conio.h>

#include "control.h"

typedef enum _CURRENTVIEW{
	INTRO,
	GAMEMAIN,
	HELP,
	RECORD,
	EXIT,
	MOVEPACMAN,
	MOVEGHOST
}CURRENTVIEW;

int wall[MAP_HEIGHT][MAP_WIDTH];			// 벽 공간 할당
int pacMan_x, pacMan_y;		// 팩맨 좌표
int ghost_x, ghost_y;		// 유령 좌표
int record = 0;				// 플레이어 점수 최대 10개로 제한
int item[3];
int menuCur = 25;			// 메뉴 커서 1번 위치로 초기화

HWND hWnd;
HDC hDC;
OBJECTSIZE objSize;

FILE *fp, *saveData;

#pragma region CommonFunction

void INTROFUNC(void *flagView);
void GAMEMAINFUNC(void *flagView);
void HELPFUNC(void *flagView);
void RECORDFUNC(void *flagView);
void EXITFUNC(void *flagView);
void MOVEPACMANFUNC(void *thrID);
void MOVEGHOSTFUNC(void *thrID);

#pragma endregion

static FUNCPTR pFunc[] = { INTROFUNC, GAMEMAINFUNC, HELPFUNC, RECORDFUNC, EXITFUNC,  MOVEPACMANFUNC, MOVEGHOSTFUNC};

void Controller()
{
	CURRENTVIEW curView = INTRO;

	hWnd = GetConsoleWindow();
	hDC = GetDC(hWnd);

	objSize.width = 20;
	objSize.height = 20;

	while (1)
	{
		switch (curView)
		{
		case INTRO:
			pFunc[INTRO]( (void *)(&curView) );
			break;
		case GAMEMAIN:
			pFunc[GAMEMAIN]( (void *)(&curView) );
			break;
		case HELP:
			pFunc[HELP]( (void *)(&curView) );
			break;
		case RECORD:
			pFunc[RECORD]( (void *)(&curView) );
			break;
		case EXIT:
			pFunc[EXIT]( (void *)(&curView) );
			return;
		}
	}
}

//void menuController()
//{
//	int cur;
//	RemoveCursor();		// 콘솔창 커서 제거함수
//	initMenu();
//	while (1)
//	{
//		menuSelect();
//		
//		switch (menuCur)
//		{
//		case 1:
//			gameCreate();
//			gameStart();
//			break;
//		case 2:
//			help();
//			break;
//		case 3:
//			recordRank();
//			break;
//		case 4:
//			exit(1);
//		}
//		updateMenu();
//	}
//}

CURRENTVIEW menuSelect(int arrow)
{
	char sel;

	fflush(stdin);

	while (1)
	{
		if (!(_kbhit()))
			continue;
		
		sel = _getch();

		if(sel == ENTER)
		{
			switch (arrow)
			{
			case 25:
				return GAMEMAIN;
			case 27:
				return HELP;
			case 29:
				return RECORD;
			case 31:
				return EXIT;
			}
		}

		arrow = MoveArrow(sel, arrow);
		updateMenu(arrow);


		/*system("cls");

		updateMenu();*/
	}
}

CURRENTVIEW mSelectHelp()
{
	char input;

	fflush(stdin);

	while (1)
	{
		input = _getch();
		if (input == ENTER)
		{
			system("cls");
			return INTRO;
		}
	}
}

CURRENTVIEW mSelectRecord()
{
	char input;

	fflush(stdin);

	gotoxy(55, 32);
	printf("이전메뉴 돌아가기 : ENTER KEY");
	while (1)
	{
		input = _getch();
		if (input == ENTER)
		{
			system("cls");
			return INTRO;
		}
	}
}

CURRENTVIEW mSelectPlayGame()
{
	/*
	Temp Function for test
	*/
	char input;

	fflush(stdin);

	while (1)
	{
		input = _getch();
		if (input == ENTER)
		{
			system("cls");
			return INTRO;
		}
	}
}

void gotoxy(int idx_X, int idx_Y)
{
	COORD Pos;
	Pos.X = idx_X;
	Pos.Y = idx_Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void setcolor(int color, int bgcolor)
{
	color &= 0xf;
	bgcolor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void INTROFUNC(void *flagView)
{
	//Init intro view
	//call menu controller for intro view
	
	CURRENTVIEW *fView = (CURRENTVIEW *)flagView;

	initMenuDraw();
	updateMenu(menuCur);
	*fView = menuSelect(menuCur);
}

void GAMEMAINFUNC(void *flagView)
{
	//Init Game main view
	//call key event controller for main view
	CURRENTVIEW *fView = (CURRENTVIEW *)flagView;

	InitPlayGame();
	InitDrawMap(hDC, &objSize);
	InitDrawBitmap();
	DrawBitmap(hDC, &objSize, pacMan_x, pacMan_y, RIGHT_KEY);

	//create thread
	pFunc[MOVEPACMAN](flagView);
	//create thread

	recordLoad();

	//create thread
	//pFunc[MOVEGHOST];
	//create thread

	/**fView = mSelectPlayGame();
	menuCur = 25;*/
}

void HELPFUNC(void *flagView)
{
	//Init Help view
	//call key event controller for help view
	CURRENTVIEW *fView = (CURRENTVIEW *)flagView;
	
	help();
	*fView = mSelectHelp();
	menuCur = 27;
}

void RECORDFUNC(void *flagView)
{
	//Init Help view
	//call key event controller for record view
	CURRENTVIEW *fView = (CURRENTVIEW *)flagView;

	recordRank();
	*fView = mSelectRecord();
	menuCur = 29;
}

void EXITFUNC(void *flagView)
{
	//process destroy function for each
	//ex) free allocated mem, delete object, handle
	freeDrawMap(&objSize);
	freeDrawBitmap();
	ReleaseDC(hWnd, hDC);
}

void MOVEPACMANFUNC(void *flagView)
{
	//movePacman function call
	CURRENTVIEW *fView = (CURRENTVIEW *)flagView;

	movePacMan();

	system("cls");

	*fView = INTRO;
	menuCur = 25;
}

void MOVEGHOSTFUNC(void *thrID)
{
	//moveGhost function call
}