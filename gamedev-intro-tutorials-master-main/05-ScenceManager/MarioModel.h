#pragma once

#include "GameObject.h"
#include "Game.h"
#include "Camera.h"
#include "Scence.h"
#include "Animations.h"

// mario collisionbox status
#define MARIO_BBOX_WIDTH				42
#define MARIO_BBOX_HEIGHT				80
#define MARIO_BBOX_HEIGHT_CROUCH		54

// mario status
#define MARIO_HIGH_JUMP_TIME			200
#define MARIO_UNTOUCHABLE_TIME			5000
#define MARIO_PMETTER					7
#define MARIO_PLUS_PMETTER_TIME			300
#define MARIO_DECAY_PEMETTER_TIME		250

//mario physic
#define MARIO_GRAVITY					0.003f
#define MARIO_ACCELERATION				0.002f
#define MARIO_DRAG						0.007f
#define MARIO_TOP_WALKING_SPEED			0.30f
#define MARIO_TOP_RUNNING_SPEED			0.4f
#define MARIO_MIN_SPEED					0.1f
#define MARIO_JUMP_FORCE				-0.65f
#define MARIO_MINIMUM_LIFT				-0.001f
#define MARIO_DEFLECT_MOB				0.05f

enum class MovingStates
{
	Die,
	Idle,
	Walk,
	Run,
	Crouch,
	Attack
};

enum class JumpingStates
{
	Stand,
	Jump,
	Fall,
	Float,
	Fly
};

struct MarioStateSet
{
	MovingStates move;
	JumpingStates jump;
};

class MarioModel : public CGameObject
{
protected:
	int InvincibleFrame;
	DWORD InvincibleTime_Start;
	DWORD HighJumpTime_Start;
	DWORD IncreasePMetterTime_Start;
	DWORD DecayPMetterTime_Start;

	float start_x;
	float start_y;

	//float acc_x;

	MarioStateSet state, prestate;
	//int changestate;
	//
	//bool canFly = false;
	//bool fullMetter = false;
	bool IsOnGround;
	bool IsHighJump;
	//bool isIncreasingPMetter = false;
	//int  PMetter = 0;
	CGameObject* Hold;

public:
	MarioModel(float x = 0, float y = 0);

	virtual void Update(DWORD dt, std::vector<LPGAMEOBJECT>* coObjects = NULL);
	virtual void Render(Camera* camera) = 0;

	void SetMoveState(MovingStates move);
	void SetJumpState(JumpingStates jump);

	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	virtual void KeyState(BYTE* state);

	virtual void GetBoundingBox(float& l, float& t, float& r, float& b) = 0;

	virtual void LoadAnimation() {};
	
	void SetPosition(int x, int y);
};

