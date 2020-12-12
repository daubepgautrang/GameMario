///#pragma once
#include"Sprites.h"
#include"Textures.h"
#include"Utils.h"
#include "Camera.h"
#include "Layer.h"
#include "Game.h"

class CTilemap
{
	CSpriteDatabase* sprites = CSpriteDatabase::GetInstance();

	string id;
	int width, height;
	int tilewidth, tileheight;

	int firstgid = 1;

	int columns;
	string tilesetTextureId;

	vector<shared_ptr<CLayer>> layers;
public:
	~CTilemap();
	CTilemap(string path, string name);
	virtual void Render();
	void Draw(int gid, float x, float y);
	void AddLayer(Layer layer);
};

typedef CTilemap* Tilemap;
