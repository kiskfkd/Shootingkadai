#pragma once
#include "Engine/GameObject.h"

enum SCENE_ID
{
	SCENE_ID_TEST = 0,
	SCENE_ID_TITLE,
	SCENE_ID_PLAY,
	SCENE_ID_CLEAR,
	SCENE_ID_GAMEOVER,
	SCENE_MAX
};

class SceneManager :
    public GameObject
{
	SCENE_ID currentSceneID;
	SCENE_ID nextSceneID;

public:
	SceneManager(GameObject* parent);
	~SceneManager() ;

	//ÉVÅ[ÉìêÿÇËë÷Ç¶()
	void ChangeScene(SCENE_ID nextScene)
	{
		nextSceneID = nextScene;
	}

	void Initialize();
	void Update();
	void Draw();
	void Release();
};

