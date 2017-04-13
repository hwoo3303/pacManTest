#include<stdio.h>
#include<conio.h>
#include<Windows.h>

#include "control.h"

extern int pacMan_x, pacMan_y;		// ÆÑ¸Ç ÁÂÇ¥
extern int wall[MAP_HEIGHT][MAP_WIDTH];			// º® ¹è¿­
extern int record[10];

extern HDC hDC;
extern OBJECTSIZE objSize;

void printPacMan() 
{
	gotoxy(pacMan_x, pacMan_y);
	printf("a");
}

void curUpdate()
{
	gotoxy(pacMan_x, pacMan_y);
	printf(" ");
}

void movePacMan()
{
	char direction;
	int recordLoc = 30;

	fflush(stdin);

	while (1)
	{
		if (!(_kbhit()))
			continue;

		direction = _getch();
		if (direction == UP_KEY)
		{
			while (wall[pacMan_y - 1][pacMan_x] != -1)
			{
				//curUpdate();
				pacMan_y--;

				//printPacMan();
				
				Sleep(200);
				if (wall[pacMan_y][pacMan_x] == 0)
				{
					recordRenew();
				}

				DrawMap(hDC, &objSize);
				DrawBitmap(hDC, &objSize, pacMan_x, pacMan_y, direction);

				if (_kbhit())
				{
					break;
				}
			}
		}
		else if (direction == DOWN_KEY)
		{
			while (wall[pacMan_y + 1][pacMan_x] != -1)
			{
				//curUpdate();
				pacMan_y++;
				
				//printPacMan();

				Sleep(200);
				if (wall[pacMan_y][pacMan_x] == 0)
				{
					recordRenew();
				}

				else if (wall[pacMan_y][pacMan_x] == 2)
				{
					actionPacMan();
				}

				DrawMap(hDC, &objSize);
				DrawBitmap(hDC, &objSize, pacMan_x, pacMan_y, direction);

				if (_kbhit())
				{
					break;
				}
			}
		}
		else if (direction == LEFT_KEY)
		{
			while (wall[pacMan_y][pacMan_x - 1] != -1)
			{
				//curUpdate();
				pacMan_x--;

				//printPacMan();

				Sleep(200);
				if (wall[pacMan_y][pacMan_x] == 0)
				{
					recordRenew();
				}

				DrawMap(hDC, &objSize);
				DrawBitmap(hDC, &objSize, pacMan_x, pacMan_y, direction);

				if (_kbhit())
				{
					break;
				}
			}
		}
		else if (direction == RIGHT_KEY)
		{
			while (wall[pacMan_y][pacMan_x + 1] != -1)
			{
				//curUpdate();
				pacMan_x++;

				//printPacMan();

				Sleep(200);
				if (wall[pacMan_y][pacMan_x] == 0)
				{
					recordRenew();
				}
				else if (wall[pacMan_y][pacMan_x] == 2)
				{
					actionPacMan();
				}

				DrawMap(hDC, &objSize);
				DrawBitmap(hDC, &objSize, pacMan_x, pacMan_y, direction);

				if (_kbhit())
				{
					break;
				}
			}
		}
		if (direction == 'a')
		{
			break;
		}
		/*if (wall[pacMan_y][pacMan_x] == 0)
		{
			actionPacMan();
			gotoxy(130, 10);
			printf("%d", record[0]);
			gotoxy(pacMan_x, pacMan_y);
		}*/
		//printPacMan();
	}
}

void deadPacMan() 
{

}

void actionPacMan() 
{
	/*setcolor(10, 0);
	printPacMan();*/
	
}