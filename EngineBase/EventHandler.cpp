#include"EventHandler.h"

EventHandler::EventHandler(){
	inputEventHandler = NULL;
	windowEventHandler = NULL;
	quitEventHandler = NULL;
}

void EventHandler::PollEvents(){
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_KEYUP || event.type == SDL_KEYDOWN){

			if(inputEventHandler){
				inputEventHandler->SubscriberReceiver(&event);
			}
		} else if(event.type == SDL_WINDOWEVENT){
			if(windowEventHandler){
				windowEventHandler->SubscriberReceiver(&event);
			}
		} else if(event.type == SDL_QUIT){
			if(quitEventHandler){
				quitEventHandler->SubscriberReceiver(&event);
			}
		}
	}
}

void EventHandler::RegisterInputEventHandler(GenericManager *inputMan){
	inputEventHandler = inputMan;
}

void EventHandler::RegisterWindowEventHandler(GenericManager *windowMan){
	windowEventHandler = windowMan;
}

void EventHandler::RegisterQuitEventHandler(GenericManager *quitMan){
	quitEventHandler = quitMan;
}

void EventHandler::SubscriberReceiver(SDL_Event *event){}
void EventHandler::SubscribeForEvents(){}
