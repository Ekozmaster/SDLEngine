#ifndef RENDERER_H
#define RENDERER_H

#include<SDL2/SDL.h>
#include"GenericManager.h"

class Renderer : public GenericManager {
private:
	SDL_GLContext glContext;

	void SetupSDLGLSettings();
public:
	Renderer();
	~Renderer();
	bool Setup(SDL_Window *window);
	void Render();
	void Destroy();
	void SubscriberReceiver(SDL_Event *event);
	void SubscribeForEvents();
};

#endif
