#include"Renderer.h"
#include<GL/glew.h>
#include"EngineHub.h"
#include"SceneManager.h"

Renderer::Renderer(){
	glContext = NULL;
}

Renderer::~Renderer(){
	SDL_GL_DeleteContext(glContext);
}

void Renderer::SetupSDLGLSettings(){
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

bool Renderer::Setup(SDL_Window *window){
	if(glContext) SDL_GL_DeleteContext(glContext);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	SetupSDLGLSettings();
	if(!glContext) return false;
	SDL_GL_SetSwapInterval(1);


	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//glViewport(0, 0, 400, 400);

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(0, 400, 400, 0, 1, -1);

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();

	return true;
}

void Renderer::Render(){
	glClearColor(0.4, 0.4, 0.4, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	((SceneManager*)(EngineHub::Instance().sceneManager))->OnRender();

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	/*
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
	//*/
}

void Renderer::Destroy(){
	SDL_GL_DeleteContext(glContext);
}

void Renderer::SubscriberReceiver(SDL_Event *event){}
void Renderer::SubscribeForEvents(){}
