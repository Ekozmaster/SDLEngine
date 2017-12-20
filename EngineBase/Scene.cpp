#include"Scene.h"

Scene::Scene(){
	gameObjects = LinkedList<GameObject&>();
}

void Scene::OnInit(){}

void Scene::OnLoop(){
	LinkedList_Node<GameObject&> *temp = gameObjects.head;
	while(temp){
		temp->data.OnLoop();
		temp = temp->next;
	}
}

void Scene::OnRender(){
	LinkedList_Node<GameObject&> *temp = gameObjects.head;
	while(temp){
		temp->data.OnRender();
		temp = temp->next;
	}
}

void Scene::OnQuit(){
	LinkedList_Node<GameObject&> *temp = gameObjects.head;
	while(temp){
		temp->data.OnQuit();
		temp = temp->next;
		gameObjects.RemoveFromHead();
	}
}

GameObject& Scene::CreateGameObject(){// TODO: test
	GameObject *gm = new GameObject();
	gm->SetUniqueID(GetAvailableGameObjectID());
	gameObjects.AddAtTail(*gm);
	gm->OnInit();
	gm->name = std::string("Game Object " + std::to_string(gm->GetUniqueID()));
	return *gm;
}

void Scene::DestroyGameObject(GameObject& gameObject){// TODO: test
	int gmPos = gameObjects.GetPosByData(gameObject);
	if(gmPos >=0) gameObjects.RemoveFromPos(gmPos);
}

int Scene::GetAvailableGameObjectID(){ // TODO: Test
	int id=0;
	bool found = false;
	while(!found){
		bool exists = false;
		LinkedList_Node<GameObject&> *temp = gameObjects.head;
		while(temp && !exists){
			if(id == temp->data.GetUniqueID()) exists = true;
			temp = temp->next;
		}
		if(exists)id++;
		else found=true;
	}
	return id;
}
