#include<GL/glew.h>
#include"Application.h"
#include"EngineHub.h"
#include"Input.h"
#include"SceneManager.h"
#include"Renderer.h"
#include"EventHandler.h"
#include"WindowManager.h"

Application::Application(){
	running = false;
}

Application::~Application(){
	// TODO: clear EngineHub instances.
}

void Application::SetupSystems(){
	SceneManager *sceneManager = new SceneManager();
	Input *input = new Input();
	EventHandler *eventHandler = new EventHandler();
	WindowManager *windowManager = new WindowManager();

	EngineHub::Instance().sceneManager = sceneManager;
	EngineHub::Instance().inputManager = input;
	EngineHub::Instance().eventManager = eventHandler;
	EngineHub::Instance().windowManager = windowManager;

	input->SubscribeForEvents();
	windowManager->SubscribeForEvents();
}

bool Application::OnInit(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0) return false;
	SetupSystems();
	WindowManager *windowManager = (WindowManager*)(EngineHub::Instance().windowManager);
	if(!windowManager->OnInit()) return false;
	glewExperimental = GL_TRUE;
	glewInit();
	running = true;
	return true;
}

// This function is called every frame.
void Application::OnLoop(){
	((EventHandler*)(EngineHub::Instance().eventManager))->PollEvents();
	SceneManager *sceneManager = ((SceneManager*)(EngineHub::Instance().sceneManager));
	WindowManager *windowManager = ((WindowManager*)(EngineHub::Instance().windowManager));

	sceneManager->OnLoop();
	windowManager->OnLoop();
	if(!windowManager->IsRunning()){
		running = false;
	}
}

// This function is called every frame.
void Application::OnRender(){
	((WindowManager*)(EngineHub::Instance().windowManager))->OnRender();
}

void Application::OnQuit(){
	((SceneManager*)(EngineHub::Instance().sceneManager))->OnQuit();
	((WindowManager*)(EngineHub::Instance().windowManager))->OnQuit();
	SDL_Quit();
}

bool Application::IsRunning(){
	return running;
}
