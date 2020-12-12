#pragma once

#include "GameObject.h"
#include "Camera.h"
#include "PlayScence.h"
#include "Utils.h"

#define mario_gravity			 0.003f
#define mario_acceleration		 0.002f
#define mario_friction			 0.007f
#define mario_walking_speed		 0.3f
#define mario_run_speed			 0.4f
#define mario_min_speed			 0.1f
#define mario_jump_force		 -0.65f
#define mario_deflect_mob		 0.05f
#define mario_high_jump_time	 200
#define mario_bbox_width		 42
#define mario_bbox_height		 80
#define mario_bbox_height_crough 54

enum class StateMove
{
	Die,
	Idle,
	Fall,
	Run,
	Crough,
	Attack,
};

enum class StateJump
{
	Stand,
	Jump,
	Fall,
	Float,
	Fly,
};

struct MarioState
{
	StateMove movement;
	StateJump jump;
};


class StatePlayer : public CGameObject
{
	DWORD JumpTime;

	float x_start;
	float y_start;

	float x_acc;

	MarioState state, prestate;
	int changestate;

	bool CanFly = false;
	bool FullMeter = false;
	bool IsOnGround;
	bool IsHighJump;
	bool IsCreasePMetter = false;
	int PMetter;

	CGameObject* Hold;
public:
	StatePlayer(float x = 0, float y = 0);

	virtual void Update(DWORD dt, std::vector<LPGAMEOBJECT>* coObject = NULL);
	virtual void Render(Camera* camera) = 0;

	void SetStateMove(StateMove move);
	void SetStateJump(StateJump jump);

	virtual void OnKeyDown(int KC);
	virtual void OnKeyUp(int KC);
	virtual void StateKey(BYTE* state)
	{}

	virtual void LoadAnimation()
	{}
	virtual void GetBoundingBox(float& l, float& t, float& r, float& b) = 0;
	
	void SetPosition(int x, int y);
};

