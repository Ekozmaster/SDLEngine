#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "../BehaviourComponents/Behaviour.h"
#include "../DataStructures/LinkedList.h"
#include<string>

class GameObject {
private:
	int uniqueID;
public:
	std::string name;
	LinkedList<Behaviour*> components;
	GameObject();
	GameObject(std::string gmName);
	Behaviour *GetTransform();

	void OnInit();
	void OnLoop();
	void OnRender();
	void OnQuit();

	template<typename componentName>
	void AddComponent(){
		Behaviour *comp = new componentName();
		comp->SetAttachedGameObject(this);
		comp->OnInit();
		components.AddAtTail(comp);
	}

	template<typename componentName>
	void RemoveComponent(){
		LinkedList_Node<Behaviour*> * temp = components.head;
		int i=0;
		while(i<components.Length()){
			// If the node data has the same type of the required component.
			if(dynamic_cast<componentName*>(temp->data)){
				delete(temp->data);
				components.RemoveFromPos(i);
				return;
			}
			temp = temp->next;
			i++;
		}
	}

	template<typename componentName>
	componentName *GetComponent(){
		LinkedList_Node<Behaviour*> * temp = components.head;
		int i=0;
		while(i<components.Length()){
			// If the node data has the same type of the required component.
			if(dynamic_cast<componentName*>(temp->data)){
				return (componentName*)temp->data;
			}
			temp = temp->next;
			i++;
		}
		return NULL;
	}

	void SetUniqueID(int id);
	int GetUniqueID();

	bool operator==(const GameObject& gm);
	bool operator!=(const GameObject& gm);
};

#endif
