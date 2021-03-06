#include <iostream>
#include <fstream>

#include "PlayScence.h"
#include "Utils.h"
#include "Textures.h"
#include "Sprites.h"
#include "Portal.h"
#include "GameGlobal.h"
#include "StatePlayer.h"


using namespace std;

CPlayScene::CPlayScene(string id):
	CScene(id)
{
	/*key_handler = new CPlayScenceKeyHandler(this);*/

}

/*
	Load scene resources from scene file (textures, sprites, animations and objects)
	See scene1.txt, scene2.txt for detail format specification
*/

#define SCENE_SECTION_UNKNOWN -1
#define SCENE_SECTION_TEXTURES 2
#define SCENE_SECTION_SPRITES 3
#define SCENE_SECTION_ANIMATIONS 4
#define SCENE_SECTION_ANIMATION_SETS	5
#define SCENE_SECTION_OBJECTS	6
#define SCENE_SECTION_TILEMAP	7

#define OBJECT_TYPE_MARIO			0
#define OBJECT_TYPE_GROUND			1
#define OBJECT_TYPE_BRICK			2
#define OBJECT_TYPE_ONEWAYPLATFORM	3
#define OBJECT_TYPE_GOOMBA			4
#define OBJECT_TYPE_KOOPAS			5

#define OBJECT_TYPE_PORTAL	50

#define MAX_SCENE_LINE 1024


#pragma region  PARSE GAME DATA

void CPlayScene::_ParseSection_TEXTURES(string line)
{
	//vector<string> tokens = split(line);

	//if (tokens.size() < 5) return; // skip invalid lines

	//int texID = atoi(tokens[0].c_str());
	//wstring path = ToWSTR(tokens[1]);
	//int R = atoi(tokens[2].c_str());
	//int G = atoi(tokens[3].c_str());
	//int B = atoi(tokens[4].c_str());

	//CTextureDatabase::GetInstance()->Add(texID, path.c_str(), D3DCOLOR_XRGB(R, G, B));
}

void CPlayScene::_ParseSection_SPRITES(string line)
{
	//vector<string> tokens = split(line);

	//if (tokens.size() < 6) return; // skip invalid lines

	//int ID = atoi(tokens[0].c_str());
	//int l = atoi(tokens[1].c_str());
	//int t = atoi(tokens[2].c_str());
	//int r = atoi(tokens[3].c_str()) + l;
	//int b = atoi(tokens[4].c_str()) + t;
	//int texID = atoi(tokens[5].c_str());

	//LPDIRECT3DTEXTURE9 tex = CTextureDatabase::GetInstance()->Get(texID);
	//if (tex == NULL)
	//{
	//	DebugOut(L"[ERROR] Texture ID %d not found!\n", texID);
	//	return; 
	//}

	//CSpriteDatabase::GetInstance()->Add(ID, l, t, r, b, tex);
}

void CPlayScene::_ParseSection_ANIMATIONS(string line)
{
	//vector<string> tokens = split(line);

	//if (tokens.size() < 3) return; // skip invalid lines - an animation must at least has 1 frame and 1 frame time

	////DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	//LPANIMATION ani = new CAnimation();

	//int ani_id = atoi(tokens[0].c_str());
	//for (int i = 1; i < tokens.size(); i += 2)	// why i+=2 ?  sprite_id | frame_time  
	//{
	//	int sprite_id = atoi(tokens[i].c_str());
	//	int frame_time = atoi(tokens[i+1].c_str());
	//	ani->Add(sprite_id, frame_time);
	//}

	//CAnimations::GetInstance()->Add(ani_id, ani);
}

void CPlayScene::_ParseSection_ANIMATION_SETS(string line)
{
	//vector<string> tokens = split(line);

	//if (tokens.size() < 2) return; // skip invalid lines - an animation set must at least id and one animation id

	//int ani_set_id = atoi(tokens[0].c_str());

	//LPANIMATION_SET s = new CAnimationSet();

	//CAnimations *animations = CAnimations::GetInstance();

	//for (int i = 1; i < tokens.size(); i++)
	//{
	//	int ani_id = atoi(tokens[i].c_str());
	//	
	//	LPANIMATION ani = animations->Get(ani_id);
	//	s->push_back(ani);
	//}

	//CAnimationSetDatabase::GetInstance()->Add(ani_set_id, s);
}

/*
	Parse a line in section [OBJECTS] 
*/
void CPlayScene::_ParseSection_OBJECTS(string line)
{
	//vector<string> tokens = split(line);

	////DebugOut(L"--> %s\n",ToWSTR(line).c_str());

	//if (tokens.size() < 3) return; // skip invalid lines - an object set must have at least id, x, y

	//int object_type = atoi(tokens[0].c_str());
	//float x = atof(tokens[1].c_str());
	//float y = atof(tokens[2].c_str());

	//int ani_set_id = atoi(tokens[3].c_str());

	//CAnimationSetDatabase * animation_sets = CAnimationSetDatabase::GetInstance();

	//CGameObject *obj = NULL;

	//switch (object_type)
	//{
	//case OBJECT_TYPE_MARIO:
	//	if (player!=NULL) 
	//	{
	//		DebugOut(L"[ERROR] MARIO object was created before!\n");
	//		return;
	//	}
	//	obj = new Player(x,y); 
	//	player = (Player*)obj;  

	//	DebugOut(L"[INFO] Player object created!\n");
	//	break;
	//case OBJECT_TYPE_GOOMBA: obj = new CGoomba(); break;
	//case OBJECT_TYPE_BRICK: obj = new CBrick(); break;
	//case OBJECT_TYPE_KOOPAS: obj = new CKoopas(); break;
	//case OBJECT_TYPE_GROUND:
	//{
	//	float width = atof(tokens[4].c_str());
	//	float height= atof(tokens[5].c_str());
	//	obj = new Ground(width,height);
	//}
	//case OBJECT_TYPE_ONEWAYPLATFORM:
	//{
	//	float width = atof(tokens[4].c_str());
	//	float height = atof(tokens[5].c_str());
	//	obj = new Ground(width, height);
	//}
	//break;
	//case OBJECT_TYPE_PORTAL:
	//	{	
	//		float r = atof(tokens[4].c_str());
	//		float b = atof(tokens[5].c_str());
	//		int scene_id = atoi(tokens[6].c_str());
	//		obj = new CPortal(x, y, r, b, scene_id);
	//	}
	//	break;
	//default:
	//	DebugOut(L"[ERR] Invalid object type: %d\n", object_type);
	//	return;
	//}

	//// General object setup
	//obj->SetPosition(x, y);

	//LPANIMATION_SET ani_set = animation_sets->Get(ani_set_id);

	//obj->SetAnimationSet(ani_set);
	//objects.push_back(obj);
}

void CPlayScene::_ParseSection_TILEMAP(string line)
{
	vector<string> tokens = split(line);

	if (tokens.size() < 1) return; // skip invalid lines

	int ID = atoi(tokens[0].c_str());
	wstring filePath_texture = ToWSTR(tokens[1]);
	wstring filePath_data = ToWSTR(tokens[2]);
	int num_row_on_texture = atoi(tokens[3].c_str());
	int num_col_on_textture = atoi(tokens[4].c_str());
	int num_row_on_tilemap = atoi(tokens[5].c_str());
	int num_col_on_tilemap = atoi(tokens[6].c_str());
	int tileset_width = atoi(tokens[7].c_str());
	int tileset_height = atoi(tokens[8].c_str());
	//int widthGrid = atoi(tokens[9].c_str());
	//int heightGrid = atoi(tokens[10].c_str());
	//boardscore = new BoardScore();
	//grid = new Grid();
	//grid->Resize(widthGrid, heightGrid);
	//grid->PushGrid(allObject);
	//tilemap = new Tilemap(ID, filePath_texture.c_str(), filePath_data.c_str(), num_row_on_texture,num_col_on_textture, num_row_on_tilemap, num_col_on_tilemap, tileset_width, tileset_height);
}

#pragma endregion

void CPlayScene::Load(TiXmlElement* data)
{
	TiXmlElement* mapData = data->FirstChildElement("TmxMap");
	string mapPath = mapData->Attribute("path");
	string mapfileName = mapData->Attribute("fileName");
	tilemap = new CTilemap(mapPath, mapfileName);

	camera = new Camera();
	camera->SetCameraPosition(0, 800);
	camera->SetCameraSize(CGame::GetInstance()->GetScreenWidth(), CGame::GetInstance()->GetScreenHeight());
	CGame::GetInstance()->setCam(camera);
	//camera->SetBoundary(0,0,tilemap->)
	player = new Player();

}

void CPlayScene::Update(DWORD dt)
{
	// We know that Mario is the first object in the list hence we won't add him into the colliable object list
	// TO-DO: This is a "dirty" way, need a more organized way 

	vector<LPGAMEOBJECT> coObjects;
	for (size_t i = 1; i < objects.size(); i++)
	{
		coObjects.push_back(objects[i]);
	}

	for (size_t i = 0; i < objects.size(); i++)
	{
		objects[i]->Update(dt, &coObjects);
	}

	// skip the rest if scene was already unloaded (Mario::Update might trigger PlayScene::Unload)
	if (player == NULL) return; 

	// Update camera to follow mario
	float cx, cy;
	player->GetPosition(cx, cy);

	CGame *game = CGame::GetInstance();
	cx -= game->GetScreenWidth() / 2;
	cy -= game->GetScreenHeight() / 2;

	//if (cx <= 0)
	//{
	//	cx = 0;
	//}
	//else if (cx + SCREEN_WIDTH >= tilemap->GetWidthTileMap())
	//{
	//	//cx = tilemap->GetWidthTileMap() - SCREEN_WIDTH;
	//}


	CGame::GetInstance()->SetCamPos(cx, 32.0f /*cy*/);
}

void CPlayScene::Render()
{
	tilemap->Render();
	for (int i = 0; i < objects.size(); i++)
		objects[i]->Render(this->camera);

	player->Render(this->camera);
}

/*
	Unload current scene
*/
void CPlayScene::Unload()
{
	for (int i = 0; i < objects.size(); i++)
		delete objects[i];

	objects.clear();
	player = NULL;

	DebugOut(L"[INFO] Scene %s unloaded! \n", sceneFilePath);
}

void CPlayScene::OnKeyDown(int key)
{
	//DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	keyCode[key] = true;
	//player->OnKeyDown(key);
}

void CPlayScene::OnKeyUp(int key)
{
	//DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);

	keyCode[key] = false;
	//player->OnKeyUp(key);
}

void CPlayScene::AddObject(LPGAMEOBJECT obj)
{
	this->objects.push_back(obj);
}

void CPlayScene::KeyState(BYTE *states)
{
	/*Player *mario = ((CPlayScene*)scence)->GetPlayer();*/
	//player->KeyState(states);
}