#include"Model.h"
#include"Engine/Direct3D.h"

namespace Model
{
	std::vector<ModelData*> modelList_;
}
//namespaceは別のところからでも追加できる

int Model::Load(std::string filename)
{
	//file名のモデルを読み込む
	//同じモデルがすでに読み込まれていたらエラー-1を返す
	//初めての読み込みだったらモデルを読み込んで配列に追加

	ModelData* pData = new ModelData;//newすれば勝手には消えないが自分で消す必要ある
	pData->Filename_ = filename;
	pData->pFBX_ = nullptr;

	for (auto& e : modelList_)
	{
		if (e->Filename_ == filename)//同名のものは同じFBXを使ってtransformだけ変える
		{
			pData->pFBX_ = e->pFBX_;
			break;
		}
	}

	if (pData->pFBX_ == nullptr)//同名のファイルはリストにない
	{
		pData->pFBX_ = new FBX;
		pData->pFBX_->Load(filename);
	}
	modelList_.push_back(pData);
	return(modelList_.size() - 1);
}

void Model::SetTransform(int hModel, Transform transform)
{
	//handleはmodeldataに当てられたNoのこと
	modelList_[hModel]->trans_ = transform;

}

void Model::Draw(int hModel)
{
	modelList_[hModel]->pFBX_->Draw(modelList_[hModel]->trans_);
}

void Model::Release()
{
	bool isReferred = false;
	for (int j = 0; j < modelList_.size(); j++)
	{
		for (int i = j + 1; i < modelList_.size(); i++)
		{
			if (modelList_[j]->pFBX_ == modelList_[i]->pFBX_)
			{
				isReferred = true;
				break;
			}
		}
		if (!isReferred)
		{
			SAFE_DELETE(modelList_[j]->pFBX_);
		}
		SAFE_DELETE(modelList_[j]);
	}
	modelList_.clear();

}
