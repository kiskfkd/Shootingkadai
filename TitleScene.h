#pragma once
#include "Engine/GameObject.h"
#include"Engine/Sprite.h"

class TitleScene :
    public GameObject
{
private:
	int hImage_;
	Sprite* spr_;
public:
	TitleScene(GameObject* parent);
	~TitleScene(){};

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

