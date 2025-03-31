#pragma once
#include "Engine/GameObject.h"

//‘O•ûéŒ¾
class FBX;

class PlayScene :
    public GameObject
{
public:
	PlayScene(GameObject* parent);
	~PlayScene();

	 void Initialize();
	 void Update();
	 void Draw();
	 void Release();
};

