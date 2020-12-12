#include "StatePlayer.h"

StatePlayer::StatePlayer(float x, float y)
{
	x_start = x;
	y_start = y;
	this->x = x;
	this->y = y;
	LoadAnimation();
	state.movement = StateMove::Idle;
}

void StatePlayer::Update(DWORD dt, std::vector<LPGAMEOBJECT>* coObject)
{
	CGameObject::Update(dt);

}
void StatePlayer::SetStateMove(StateMove move)
{
	prestate = this->state;
	this->state.movement = move;
}

void StatePlayer::SetStateJump(StateJump jump)
{
	switch (jump)
	{
	case StateJump::Fly:
		IsOnGround = false;
		break;
	}
	this->state.jump = jump;
}

void StatePlayer::OnKeyDown(int KC)
{
	switch (KC)
	{
	case DIK_A:
	{
		//IncreasePMetterTime_Start = GetTickCount();
	}
	case DIK_X:
	{
		if (IsOnGround)
		{
			SetStateJump(StateJump::Jump);
			IsOnGround = false;
		}
		break;
	}
	case DIK_S:
		if (IsOnGround)
		{
			SetStateJump(StateJump::Jump);
			IsOnGround = false;
			IsHighJump = true;
			//HighJumpTime_Start = GetTickCount();
			//vy = mario_min_lift;
		}
		break;

	case DIK_1:
		this->changestate = 0;
		break;
	case DIK_2:
		this->changestate = 1;
		break;
	case DIK_3:
		this->changestate = 2;
		break;
	case DIK_4:
		this->changestate = 3;
		break;

	case DIK_DOWN:
		SetStateMove(StateMove::Crough);
		break;
	}
}

void StatePlayer::OnKeyUp(int KC)
{
	CGame* game = CGame::GetInstance();

	if (this->state.movement == StateMove::Die)
		return;

	switch (KC)
	{
	case DIK_S:
		if (IsHighJump)
		{
			IsHighJump = false;
		}
		break;

	case DIK_A:
		if (Hold != NULL)
		{

		}
	}
}

void StatePlayer::SetPosition(int x, int y)
{
	CGameObject::SetPosition(x, y);
}
