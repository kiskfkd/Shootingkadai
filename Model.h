#pragma once
#include<string>
#include<list>
#include"Engine/FBX.h"
#include"Engine/Transform.h"
using std::string;

namespace Model
{
	struct ModelData
	{
		FBX* pFBX_;
		Transform trans_;
		string Filename_;
		ModelData() :pFBX_(nullptr), Filename_("")
		{}
	};

	//モデルの一覧を保存する配列vectorかlist
	int Load(std::string filename);
	void SetTransform(int hModel,Transform transform);
	void Draw(int hModel);
	void Release();
	
}