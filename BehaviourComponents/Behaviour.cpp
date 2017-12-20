#include"Behaviour.h"

// Just to have a definition.
Behaviour::~Behaviour(){};
void Behaviour::OnInit(){}
void Behaviour::OnRender(){}
void Behaviour::OnQuit(){}
void Behaviour::Start(){}
void Behaviour::Update(){}
void Behaviour::OnDestroy(){}

void Behaviour::SetInitialized(){
	initialized = true;
}

bool Behaviour::IsInitialized(){
	return initialized;
}

void Behaviour::SetAttachedGameObject(GameObject *gm){
	attachedGameObject = gm;
}

GameObject *Behaviour::GetGameObject(){
	return attachedGameObject;
}
