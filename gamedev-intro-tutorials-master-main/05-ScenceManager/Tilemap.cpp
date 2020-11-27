#include "Tilemap.h"
#include "GameGlobal.h"
#include "Game.h"
#include "Brick.h"
#include "Layer.h"
#include <memory>
#include "OneWayPlatform.h"

CTilemap::CTilemap(string path, string name)
{
	string fullpath = path + name;
	TiXmlDocument doc(fullpath.c_str());

	if (!doc.LoadFile()) 
	{
		return;
	}

	TiXmlElement* root = doc.RootElement();
	//Tilemap* CTilemap = new Tilemap();

	root->QueryIntAttribute("width", &width);
	root->QueryIntAttribute("height", &height);
	root->QueryIntAttribute("tilewidth", &tilewidth);
	root->QueryIntAttribute("tileheight", &tileheight);

	TiXmlElement* tileset = root->FirstChildElement("tileset");
	tileset->QueryIntAttribute("columns", &columns);

	string imgPath = tileset->FirstChildElement("image")->Attribute("source");

	this->tilesetTextureId = path + imgPath;
	CTextureDatabase::GetInstance()->Add(tilesetTextureId, ToLPCWSTR(tilesetTextureId), D3DCOLOR_ARGB(0, 0, 0, 0));

	TiXmlElement* layerInfo = root->FirstChildElement("layer");
	for (TiXmlElement* layerInfo = root->FirstChildElement("layer"); layerInfo != NULL; layerInfo = layerInfo->NextSiblingElement("layer"))
	{
		Layer layer = make_shared<CLayer>(layerInfo);
		this->AddLayer(layer);
	}
	for (TiXmlElement* objectgroupInfo = root->FirstChildElement("objectgroup"); objectgroupInfo != NULL; objectgroupInfo = objectgroupInfo->NextSiblingElement("objectgroup"))
	{
		string name1 = objectgroupInfo->Attribute("name");
		if (name1 == "Object Layer")
			continue;
		for (TiXmlElement* objectInfo = objectgroupInfo->FirstChildElement("object"); objectInfo != NULL; objectInfo = objectInfo->NextSiblingElement("object"))
		{
			CGameObject* obj = NULL;
			std::string name = objectInfo->Attribute("name");
			if (name == "SolidBlock")
			{
				obj = new CBrick();
			}
			if (name == "GhostBlock")
			{
				obj = new OneWayPlatform();
			}

			float x =0, y = 0;
			float width=0, height=0;
			objectInfo->QueryFloatAttribute("x", &x);
			objectInfo->QueryFloatAttribute("y", &y);
			objectInfo->QueryFloatAttribute("width", &width);
			objectInfo->QueryFloatAttribute("height", &height);

			obj->SetPosition(x, y);
			obj->SetWidthHeight(width, height);
			CGame::GetInstance()->GetCurrentScene()->AddObject(obj);

			DebugOut(L"[INFO] %f \t %f \n", x, y);
		}
	}
}

void CTilemap::Render()
{
	int col = CGame::GetInstance()->GetCamX() / tilewidth;
	int row = CGame::GetInstance()->GetCamY() / tileheight;

	if (col > 0)
		col--;
	if (row > 0)
		row--;

	Vec2 camSize = Vec2(CGame::GetInstance()->GetCamWidth() / tilewidth, CGame::GetInstance()->GetCamHeight() / tileheight);

	for (int i = col; i < camSize.x + col + 2; i++)
	{
		for (int j = row; j < camSize.y + row + 2; j++)
		{
			int x = i * tilewidth /*- CGame::GetInstance()->GetCamX();*/;
			int y = j * tileheight /*- CGame::GetInstance()->GetCamY();*/;

			for (shared_ptr<CLayer> layer : layers)
			{
				if (layer->Hidden) continue;
				int id = layer->GetTileID(i % width, j % height);
				this->Draw(id, x, y);
			}
		}
	}
}

void CTilemap::Draw(int gid, float x, float y)
{
	if (gid < firstgid) return;
	RECT r;
	r.top = ((gid - firstgid) / columns) * tileheight;
	r.left = ((gid - firstgid) % columns) * tilewidth;
	r.bottom = r.top + tileheight;
	r.right = r.left + tilewidth;
	
	CGame::GetInstance()->Draw(1, x, y, CTextureDatabase::GetInstance()->Get(tilesetTextureId), r.left, r.top, r.right, r.bottom);
}

void CTilemap::AddLayer(Layer layer)
{
	this->layers.push_back(layer);
}


CTilemap::~CTilemap()
{
}


