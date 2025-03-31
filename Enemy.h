#pragma once
#include "Engine/GameObject.h"

class Enemy :
    public GameObject
{
	int hModel;
	int SpawnTime_;
public:
	Enemy(GameObject* parent);
	~Enemy() {};

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	XMFLOAT3 GetPosition() { return transform_.position_; }
};

