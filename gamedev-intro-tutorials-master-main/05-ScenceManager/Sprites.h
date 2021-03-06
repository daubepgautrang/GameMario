#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <unordered_map>
#include "Textures.h"

using namespace std;

class CSprite
{
	string id;				// Sprite ID in the sprite database

	int left; 
	int top;
	int right;
	int bottom;

	LPDIRECT3DTEXTURE9 texture;
public: 
	CSprite(string id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);

	void Draw(int direction, float x, float y, int alpha = 255);
};

typedef CSprite * LPSPRITE;

/*
	Manage sprite database
*/
class CSpriteDatabase
{
	static CSpriteDatabase * __instance;

	unordered_map<string, LPSPRITE> sprites;

public:
	void Add(string id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex);
	LPSPRITE Get(string id);
	void CSpriteDatabase::Clear();
	void ImportSpriteFromXml(string textureId, string SpritePath);
	static CSpriteDatabase * GetInstance();
};



