#include "Layer.h"
#include "Tilemap.h"

CLayer::CLayer()
{
	this->id = 0;
	this->width = 1;
	this->height = 1;
	this->visible = 1;
}

CLayer::CLayer(TiXmlElement* data)
{
	data->QueryIntAttribute("id", &this->id);
	data->QueryIntAttribute("width", &this->width);
	data->QueryIntAttribute("height", &this->height);
	data->QueryIntAttribute("visible", &this->visible);

	tiles = new int* [this->width];

	const char* content = data->FirstChildElement()->GetText();
	vector<string> splitted = split(content, ",");

	for (int i = 0; i < this->width; i++) {
		tiles[i] = new int[height];
		for (int j = 0; j < this->height; j++) {
			int tileId = stoi(splitted[i + j * width]);
			tiles[i][j] = tileId;
		}
	}

	splitted.clear();
}


int CLayer::GetTileID(int x, int y)
{
	if (!visible) return 0;
	if (x < 0 || x >= width) return 0;
	if (y < 0 || y >= width) return 0;
	return tiles[x][y];
}

CLayer::~CLayer()
{
	for (int i = 0; i < width; i++) {
		delete[] tiles[i];
	}
	delete[] tiles;
}