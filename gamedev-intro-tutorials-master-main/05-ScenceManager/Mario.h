#include <unordered_map>
#include <vector>
#include "GameObject.h"
#include "MarioModel.h"
#include "Camera.h"
#include "BigMario.h"

#define MARIO_GRAVITY 0.005f
#define MARIO_BBOX_X 48
#define MARIO_BBOX_Y 48


class Mario : public CGameObject
{
private:
	float start_x, start_y;
	Camera* camera;
	std::vector<MarioModel*> StateMario;
	MarioModel* CurrentMario;
public:
	Mario(float x = 0.0f, float y = 0.0f);
	virtual void Update(DWORD dt, std::vector<LPGAMEOBJECT>* collision_objects = NULL);
	virtual void Render(Camera* camera);
	virtual void OnOverLap(CGameObject* obj);
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);

	MarioModel* GetCurrentMario();
	void Reset();
	void LoadAnimation();
	void SetCamera(Camera* camera);
};

