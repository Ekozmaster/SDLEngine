#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include"GenericManager.h"
#include"Scene.h"

class SceneManager : public GenericManager {
	Scene currentScene;
public:
	SceneManager();
	void OnInit();
	void OnLoop();
	void OnRender();
	void OnQuit();
	Scene& GetCurrentScene();
	void LoadScene(); // TODO: find a way to load from disk
	void LoadEmptyScene();
	void SubscriberReceiver(SDL_Event *event);
	void SubscribeForEvents();
};

#endif
