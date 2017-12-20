#ifndef SCENE_H
#define SCENE_H

#include "../DataStructures/LinkedList.h"
#include "GameObject.h"

class Scene {
	LinkedList<GameObject&> gameObjects;
public:
	Scene();
	void OnInit();
	void OnLoop(); // Runs everything on scene.
	void OnRender();
	void OnQuit();
	GameObject& CreateGameObject(); // Creates and attach the gameObject to the current scene.
	void DestroyGameObject(GameObject& gameObject);
	int GetAvailableGameObjectID();
};

#endif
