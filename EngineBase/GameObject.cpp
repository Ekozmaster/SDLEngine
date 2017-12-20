#include"GameObject.h"
#include"../BehaviourComponents/Transform.h"

GameObject::GameObject(){
	uniqueID=-1;
	name = "Game Object";
	components = LinkedList<Behaviour*>();
}

GameObject::GameObject(std::string gmName){
	uniqueID=-1;
	name = gmName;
	components = LinkedList<Behaviour*>();
}

Behaviour *GameObject::GetTransform(){
	return components.head->data;
}

void GameObject::OnInit(){
	AddComponent<Transform>();
}

void GameObject::OnLoop(){
	LinkedList_Node<Behaviour*> *temp = components.head;
	while(temp){
		if(!temp->data->IsInitialized()){
			temp->data->Start();
			temp->data->SetInitialized();
		}
		temp->data->Update();
		temp = temp->next;
	}
}

void GameObject::OnRender(){
	LinkedList_Node<Behaviour*> *temp = components.head;
	while(temp){
		if(temp->data->IsInitialized()) temp->data->OnRender();
		temp = temp->next;
	}
}

void GameObject::OnQuit(){
	LinkedList_Node<Behaviour*> *temp = components.tail;
	while(temp){
		temp->data->OnDestroy();
		temp->data->OnQuit();
		delete(temp->data);
		temp = temp->prev;
		components.RemoveFromTail();
	}
}

void GameObject::SetUniqueID(int id){
	uniqueID = id;
}

int GameObject::GetUniqueID(){
	return uniqueID;
}

bool GameObject::operator==(const GameObject& gm){
	return uniqueID == gm.uniqueID;
}

bool GameObject::operator!=(const GameObject& gm){
	return uniqueID != gm.uniqueID;
}
