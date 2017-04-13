#pragma once

#include<Windows.h>

#include "resource.h"

//#define MAP_WIDTH	 90
//#define MAP_HEIGHT	 28

#define MAP_WIDTH	 43
#define MAP_HEIGHT	 22

typedef struct _Tile
{
	HBRUSH hbrTile;
	HPEN hpnTile;
	RECT area;
}TILE;

typedef struct _ObjectSize
{
	LONG width;
	LONG height;
}OBJECTSIZE;