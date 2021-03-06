#include <vector>
#include <d3dx9.h>
#include "MarioModel.h"
#include "Camera.h"

#define ANI_BIG_MARIO_IDLE			"ani-big-mario-idle"
#define ANI_BIG_MARIO_WALK			"ani-big-mario-walk"
#define ANI_BIG_MARIO_SKID			"ani-big-mario-skid"
#define ANI_BIG_MARIO_RUN			"ani-big-mario-run"
#define ANI_BIG_MARIO_JUMP			"ani-big-mario-jump"
#define ANI_BIG_MARIO_CROUCH		"ani-big-mario-crouch"	
#define ANI_BIG_MARIO_HIGH_JUMP		"ani-big-mario-high-jump"
#define ANI_BIG_MARIO_HIGH_SPEED	"ani-big-mario-high-speed"
#define ANI_BIG_MARIO_HOLD			"ani-big-mario-hold"
#define ANI_BIG_MARIO_KICK			"ani-big-mario-kick"
#define MARIO_BIG_BBOX_WIDTH				42
#define MARIO_BIG_BBOX_HEIGHT				80
#define MARIO_BIG_BBOX_HEIGHT_CROUCH		54

class BigMario : public MarioModel
{
private:
	void BigMarioMoveState();
public:
	BigMario();
	void Update(DWORD dt, std::vector<LPGAMEOBJECT>* coObject = NULL);
	void Render(Camera* camera);
	void LoadAnimation();
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};

