#include"AppWindow.h"

AppWindow::AppWindow(){
	x = SDL_WINDOWPOS_CENTERED;
	y = SDL_WINDOWPOS_CENTERED;
	w = 640;
	h = 480;
	fullscreen = false;
	running = false;
	window = NULL;
	renderer = Renderer();
}

AppWindow::AppWindow(int posX, int posY, int width, int height){
	x = posX;
	y = posY;
	w = width;
	h = height;
	fullscreen = false;
	running = false;
	window = NULL;
	renderer = Renderer();
}

AppWindow::AppWindow(int width, int height){
	x = SDL_WINDOWPOS_CENTERED;
	y = SDL_WINDOWPOS_CENTERED;
	w = width;
	h = height;
	fullscreen = false;
	running = false;
	window = NULL;
	renderer = Renderer();
}

AppWindow::~AppWindow(){
	if(window) SDL_DestroyWindow(window);
}

bool AppWindow::IsRunning(){
	return running;
}

SDL_Window *AppWindow::GetSDLWindow(){
	return window;
}

Renderer *AppWindow::GetRenderer(){
	return &renderer;
}

bool AppWindow::Init(){
	// Creating Window Object
	window = SDL_CreateWindow("Fucking Game Engine", x, y, w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if(!window) return false;
	if(!renderer.Setup(window)) return false;
	running = true;
	return true;
}

void AppWindow::Show(){
	renderer.Render();
	SDL_GL_SwapWindow(window);
}

void AppWindow::Destroy(){
	renderer.Destroy();
	SDL_DestroyWindow(window);
	running = false;
}
