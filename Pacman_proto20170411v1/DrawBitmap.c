#include<Windows.h>

#include "control.h"

typedef struct _bmpPacman
{
	HBITMAP hbmpPacman;
	BITMAP bmpPacman;
}BMPPACMAN;

static BMPPACMAN bmpPacman;

void DrawBitmap(HDC hDC, OBJECTSIZE *objSize, int arrX, int arrY, const char currentDir)
{
	const RECT *pixMapArea;
	int picX, picY;
	HDC hMemDC;

	hMemDC = CreateCompatibleDC(hDC);

	//switch(currentDir) - case select to pacman image
	SelectObject(hMemDC, bmpPacman.hbmpPacman);
	//switch(currentDir) - case select to pacman image

	pixMapArea = GetPixelMapArea();

	picX = pixMapArea->left + arrX * objSize->width;
	picY = pixMapArea->top + arrY * objSize->height;

	StretchBlt(hDC, picX, picY, objSize->width, objSize->height, hMemDC, 0, 0, bmpPacman.bmpPacman.bmWidth, bmpPacman.bmpPacman.bmHeight, SRCCOPY);

	DeleteDC(hMemDC);
}

void InitDrawBitmap()
{
	HINSTANCE hInstance;

	hInstance = GetModuleHandle(NULL);

	bmpPacman.hbmpPacman = LoadBitmap(hInstance, MAKEINTRESOURCE(PACMAN));
	
	GetObject(bmpPacman.hbmpPacman, sizeof(BITMAP), &bmpPacman.bmpPacman);
}

void freeDrawBitmap()
{
	DeleteObject(bmpPacman.hbmpPacman);
}