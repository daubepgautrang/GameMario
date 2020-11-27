#pragma once


class GameMap
{
	int width;
	int height;
	int tilewidth;
	int tileheight;

public:
	GameMap();
	GameMap(int width, int height, int tilewidth, int tileheight);

};

typedef GameMap* CGameMap;
