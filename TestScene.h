#pragma once
#include "Engine/GameObject.h"
class TestScene :
    public GameObject
{
public:
	TestScene(GameObject* parent);
	~TestScene() {};

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

