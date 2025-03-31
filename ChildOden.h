#pragma once
#include "Engine/GameObject.h"
class FBX;

class ChildOden :
    public GameObject
{
	//FBX* pFbx;
	int hModel;
public:
	ChildOden(GameObject* parent);
	~ChildOden();

	void Initialize();
	void Update();
	void Draw();
	void Release();

	void OnCollision(GameObject* pTarget) override;
};

