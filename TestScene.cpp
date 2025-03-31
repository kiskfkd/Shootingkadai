#include "TestScene.h"
#include"SceneManager.h"
#include"Input.h"
TestScene::TestScene(GameObject* parent)
	:GameObject(parent,"TestScene")
{
}

void TestScene::Initialize()
{
}

void TestScene::Update()
{
	if (Input::IsKeyUp(DIK_SPACE)) {
		SceneManager* ps = (SceneManager*)FindObject("SceneManager");
		ps->ChangeScene(SCENE_ID_PLAY);
	}

}

void TestScene::Draw()
{
}

void TestScene::Release()
{
}
