#include "Mario.h"
#include "Animations.h"

Mario::Mario(float x, float y)
{
	LoadAnimation();
	this->start_x = x;
	this->start_y = y;
	this->x = x;
	this->y = y;

	StateMario.push_back(new BigMario());
	CurrentMario = StateMario[0];


}

void Mario::Update(DWORD dt, std::vector<LPGAMEOBJECT>* collision_objects)
{
	CurrentMario->Update(dt, collision_objects);
}

void Mario::Render(Camera* camera)
{
	auto pos = camera->ToGetPosition(this->x, this->y);

	CAnimations::GetInstance()->Get("ani-big-mario-walk")->Render(1,pos.x, pos.y);
	//CurrentMario->Render(camera);
}

void Mario::OnOverLap(CGameObject* obj)
{
}

void Mario::GetBoundingBox(float& left, float& top, float& right, float& bottom)
{
}

void Mario::LoadAnimation()
{
}
