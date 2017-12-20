#include"SceneManager.h"
#include"../BehaviourComponents/MeshRenderer.h"
#include"../DataStructures/Mesh.h"
#include"glm/glm.hpp"

SceneManager::SceneManager(){

}

void SceneManager::OnInit(){
	LoadEmptyScene();
}

void SceneManager::OnLoop(){
	currentScene.OnLoop();
}

void SceneManager::OnRender(){
	currentScene.OnRender();
}

void SceneManager::OnQuit(){
	currentScene.OnQuit();
}

Scene& SceneManager::GetCurrentScene(){
	return currentScene;
}

void SceneManager::LoadScene(){

}

void SceneManager::LoadEmptyScene(){
	currentScene = Scene();
	currentScene.OnInit();
}

void SceneManager::SubscriberReceiver(SDL_Event *event){}
void SceneManager::SubscribeForEvents(){}
