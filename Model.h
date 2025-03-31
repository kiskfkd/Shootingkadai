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

	//ƒ‚ƒfƒ‹‚Ìˆê——‚ð•Û‘¶‚·‚é”z—ñvector‚©list
	int Load(std::string filename);
	void SetTransform(int hModel,Transform transform);
	void Draw(int hModel);
	void Release();
	
}