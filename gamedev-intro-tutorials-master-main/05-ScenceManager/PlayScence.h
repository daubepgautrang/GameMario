#pragma once
#include "TinyXML/tinyxml.h"
#include "Game.h"
#include "Textures.h"
#include "Scence.h"
#include "GameObject.h"
#include "Brick.h"
#include "Ground.h"
#include "Player.h"
#include "Goomba.h"
#include "Koopas.h"
#include "Tilemap.h"
#include "Camera.h"

class CPlayScene: public CScene
{
protected: 
	Tilemap tilemap;
	Player *player;					// A play scene has to have player, right? 

	/*Tilemap* tilemap;*/

	vector<LPGAMEOBJECT> objects;

	void _ParseSection_TEXTURES(string line);
	void _ParseSection_SPRITES(string line);
	void _ParseSection_ANIMATIONS(string line);
	void _ParseSection_ANIMATION_SETS(string line);
	void _ParseSection_OBJECTS(string line);
	void _ParseSection_TILEMAP(string line);

	
public: 
	CPlayScene(string id);

	virtual void Load(TiXmlElement* data);
	virtual void Update(DWORD dt);
	virtual void Render();
	virtual void Unload();
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	virtual void AddObject(LPGAMEOBJECT obj);
	Player * GetPlayer() { return player; } 

	friend class CPlayScenceKeyHandler;
};

//class CPlayScenceKeyHandler : public CScenceKeyHandler
//{
//public: 
//	virtual void KeyState(BYTE *states);
//	virtual void OnKeyDown(int KeyCode);
//	virtual void OnKeyUp(int KeyCode);
//	CPlayScenceKeyHandler(CScene *s) :CScenceKeyHandler(s) {};
//};

