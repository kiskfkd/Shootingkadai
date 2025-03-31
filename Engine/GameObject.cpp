#include "GameObject.h"
#include"Direct3D.h"
#include"../SphereCollider.h"
#include<string>

using std::string;

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent),objectName_(name),isDead_(false),pCollider_(nullptr),Hp_(0)
{
	if (parent != nullptr) {
		this->transform_.pParent_ = &(parent->transform_);
	}
}

GameObject::~GameObject()
{
}

void GameObject::Release()
{
}

void GameObject::UpdateSub()
{
	Update();
	RoundRobin(GetRootJob());

	for (auto itr : childList_)
	{
		itr->UpdateSub();
	}
	for (auto itr = childList_.begin(); itr != childList_.end();)
	{
		if ((*itr)->isDead_) {
			(*itr)->ReleaseSub();
			SAFE_DELETE(*itr);
			itr = childList_.erase(itr);
		}
		else
		{
			itr++;
		}
	}
}

void GameObject::DrawSub()
{
	Draw();
	for (auto itr : childList_)
	{
		itr->DrawSub();
	}
}

void GameObject::ReleaseSub()
{
	Release();
	for (auto itr : childList_)
	{
		itr->ReleaseSub();
	}
}

void GameObject::KillMe()
{
	isDead_ = true;
}

GameObject* GameObject::FindObject(string objName)
{
	//自分からみたrootjobを探して
	//そのroogjobから全部の子を辿ってobjnameを探す
	GameObject* rootJob = GetRootJob();
	GameObject* res = rootJob->FindChildObject(objName);
	return (res);
}

GameObject* GameObject::GetRootJob()
{
	if (pParent_ == nullptr){
		return this;
	}
	return pParent_->GetRootJob();
}

GameObject* GameObject::FindChildObject(string objName)
{
	if (this->objectName_ == objName)
	{
		return this;
	}
	else
	{
		for (auto itr : childList_)
		{
			GameObject* obj = itr->FindChildObject(objName);
			if(obj != nullptr)
				return obj;
		}
	}
	return nullptr;
}

void GameObject::AddCollider(SphereCollider* pColl)
{
	pCollider_ = pColl;

}

void GameObject::Collision(GameObject* pTarget)
{
	if (this->pCollider_ == nullptr || pTarget->pCollider_ == nullptr || pTarget == this)
	{
		return;
	}

	//自分とターゲットのコライダー同士の当たり判定
	
	XMVECTOR p1 = XMLoadFloat3(&transform_.position_);
	XMVECTOR p2 = XMLoadFloat3(&pTarget->transform_.position_);
	
	float dist = XMVectorGetX(XMVector3Length(p1 - p2));//thisとtargetの距離
	float rDist = this->pCollider_->GetRadius() + pTarget->pCollider_->GetRadius();//thisとtargetの半径の合計
	if (dist <= rDist)
	{//二点間の距離 >= this とtargetの半径の合計
		//当たってるときの処理	
  		OnCollision(pTarget);
	}
}

void GameObject::RoundRobin(GameObject* pTarget)
{
	//自分とターゲットの当たり判定
	if (this->pCollider_ == nullptr) {
		return;
	}
	if (pTarget->pCollider_ != nullptr){
		Collision(pTarget);
	}

	//自分とターゲットの子オブジェクト全部の当たり判定（再帰処理）
	for (auto itr : pTarget->childList_)
	{
		RoundRobin(itr);
	}
}
