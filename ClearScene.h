#pragma once
#include "Engine/GameObject.h"
#include"Engine/Sprite.h"

class ClearScene :
    public GameObject
{
private:
	int hImage_;
	Sprite* spr_;
public:
	ClearScene(GameObject* parent);
	~ClearScene() {};

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

