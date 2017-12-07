#ifndef EVENTHANDLER_h
#define EVENTHANDLER_H

#include<SDL2/SDL.h>
#include"GenericManager.h"

// Publish/Subscribe system to poll and redirect SDL_Events.
class EventHandler : public GenericManager {
	SDL_Event event;
	GenericManager *inputEventHandler;
	GenericManager *windowEventHandler; // TODO: Change to LinkedList of subscribers;
	GenericManager *quitEventHandler;

public:
	EventHandler();
	void PollEvents();

	void RegisterInputEventHandler(GenericManager *inputMan);
	void RegisterWindowEventHandler(GenericManager *windowMan);
	void RegisterQuitEventHandler(GenericManager *quitMan);

	void SubscriberReceiver(SDL_Event *event);
	void SubscribeForEvents();
};

#endif
