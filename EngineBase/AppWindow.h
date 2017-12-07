#ifndef APPWINDOW_H
#define APPWINDOW_H
#include<SDL2/SDL.h>
#include"Renderer.h"

class AppWindow {
private:
	int x, y, w, h;
	bool fullscreen, running;
	SDL_Window *window;
	Renderer renderer;

public:
	AppWindow();
	AppWindow(int posX, int posY, int width, int height);
	AppWindow(int width, int height);
	~AppWindow();
	void SetSize(int width, int height);
	void SetPos(int posX, int posY);
	bool IsRunning();
	SDL_Window *GetSDLWindow();
	Renderer *GetRenderer();

	// Application Window Flow
	bool Init();
	void Show();
	void Destroy();

};

#endif
