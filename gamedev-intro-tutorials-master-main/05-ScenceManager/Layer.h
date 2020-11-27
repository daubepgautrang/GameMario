#pragma once
#include "Utils.h"
#include "TinyXML/tinyxml.h"
#include "TinyXML/tinystr.h"

class CTilemap;

class CLayer
{
	int id;
	int visible;
	int width;
	int height;

	int** tiles;
public:
	CLayer();
	CLayer(TiXmlElement* data);

	bool Hidden = false;
	int GetTileID(int x, int y);

	~CLayer();
};

typedef shared_ptr<CLayer> Layer;
