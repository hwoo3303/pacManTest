#include<Windows.h>
#include<stdio.h>

#include "control.h"

void RemoveCursor();
void InitConsoleSize();

void initMenuDraw()
{
	InitConsoleSize();
	RemoveCursor();
}

void InitConsoleSize()
{
	system("mode con cols=150 lines=40");
}

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0; // bVisible 멤버 변경
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo); // 변경값 적용
}

int MoveArrow(char arrow, int idx_Y)
{
	switch (arrow)
	{
	case UP_KEY:
		if (idx_Y>25)
		{
			gotoxy(60, idx_Y);
			printf("  ");
			idx_Y -= 2;
			gotoxy(60, idx_Y);
			printf("▶");
		}
		else if(idx_Y == 25)
		{
			gotoxy(60, idx_Y);
			printf("  ");
			idx_Y += 6;
			gotoxy(60, idx_Y);
			printf("▶");
		}
		return idx_Y;

	case DOWN_KEY:
		if (idx_Y<31)
		{
			gotoxy(60, idx_Y);
			printf("  ");

			idx_Y += 2;
			gotoxy(60, idx_Y);
			printf("▶");
		}
		else if (idx_Y == 31)
		{
			gotoxy(60, idx_Y);
			printf("  ");

			idx_Y -= 6;
			gotoxy(60, idx_Y);
			printf("▶");
		}
		return idx_Y;
	}

	return idx_Y;
}

void updateMenu(int arrow)
{
	//printf("Pac-Man\n\n");
	if (arrow == 25) {
		gotoxy(60, 25);	
		printf("▶");	
		setcolor(0, 15);
	}
	gotoxy(70, 25);	printf("S T A R T\n");
	if (arrow == 25)
		setcolor(7, 0);
	if (arrow == 27) {
		gotoxy(60, 27);	printf("▶");	setcolor(0, 15);
	}
	gotoxy(71, 27);	printf("H E L P\n");
	if (arrow == 27)
		setcolor(7, 0);
	if (arrow == 29) {
		gotoxy(60, 29);	printf("▶");	setcolor(0, 15);
	}
	gotoxy(70, 29); printf("S C O R E\n");
	if (arrow == 29)
		setcolor(7, 0);
	if (arrow == 31) {
		gotoxy(60, 31);	printf("▶");	setcolor(0, 15);
	}
	gotoxy(71, 31); printf("E X I T\n\n");
	if (arrow == 31)
		setcolor(7, 0);
}