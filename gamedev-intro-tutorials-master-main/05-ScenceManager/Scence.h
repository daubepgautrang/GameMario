#pragma once
#include "TinyXML/tinyxml.h"
#include <d3dx9.h>
#include "KeyEventHandler.h"
#include "Utils.h"
#include "GameObject.h"
#include "Camera.h"

class CScene
{
protected:
	CKeyEventHandler * key_handler;
	string id;
	LPCWSTR sceneFilePath;
	Camera* camera;
public: 
	CScene(string id);

	CKeyEventHandler * GetKeyEventHandler() { return key_handler; }
	virtual void Load(TiXmlElement* data) = 0;
	virtual void Unload() = 0;
	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0; 
	virtual void KeyState(BYTE* states) = 0;
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
	virtual void AddObject(LPGAMEOBJECT obj) = 0;
};
typedef CScene * LPSCENE;