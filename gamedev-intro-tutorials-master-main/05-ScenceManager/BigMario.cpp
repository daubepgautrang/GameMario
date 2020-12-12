#include "BigMario.h"

BigMario::BigMario()
{
	LoadAnimation();
	//ColTag = Collision2DTag::FourSide;
	//EntityTag = Tag::player;
}

void BigMario::BigMarioMoveState()
{

}

void BigMario::Update(DWORD dt, std::vector<LPGAMEOBJECT>* coObject)
{
	MarioModel::Update(dt, coObject);
	//BigMarioMoveState();

	if (this->state.jump == JumpingStates::Jump)
	{
		if (GetTickCount() - HighJumpTime_Start > MARIO_HIGH_JUMP_TIME)
		{
			IsHighJump = false;
		}
	}
}

void BigMario::Render(Camera* camera)
{
	CAnimations::GetInstance()->Get("ani-big-mario-walk")->Render(1, 100, 100);
}

void BigMario::LoadAnimation()
{
}

void BigMario::GetBoundingBox(float& l, float& t, float& r, float& b)
{
}
