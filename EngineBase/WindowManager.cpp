#include<SDL2/SDL.h>
#include"EngineHub.h"
#include"EventHandler.h"
#include"WindowManager.h"

WindowManager::WindowManager(){
	running = false;
}

bool WindowManager::OnInit(){
	if(!LoadSystemWindows()) return false;
	running = true;
	return true;
}

void WindowManager::OnLoop(){
	//if(!mainWindow.IsRunning()) running = false;
}

void WindowManager::OnRender(){
	mainWindow.Show();
}

void WindowManager::OnQuit(){
	mainWindow.Destroy();
}

bool WindowManager::IsRunning(){
	return running;
}

bool WindowManager::LoadSystemWindows(){
	mainWindow = AppWindow(50, 50, 400, 400);
	if(!mainWindow.Init()) return false;
	return true;
}

AppWindow *WindowManager::GetMainWindow(){
	return &mainWindow;
}

void WindowManager::SubscriberReceiver(SDL_Event *event){
	if(event->type == SDL_QUIT){
		running = false;
	}
};

void WindowManager::SubscribeForEvents(){
	((EventHandler*)(EngineHub::Instance().eventManager))->RegisterWindowEventHandler(this);
	((EventHandler*)(EngineHub::Instance().eventManager))->RegisterQuitEventHandler(this);
}
