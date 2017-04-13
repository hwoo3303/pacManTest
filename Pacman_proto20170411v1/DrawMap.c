#include<stdio.h>
#include<stdlib.h>

#include "PacmanEngine.h"

RECT PixelMapArea;

TILE **Tile;

extern int wall[MAP_HEIGHT][MAP_WIDTH];

const RECT* GetPixelMapArea()
{
	return &PixelMapArea;
}

//void Loadwall()
//{
//	FILE *fp;
//	int i, j;
//
//	if (fopen_s(&fp, "PacmanMap.txt", "rt"))
//	{
//		printf("File Open Fail...");
//		fclose(fp);
//		return;
//	}
//
//	for (i = 0; i < MAP_HEIGHT; i++)
//		for (j = 0; j < MAP_WIDTH; j++)
//			fscanf_s(fp, "%d", &wall[i][j]);
//
//	fclose(fp);
//}

void ConvertToPixelMap(int _pixLeft, int _pixTop, OBJECTSIZE *objSize)
{
	int i, j;
	int ci, cj;

	PixelMapArea.left = _pixLeft;
	PixelMapArea.top = _pixTop;

	PixelMapArea.right = _pixLeft + MAP_WIDTH * objSize->width;
	PixelMapArea.bottom = _pixTop + MAP_HEIGHT * objSize->height;

	Tile = (TILE **)malloc(sizeof(TILE) * (PixelMapArea.bottom - PixelMapArea.top));

	for (i = 0; i < PixelMapArea.bottom - PixelMapArea.top; i += objSize->height)
	{
		Tile[i] = (TILE *)malloc(sizeof(TILE) * (PixelMapArea.right - PixelMapArea.left));
		ci = i / objSize->height;
		for (j = 0; j < PixelMapArea.right - PixelMapArea.left; j += objSize->width)
		{
			cj = j / objSize->width;
			
			switch (wall[ci][cj])
			{
			case -1:
				Tile[i][j].hbrTile = CreateSolidBrush(RGB(0xB2, 0x23, 0x23));
				Tile[i][j].hpnTile = CreatePen(PS_DOT, 1, RGB(0xB2, 0x23, 0x23));
				break;
			case 0:
				Tile[i][j].hbrTile = CreateSolidBrush(RGB(0x00, 0x00, 0x00));
				Tile[i][j].hpnTile = CreatePen(PS_SOLID, 1, RGB(0x00, 0x00, 0x00));
				break;
			}

			Tile[i][j].area.left = j + PixelMapArea.left;
			Tile[i][j].area.top = i + PixelMapArea.top;
			Tile[i][j].area.right = Tile[i][j].area.left + objSize->width;
			Tile[i][j].area.bottom = Tile[i][j].area.top + objSize->height;
		}
	}
}

void DrawBackground(HDC hDC, int _pixX, int _pixY)
{
	SelectObject(hDC, Tile[_pixY][_pixX].hbrTile);
	SelectObject(hDC, Tile[_pixY][_pixX].hpnTile);

	Rectangle(hDC,
		Tile[_pixY][_pixX].area.left,
		Tile[_pixY][_pixX].area.top,
		Tile[_pixY][_pixX].area.right,
		Tile[_pixY][_pixX].area.bottom);
}

void DrawMap(HDC hDC, OBJECTSIZE *objSize)
{
	int i, j;

	for (i = 0; i < PixelMapArea.bottom - PixelMapArea.top; i += objSize->height)
	{
		for (j = 0; j < PixelMapArea.right - PixelMapArea.left; j += objSize->width)
		{
			SelectObject(hDC, Tile[i][j].hbrTile);
			SelectObject(hDC, Tile[i][j].hpnTile);

			Rectangle(hDC,
				Tile[i][j].area.left,
				Tile[i][j].area.top,
				Tile[i][j].area.right,
				Tile[i][j].area.bottom
			);
		}
	}
}

void InitDrawMap(HDC hDC, OBJECTSIZE *objSize)
{
	ConvertToPixelMap(13, 174, objSize);
	DrawMap(hDC, objSize);
}

void freeDrawMap(OBJECTSIZE *objSize)
{
	int i, j;

	for (i = 0; i < PixelMapArea.bottom - PixelMapArea.top; i += objSize->height)
	{
		for (j = 0; j < PixelMapArea.right - PixelMapArea.left; j += objSize->width)
		{
			DeleteObject(Tile[i][j].hbrTile);
			DeleteObject(Tile[i][j].hpnTile);
		}
		free(Tile[i]);
	}
}