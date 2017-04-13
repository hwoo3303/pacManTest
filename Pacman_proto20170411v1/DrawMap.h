#pragma once

#include "PacmanEngine.h"

//void LoadCursorMap();
void ConvertToPixelMap(int _pixLeft, int _pixTop, OBJECTSIZE *objSize);
void DrawBackground(HDC hDC, int _pixX, int _pixY);
void DrawMap(HDC hDC, OBJECTSIZE *objSize);
void InitDrawMap(HDC hDC, OBJECTSIZE *objSize);
void freeDrawMap(OBJECTSIZE *objSize);
const RECT* GetPixelMapArea();