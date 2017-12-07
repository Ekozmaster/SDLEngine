#ifndef GENERICMANAGER_H
#define GENERICMANAGER_H

#include<SDL2/SDL.h>

class GenericManager {
public:
	virtual ~GenericManager(){};
	virtual void SubscriberReceiver(SDL_Event *event)=0;
	virtual void SubscribeForEvents()=0;
};

#endif
