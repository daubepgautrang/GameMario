#pragma once
#include "PlayerState.h"
#include <d3dx9tex.h>

class PlayerAttackingState : public PlayerState
{
public:
	PlayerAttackingState();
	void Update(DWORD dt);
	void HandleKeyboard(DWORD dt);
	void UpdateAnimation();
};

