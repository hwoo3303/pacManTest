#pragma warning(disable: 4996)

#include<Windows.h>
#include<stdio.h>

#include "control.h"

extern int wall[MAP_HEIGHT][MAP_WIDTH];
extern FILE *fp;
extern int record;
extern int pacMan_x, pacMan_y;

#pragma region playGameINIT

void pinkBlock()
{
	/*------------ºÐÈ«»öÄ­-----------*/
	int i = 0;
	setcolor(13, 0);
	gotoxy(110, 0);
	printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤");

	gotoxy(110, 38);
	printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥");

	for (i = 0; i<37; i++) { // ?! ¼ýÀÚ..

		gotoxy(110, 1 + i);
		printf("¦¢");
		gotoxy(148, 1 + i);
		printf("¦¢");
	}

}
void pinkBlockMenu()
{
	/*-------- -ºÐÈ«»öÄ­ ¾È ¸Þ´º-----------*/
	int i = 0;
	setcolor(15, 0);
	gotoxy(120, 16);
	printf("SCORE : ");
	gotoxy(120, 18);
	printf("NEXT ITEM : ");
	gotoxy(120, 20);
	printf("NEXT GHOST : %d sec", i); // 5-4-3-2-1?
	gotoxy(125, 24);
	printf("[ CONTROL ]");
	gotoxy(120, 26);
	printf("¡è : UP");
	gotoxy(120, 28);
	printf("¡é : DOWN");
	gotoxy(120, 30);
	printf("¡ç : LEFT");
	gotoxy(120, 32);
	printf("¡æ : RIGHT");
}

void Danger(int x, int y)
{
	/*------------DANGER-----------*/
	int i = 0;
	setcolor(x, y);
	gotoxy(22, 2);
	printf("¡á¡á¡á        ¡á      ¡á      ¡á    ¡á¡á¡á  ¡á¡á¡á¡á  ¡á¡á¡á¡á\n");
	gotoxy(22, 3);
	printf("¡á    ¡á    ¡á  ¡á    ¡á¡á    ¡á  ¡á        ¡á        ¡á    ¡á\n");
	gotoxy(22, 4);
	printf("¡á    ¡á  ¡á¡á¡á¡á¡á  ¡á  ¡á  ¡á  ¡á  ¡á¡á  ¡á¡á¡á¡á  ¡á¡á¡á       \n");
	gotoxy(22, 5);
	printf("¡á    ¡á  ¡á      ¡á  ¡á    ¡á¡á  ¡á    ¡á  ¡á        ¡á    ¡á\n");
	gotoxy(22, 6);
	printf("¡á¡á¡á    ¡á      ¡á  ¡á      ¡á    ¡á¡á¡á  ¡á¡á¡á¡á  ¡á    ¡á\n");
}
void DangerSec()
{
	int i = 0;
	for (i = 0; i<5; i++) {
		Danger(4, 0);
		Sleep(100);
		Danger(9, 0);
		Sleep(100);
		Danger(10, 0);
		Sleep(100);
	}

}
void Pacman()
{
	/*------------DANGER-----------*/
	int i = 0;
	setcolor(0, 14);
	gotoxy(126, 4);
	printf("         ");
	gotoxy(124, 5);
	printf("             ");
	gotoxy(122, 6);
	printf("    ¡á     ¡á    ");
	gotoxy(121, 7);
	printf("     ¡á     ¡á     ");
	gotoxy(121, 8);
	printf("                   ");
	setcolor(12, 14);
	gotoxy(121, 9);
	printf("     P       N     ");
	gotoxy(122, 10);
	printf("     A C M A     ");
	gotoxy(124, 11);
	printf("             ");
	gotoxy(126, 12);
	printf("         ");
}

#pragma endregion

void InitPlayGame()
{
	system("cls");

	Pacman();
	pinkBlock();
	pinkBlockMenu();
	DangerSec();
	gameCreate();
}

void gameCreate() 
{
	record = 0;
	pacMan_x = 21, pacMan_y = 20;
	int i, j;
	// ¸Þ´º¿¡¼­ start ´­·¶À»½Ã »ý¼ººÎ
	/*fp = fopen("array.txt", "r");*/

	if (fopen_s(&fp, "PacmanMap.txt", "r"))
		return;

	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			fscanf(fp, "%d", &wall[i][j]);
		}
	}

	/*system("cls");
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			if (wall[i][j] == -1) 
			{
				printf("1");
			}
			else if (wall[i][j] == 0)
			{
				printf("*");
			}
			else if (wall[i][j] == 2)
			{
				printf("@");
			}
		}printf("\n");
	}*/
}

void inputKey()
{

}

void itemCreate() 
{

}

void objectAction() 
{

}

void gameStart()
{
	printPacMan();
	movePacMan();
	recordLoad();
}