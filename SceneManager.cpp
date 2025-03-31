#include "SceneManager.h"
#include"TestScene.h"
#include"TitleScene.h"
#include"PlayScene.h"
#include"ClearScene.h"
#include"GameOverScene.h"

#include"Engine/Direct3D.h"
#include"Model.h"
SceneManager::SceneManager(GameObject* parent)
    :GameObject(parent,"SceneManager"),currentSceneID(SCENE_ID_TEST),nextSceneID(SCENE_ID_TEST)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID = SCENE_ID_TITLE;
	nextSceneID = currentSceneID;
	Instantiate<TitleScene>(this);
}

void SceneManager::Update()
{
    //次のシーンが現在のシーンと違う ＝ シーンを切り替えなければならない
    if (currentSceneID != nextSceneID)
    {
        //そのシーンのオブジェクトを全削除（子オブジェクトを全削除）
        /*for (auto itr : childList_)
        {
            itr->ReleaseSub();
            SAFE_DELETE(itr);
            childList_.clear();
        }
        Model::Release();*/
        auto scene = childList_.begin();
        (*scene)->ReleaseSub();
        SAFE_DELETE(*scene);
        childList_.clear();
        Model::Release();

        //ロードしたデータを全削除

        //次のシーンを作成
        switch (nextSceneID)
        {
        case SCENE_ID_TEST: Instantiate<TestScene>(this); break;
        case SCENE_ID_TITLE: Instantiate<TitleScene>(this); break;
        case SCENE_ID_PLAY: Instantiate<PlayScene>(this); break;
        case SCENE_ID_CLEAR: Instantiate<ClearScene>(this); break;
        case SCENE_ID_GAMEOVER: Instantiate<GameOverScene>(this); break;
        }

        //シーンを生成できたらカレントシーンを更新
        currentSceneID = nextSceneID;
    }
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}
