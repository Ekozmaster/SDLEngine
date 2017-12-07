#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include"GenericManager.h"
#include"AppWindow.h"

class WindowManager : public GenericManager {
	bool running = false;
	AppWindow mainWindow;
public:
	WindowManager();

	bool OnInit();
	void OnLoop();
	void OnRender();
	void OnQuit();

	bool IsRunning();
	bool LoadSystemWindows();
	AppWindow *GetMainWindow();
	void SubscriberReceiver(SDL_Event *event);
	void SubscribeForEvents();
};

#endif
