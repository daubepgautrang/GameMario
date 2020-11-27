#include "GameMap.h"

GameMap::GameMap()
{
}

GameMap::GameMap(int width, int height, int tilewidth, int tileheight)
{
	this->width = width;
	this->height = height;
	this->tilewidth = tilewidth;
	this->tileheight = tileheight;
}
