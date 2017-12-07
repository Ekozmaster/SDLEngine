#ifndef ENGINEHUB_H
#define ENGINEHUB_H

#include"GenericManager.h"

// Singleton used to store all important objects used in the whole engine.
class EngineHub {
private:
	EngineHub(){};
	~EngineHub(){
		if(sceneManager) delete sceneManager;
		if(inputManager) delete inputManager;
		if(rendererManager) delete rendererManager;
		if(eventManager) delete eventManager;
		if(windowManager) delete windowManager;
	};
public:
	static EngineHub& Instance(){
		static EngineHub instance;
		return instance;
	}
	static GenericManager *sceneManager;
	static GenericManager *inputManager;
	static GenericManager *rendererManager;
	static GenericManager *eventManager;
	static GenericManager *windowManager;

	// Blocking constructors and assigns.
	EngineHub(EngineHub const&) = delete;
	EngineHub(EngineHub&&) = delete;
	EngineHub& operator=(EngineHub const&) = delete;
	EngineHub& operator=(EngineHub&&) = delete;
};

#endif
