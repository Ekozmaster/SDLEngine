#include"EngineBase/Application.h"
#include<iostream>


#include<typeinfo>
#include"EngineBase/EngineHub.h"
#include"EngineBase/GameObject.h"
#include"EngineBase/SceneManager.h"
#include"BehaviourComponents/Transform.h"

#include"BehaviourComponents/MeshRenderer.h"
#include"BehaviourComponents/Camera.h"
#include"BehaviourComponents/SceneryNavigation.h"
void TestEngine(){
	//((SceneManager*)(EngineHub::Instance().sceneManager))->
	Scene& curScene = ((SceneManager*)(EngineHub::Instance().sceneManager))->GetCurrentScene();

	//#####################
	GameObject& gm = curScene.CreateGameObject();
	gm.AddComponent<MeshRenderer>();
	Mesh *mesh = new Mesh();
	glm::vec3 vertices[5];
	GLuint triangles[3];
	vertices[0] = (glm::vec3(-0.5, -0.5, 0.5));
	vertices[1] = (glm::vec3(-0.7, 0.5, 0.5));
	vertices[2] = (glm::vec3(0.0, 0.7, 0.5));
	vertices[3] = (glm::vec3(0.7, 0.5, 0.5));
	vertices[4] = (glm::vec3(0.5, -0.5, 0.5));

	triangles[0] = 0;
	triangles[1] = 1;
	triangles[2] = 2;
	mesh->SetVertices(vertices, 5);
	mesh->SetTriangles(triangles, 3);
	gm.GetComponent<MeshRenderer>()->SetMesh(mesh);
	//#####################

	GameObject &camera = curScene.CreateGameObject();
	camera.AddComponent<Camera>();
	((Transform*)(camera.GetTransform()))->position = glm::vec3(0.0, 0.0, 5.0);
	((Transform*)(camera.GetTransform()))->rotation = glm::quat(glm::vec3(0.0, glm::radians(180.0), 0.0));
	camera.AddComponent<SceneryNavigation>();
}


int main(int argc, char **argv){

	Application app = Application();
	if(!app.OnInit()){
		app.OnQuit();
		return -1;
	}

	TestEngine();
	while(app.IsRunning()){
		app.OnLoop();
		app.OnRender();
	}
	app.OnQuit();
	return 0;
}
