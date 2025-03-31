#pragma once
#include "Engine/GameObject.h"
#include"Engine/Sprite.h"

class GameOverScene :
    public GameObject
{
private:
	int hImage_;
	Sprite* spr_;
public:
	GameOverScene(GameObject* parent);
	~GameOverScene() {};

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

