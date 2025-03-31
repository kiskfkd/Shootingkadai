#include "ChildOden.h"
#include"Engine/FBX.h"
#include"Model.h"
#include"Enemy.h"
#include"SphereCollider.h"
#include"SceneManager.h"

namespace {
	const int DeadLine = 20;
	float childpos = 0.3f;
	float rot = 3.0f;
}

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent,"ChildOden"), hModel(-1)/*pFbx(nullptr)*/
{
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{
	hModel = Model::Load("Assets//oden.fbx");
	transform_.scale_ = { 0.2,0.2,0.2 };
	
	SphereCollider * col = new SphereCollider(0.5f);
	this->AddCollider(col);

}

void ChildOden::Update()
{
	transform_.position_.y += childpos;
	transform_.rotate_.y += rot;
	Enemy* enemy = (Enemy*)FindObject("Enemy");

	/*//’e‚Æ“G‚Ì“ñ“_ŠÔ‚Ì‹——£@ƒ@“G‚Ì’†‰›‚©‚ç‚Ì‹——£+’e‚Ì’†‰›‚©‚ç‚Ì‹——£
	float r1 = 0.1;
	float r2 = 0.5;
	XMFLOAT3 P1 = enemy->GetPosition();
	XMFLOAT3 P2 = transform_.position_;
	XMVECTOR dist = XMVector3Length(XMVectorSet(P1.x, P1.y, P1.z, 1) - XMVectorSet(P2.x, P2.y, P2.z, 1));
	float d = XMVectorGetX(dist);
	if (d <= r1 + r2)
	{
		KillMe();
	}*/

	if (transform_.position_.y >= DeadLine)
	{
		KillMe();
	}
}

void ChildOden::Draw()
{
	//pFbx->Draw(transform_);
	Model::SetTransform(hModel, transform_);
	Model::Draw(hModel);
}

void ChildOden::Release()
{
}

void ChildOden::OnCollision(GameObject* pTarget)
{
	if (pTarget == FindObject("Enemy") || pTarget == FindObject("EnemyBullet"))
	{
		/*KillMe();
		pTarget->KillMe();*/
		KillMe();
		pTarget->Damage();
	}

}
