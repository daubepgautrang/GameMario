#include "Animations.h"
#include "Utils.h"
#include "Game.h"

CAnimationSetDatabase * CAnimationSetDatabase::__instance = NULL;

void CAnimation::Add(string spriteId, DWORD time)
{
	int t = time;
	if (time == 0) t = this->defaultTime;
	LPSPRITE sprite = CSpriteDatabase::GetInstance()->Get(spriteId);

	if (sprite == NULL)
	{
		DebugOut(L"[ERROR] Sprite ID %d cannot be found!\n", spriteId);
	}

	LPANIMATION_FRAME frame = new CAnimationFrame(sprite, t);
	frames.push_back(frame);
}

// NOTE: sometimes Animation object is NULL ??? HOW ??? 
void CAnimation::Render(int direction, float x, float y, int alpha)
{
	DWORD now = GetTickCount();
	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size()) currentFrame = 0;
		}
	}

	frames[currentFrame]->GetSprite()->Draw(direction,x, y, alpha);
}

CAnimations * CAnimations::__instance = NULL;

CAnimations * CAnimations::GetInstance()
{
	if (__instance == NULL) __instance = new CAnimations();
	return __instance;
}

void CAnimations::Add(string id, LPANIMATION ani)
{
	animations[id] = ani;
}

LPANIMATION CAnimations::Get(string id)
{
	LPANIMATION ani = animations[id];
	if (ani == NULL)
		DebugOut(L"[ERROR] Failed to find animation id: %d\n", id);
	return ani;
}

void CAnimations::Clear()
{
	for (auto x : animations)
	{
		LPANIMATION ani = x.second;
		delete ani;
	}

	animations.clear();
}

void CAnimations::ImportAnimationFromXml(string AnimationPath)
{
	TiXmlDocument XMLdoc(AnimationPath.c_str());

	if (XMLdoc.LoadFile())
	{
		TiXmlElement* root = XMLdoc.RootElement();

		for (TiXmlElement* XMLtexture = root->FirstChildElement("Textures"); XMLtexture != NULL; XMLtexture = XMLtexture->NextSiblingElement("Textures"))
		{
			for (TiXmlElement* XMLanimation = XMLtexture->FirstChildElement("Animation"); XMLanimation != NULL; XMLanimation = XMLanimation->NextSiblingElement("Animation"))
			{
				LPANIMATION ani;
				int aniframetime;

				std::string aniID = XMLanimation->Attribute("aniId");
				XMLanimation->QueryIntAttribute("frameTime", &aniframetime);
				ani = new CAnimation(aniframetime);

				for (TiXmlElement* XMLanimationsprites = XMLanimation->FirstChildElement(); XMLanimationsprites != NULL; XMLanimationsprites = XMLanimationsprites->NextSiblingElement())
				{
					int frametime;
					std::string spriteId = XMLanimationsprites->Attribute("id");
					XMLanimationsprites->QueryIntAttribute("frameTime", &frametime);
					ani->Add(spriteId, frametime);
				}
				Add(aniID, ani);
				OutputDebugStringW(ToLPCWSTR("[INFO] created animation: " + aniID + "\n"));
			}
		}
	}
	else
	{
		OutputDebugStringW(ToLPCWSTR("[ERROR] could not load file" + AnimationPath));
	}
}

CAnimationSetDatabase::CAnimationSetDatabase()
{

}

CAnimationSetDatabase *CAnimationSetDatabase::GetInstance()
{
	if (__instance == NULL) __instance = new CAnimationSetDatabase();
	return __instance;
}

LPANIMATION_SET CAnimationSetDatabase::Get(string id)
{
	LPANIMATION_SET ani_set = animation_sets[id];
	if (ani_set == NULL)
		DebugOut(L"[ERROR] Failed to find animation set id: %d\n",id);
	 
	return ani_set;
}

void CAnimationSetDatabase::Add(string id, LPANIMATION_SET ani_set)
{
	animation_sets[id] = ani_set;
}
