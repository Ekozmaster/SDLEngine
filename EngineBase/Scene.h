#ifndef SCENE_H
#define SCENE_H

#include "../DataStructures/LinkedList.h"

class Scene {
public:
	// LinkedList<GameObjects> gameObjects;
	Scene();
	~Scene();
	//void RegisterObject(GameObject * object); // Adds a object to the execution queue.
	//void UnregisterObject(int id); // Remove object from execution queue.
	//GameObject *GetObjectByID(int id); // Get object from queue with id.
	//void MainUpdate(); // Runs everything on scene.
};

#endif
