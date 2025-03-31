#include "TitleScene.h"
#include"SceneManager.h"
#include"Input.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene")
{
}

void TitleScene::Initialize()
{
	spr_ = new Sprite();
	hImage_ = spr_->Load("Assets//title_oden.png");
	
}

void TitleScene::Update()
{
	if (Input::IsKeyUp(DIK_SPACE)) {
		SceneManager* ps = (SceneManager*)FindObject("SceneManager");
		ps->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	Transform trs;
	trs.position_ = { 0,0,0 };
	trs.scale_ = { 1,1,1 };
	spr_->Draw(trs);
}

void TitleScene::Release()
{
}
