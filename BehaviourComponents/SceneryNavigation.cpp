#include"SceneryNavigation.h"
#include"../EngineBase/EngineHub.h"
#include"../EngineBase/Input.h"
#include"Camera.h"
#include"Transform.h"

SceneryNavigation::SceneryNavigation(){

}
SceneryNavigation::~SceneryNavigation(){

}

void SceneryNavigation::OnInit(){}
void SceneryNavigation::OnRender(){}
void SceneryNavigation::OnQuit(){}
void SceneryNavigation::Start(){}

void SceneryNavigation::Update(){
	Input* input = ((Input*)(EngineHub::Instance().inputManager));
	if(input->GetKey(KeyCodeToIdx.W)){

		Transform *camTransform = ((Transform*)(attachedGameObject->GetTransform()));
		camTransform->position += camTransform->rotation * (glm::vec3(0,0,1));
	} else if(input->GetKey(KeyCodeToIdx.S)){
		Transform *camTransform = ((Transform*)(attachedGameObject->GetTransform()));
		camTransform->position += camTransform->rotation * (glm::vec3(0,0,-1));
	}
	if(input->GetKey(KeyCodeToIdx.A)){
		Transform *camTransform = ((Transform*)(attachedGameObject->GetTransform()));
		camTransform->position += camTransform->rotation * (glm::vec3(-1,0,0));
	} else if (input->GetKey(KeyCodeToIdx.D)){
		Transform *camTransform = ((Transform*)(attachedGameObject->GetTransform()));
		camTransform->position += camTransform->rotation * (glm::vec3(1,0,0));
	}

}

void SceneryNavigation::OnDestroy(){}
