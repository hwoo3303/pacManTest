#pragma once

#include "PacmanEngine.h"

void InitDrawBitmap();
void DrawBitmap(HDC hDC, OBJECTSIZE *objSize, int arrX, int arrY, const int currentDir);
void freeDrawBitmap();