#include "Enemy.h"
#include"Model.h"
#include"SphereCollider.h"
#include"Player.h"

namespace {
	
	const int enemylife = 5;
	int rot = 180;
	float EnemyPos = 2.5f;
}

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel(-1)
{
}

void Enemy::Initialize()
{
	hModel = Model::Load("Assets//enemy.fbx");
	transform_.position_.y = EnemyPos; 
	transform_.scale_ = { 0.5,0.5,0.5 };
	transform_.rotate_.x = rot;
	SetHp(enemylife);
	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);

}

void Enemy::Update()
{
	int r = rand() % 3;
	
	static int dt;//ˆÚ“®‚·‚é
	dt += 5;
	float nTime = dt / (60.0f * 10.0f) - 2.0;
	transform_.position_.x = 4.0 * sin(nTime);

	

	if (GetHp() <= 0) {
		KillMe();
	}

}

void Enemy::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Enemy::Release()
{
	
}
