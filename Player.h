#pragma once
#include "Engine/GameObject.h"
class FBX;//pointa使うなら前方宣言するだけでOK　多重定義の防止に使える

class Player :
    public GameObject
{
	int hModel;
public:
	Player(GameObject* parent);
	~Player();

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};

