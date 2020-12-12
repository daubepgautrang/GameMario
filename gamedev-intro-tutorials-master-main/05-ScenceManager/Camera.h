#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Utils.h"

class Camera
{
protected:
	Vec2 position;
	Vec2 size;
	float boundaryleft, boundaryright, boundarytop, boundarybottom;
public:
	Camera();
	~Camera();
	Camera(Vec2 pos, Vec2 size);
	virtual Vec2 GetCameraSize();
	virtual void SetCameraSize(float w, float h);
	virtual Vec2 GetCameraPosition();
	virtual void SetCameraPosition(float x, float y);
	virtual Vec2 ToGetPosition(float x, float y);
	void Update(DWORD dt);
};