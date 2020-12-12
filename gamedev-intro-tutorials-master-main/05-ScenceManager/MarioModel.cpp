#include "MarioModel.h"
#include <dinput.h>

MarioModel::MarioModel(float x, float y)
{
	start_x = x;
	start_y = y;
	this->x = x;
	this->y = y;

	//this->changestate = -1;

	InvincibleFrame = 0;

	LoadAnimation();

	state.move = MovingStates::Idle;
}

void MarioModel::Update(DWORD dt, std::vector<LPGAMEOBJECT>* coObjects)
{

}

void MarioModel::SetMoveState(MovingStates move)
{
	prestate = this->state;
	this->state.move = move;
}

void MarioModel::SetJumpState(JumpingStates jump)
{
	switch (jump)
	{
	case JumpingStates::Fly:
			IsOnGround = false;
			break;
	}
	this->state.jump = jump;
}

void MarioModel::OnKeyDown(int KeyCode)
{
	switch (KeyCode)
	{
	case DIK_A:
	{
		IncreasePMetterTime_Start = GetTickCount();
	}
	case DIK_X:
	{
		if (IsOnGround)
		{
			SetJumpState(JumpingStates::Jump);
			IsOnGround = false;
		}
		break;
	}
	case DIK_S:
	{
		if (IsOnGround)
		{
			SetJumpState(JumpingStates::Jump);
			IsOnGround = false;
			IsHighJump = true;
			HighJumpTime_Start = GetTickCount();
			vy = MARIO_MINIMUM_LIFT;
		}
		break;
	}
	case DIK_1:
	{
		break;
	}
	case DIK_2:
	{
		break;
	}
	case DIK_3:
	{
		break;
	}
	case DIK_4:
	{
		break;
	}
	case DIK_DOWN:
	{
		SetMoveState(MovingStates::Crouch);
		break;
	}
	case DIK_Q:
	{
		//add Goomba
	}
	case DIK_W:
	{
		//add Koopa
	}
	}
}

void MarioModel::OnKeyUp(int KeyCode)
{
	CGame* game = CGame::GetInstance();

	if (this->state.move == MovingStates::Die)
		return;

	switch (KeyCode)
	{
	case DIK_S:
	{
		if (IsHighJump)
			IsHighJump = false;
		break;
	}
	case DIK_A:
	{
		if (Hold != NULL)
		{
			//unimplement !!!
		}
	}
	DecayPMetterTime_Start = GetTickCount();
	break;
	}
}

void MarioModel::KeyState(BYTE* state)
{
}

void MarioModel::SetPosition(int x, int y)
{
	CGameObject::SetPosition(x, y);
}
