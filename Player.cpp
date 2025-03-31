#include "Player.h"
#include"Engine/FBX.h"
#include"ChildOden.h"
#include"Input.h"
#include"Model.h"
#include"SphereCollider.h"

namespace {
	int mylife = 3;
	float rot = 2.0f;
	float move = 0.2f;
}

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//pOden = new FBX();
	//pOden->Load("Assets//oden.fbx");
	hModel = Model::Load("Assets//oden.fbx");
	transform_.scale_ = { 0.4,0.4,0.4 };
	transform_.position_ = { 0,-2,0 };
	SetHp(mylife);

	SphereCollider* col = new SphereCollider(0.1f);
	this->AddCollider(col);

	/*GameObject *pCO = Instantiate<ChildOden>(this);
	pCO->SetPosition(0, 0, -1);
	GameObject* pCO2 = Instantiate<ChildOden>(this);
	pCO2->SetPosition(-2, 0, -1);*/
}

void Player::Update()
{
	//transform_.rotate_.y += 1;
	/*if (transform_.rotate_.y > 60 * 2) 
	{
		KillMe();
	}*/

	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= move;
		transform_.rotate_.y += rot;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += move;
		transform_.rotate_.y -= rot;
	}

	/*if (transform_.position_.x <= -4.0f)
	{
		int i = 0;
	}*/

	if(Input::IsKeyUp(DIK_SPACE))
	{
		GameObject* pCO = Instantiate<ChildOden>(this);
		pCO->SetPosition(transform_.position_.x,transform_.position_.y ,transform_.position_.z);
	}

	if (GetHp() <= 0) {
		KillMe();
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void Player::Release()
{
	//this->Release();
}