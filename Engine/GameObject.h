#pragma once
#include <string>
#include<list>
#include<string>
#include"Transform.h"

using std::string;

class SphereCollider;

class GameObject
{
	bool isDead_;

protected:
	std::list<GameObject*>childList_;
	Transform transform_;
	GameObject* pParent_;
	std::string objectName_;
	SphereCollider* pCollider_;
	int Hp_;
public:
	GameObject();
	GameObject(GameObject* parent, const std::string& name);
	~GameObject();

	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
	void UpdateSub();
	void DrawSub();
	void ReleaseSub();

	void KillMe();
	int GetHp() { return Hp_; }
	void SetHp(int hp) { Hp_ = hp; }
	void Damage() { Hp_--; }

	//inline定義
	void SetPosition(XMFLOAT3 position)
	{
		transform_.position_ = position;
	}
	void SetPosition(float x, float y, float z)
	{
		SetPosition(XMFLOAT3(x, y, z));
	}
	void SetScale(float sx, float sy, float sz) {
		transform_.scale_ = { sx,sy,sz };
	}
	void SetRotateX(float xrotate) { transform_.position_.x = xrotate; }
	void SetRotateY(float yrotate) { transform_.position_.y = yrotate; }
	void SetRotateZ(float zrotate) { transform_.position_.z = zrotate; }

	int GetPositionX() { return transform_.position_.x; }
	int GetPositionY() { return transform_.position_.y; }
	int GetPositionZ() { return transform_.position_.z; }
	XMFLOAT3 GetPosition() { return transform_.position_; }

	GameObject* FindObject(string objName);
	GameObject* GetRootJob();
	GameObject* FindChildObject(string objName);
	void AddCollider(SphereCollider* pColl);
	void Collision(GameObject* pTarget);
	void RoundRobin(GameObject* pTarget);
	virtual void OnCollision(GameObject* pTarget) {};

	//template <typename T>//クラスならclassとかく　ほぼ同じ
	template <class T> //tポインタ型　仮引数のクラスに合わせた引数
	T* Instantiate(GameObject* pParent)
	{
		T* pTmp = new T(pParent);
		if (pTmp != nullptr)
		{
			pTmp->Initialize();
			childList_.push_back(pTmp);
		}
		return pTmp;
	}
};

