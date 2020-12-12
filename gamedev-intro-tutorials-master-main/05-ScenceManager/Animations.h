#pragma once
#include <Windows.h>
#include <d3dx9.h>
#include <unordered_map>

#include "Sprites.h"

/*
Sprite animation
*/
class CAnimationFrame
{
	LPSPRITE sprite;
	DWORD time;

public:
	CAnimationFrame(LPSPRITE sprite, int time) { this->sprite = sprite; this->time = time; }
	DWORD GetTime() { return time; }
	LPSPRITE GetSprite() { return sprite; }
};

typedef CAnimationFrame *LPANIMATION_FRAME;

class CAnimation
{
	DWORD lastFrameTime;
	int currentFrame;
	int defaultTime;
	vector<LPANIMATION_FRAME> frames;
public:
	CAnimation(int defaultTime = 100) { this->defaultTime = defaultTime; lastFrameTime = -1; currentFrame = -1; }
	void Add(string spriteId, DWORD time = 0);
	int GetCurrentFrame() { return currentFrame; }
	void Render(int direction, float x, float y, int alpha = 255);
};

typedef CAnimation *LPANIMATION;

class CAnimations
{
	static CAnimations * __instance;

	unordered_map<string, LPANIMATION> animations;

public:
	void Add(string id, LPANIMATION ani);
	LPANIMATION Get(string id);
	void Clear();
	void ImportAnimationFromXml(string AnimationPath);
	static CAnimations * GetInstance();
};

typedef vector<LPANIMATION> CAnimationSet;

typedef CAnimationSet* LPANIMATION_SET;

/*
	Manage animation set database
*/
class CAnimationSetDatabase
{
	static CAnimationSetDatabase * __instance;

	unordered_map<string, LPANIMATION_SET> animation_sets;

public:
	CAnimationSetDatabase();
	void Add(string id, LPANIMATION_SET ani);
	LPANIMATION_SET Get(string id);

	static CAnimationSetDatabase * GetInstance();
};