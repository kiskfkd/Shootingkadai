#include "GameOverScene.h"
#include"SceneManager.h"
#include"Input.h"
GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"GameOverScene"), hImage_(-1), spr_(nullptr)
{
}

void GameOverScene::Initialize()
{
	spr_ = new Sprite();
	hImage_ = spr_->Load("Assets//gameover.png");
}

void GameOverScene::Update()
{
	if (Input::IsKeyUp(DIK_P)) {
		SceneManager* ps = (SceneManager*)FindObject("SceneManager");
		ps->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameOverScene::Draw()
{
	Transform trs;
	trs.position_ = { 0,0,0 };
	trs.scale_ = { 0.5,0.5,0.5 };
	spr_->Draw(trs);
}

void GameOverScene::Release()
{
}
