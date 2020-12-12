#include "Sprites.h"
#include "Game.h"
#include "Utils.h"
#include "Textures.h"

CSprite::CSprite(string id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = tex;
}

CSpriteDatabase * CSpriteDatabase::__instance = NULL;

CSpriteDatabase *CSpriteDatabase::GetInstance()
{
	if (__instance == NULL) __instance = new CSpriteDatabase();
	return __instance;
}

void CSprite::Draw(int direction,float x, float y, int alpha)
{
	CGame * game = CGame::GetInstance();
   	game->Draw(direction, x, y, texture, left, top, right, bottom, alpha);
}

void CSpriteDatabase::Add(string id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	LPSPRITE s = new CSprite(id, left, top, right, bottom, tex);
	sprites[id] = s;

	DebugOut(L"[INFO] sprite added: %d, %d, %d, %d, %d \n", id, left, top, right, bottom);
}

LPSPRITE CSpriteDatabase::Get(string id)
{
	return sprites[id];
}

/*
	Clear all loaded textures
*/
void CSpriteDatabase::Clear()
{
	for (auto x : sprites)
	{
		LPSPRITE s = x.second;
		delete s;
	}

	sprites.clear();
}

void CSpriteDatabase::ImportSpriteFromXml(string textureId, string spritePath)
{
	TiXmlDocument XMLdoc(spritePath.c_str());

	if (XMLdoc.LoadFile())
	{
		TiXmlElement* root = XMLdoc.RootElement();
		for (TiXmlElement* XMLtexture = root->FirstChildElement("Textures"); XMLtexture != NULL; XMLtexture = XMLtexture->NextSiblingElement("Textures"))
		{
			for (TiXmlElement* XMLsprite = XMLtexture->FirstChildElement("Sprite"); XMLsprite != NULL; XMLsprite = XMLsprite->NextSiblingElement("Sprite"))
			{
				int left, top, width, height;
				int xPivot, yPivot = 0;
				std::string id = XMLsprite->Attribute("id");
				XMLsprite->QueryIntAttribute("left", &left);
				XMLsprite->QueryIntAttribute("top", &top);
				XMLsprite->QueryIntAttribute("width", &width);
				XMLsprite->QueryIntAttribute("height", &height);
				XMLsprite->QueryIntAttribute("xPivot", &xPivot);
				XMLsprite->QueryIntAttribute("yPivot", &yPivot);

				Add(id, left, top, left+width, top+height, CTextureDatabase::GetInstance()->Get(textureId));
				OutputDebugStringW(ToLPCWSTR("[INFO] loaded sprite: " + id + "/n"));
			}
		}
	}
	else
	{
		OutputDebugStringW(ToLPCWSTR("[ERROR] could not load file: "+ spritePath + "\n"));
	}
}



