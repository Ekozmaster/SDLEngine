#ifndef APPLICATION_H
#define APPLICATION_H

#include<SDL2/SDL.h>

class Application {
	bool running;
	void SetupSystems();

public:
	Application();
	~Application();

	// Application base flow
	bool OnInit();
	void OnLoop();
	void OnRender();
	void OnQuit();

	// Properties
	bool IsRunning();
};

#endif
