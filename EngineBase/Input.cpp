#include"Input.h"
#include"EngineHub.h"
#include"EventHandler.h"

Input::Input(){
	for(int i=0; i<keysMapped; i++){
		keysState[i] = false;
	}
}


bool Input::GetKey(int keyCode){
	if(keyCode >= 0 && keyCode < keysMapped){
		return keysState[keyCode];
	}
	return false;
}

void Input::SubscriberReceiver(SDL_Event *event){
	keysState[KeyCodeToIdx::LeftControl] = event->key.keysym.mod & KMOD_LCTRL;
	keysState[KeyCodeToIdx::RightControl] = event->key.keysym.mod & KMOD_RCTRL;
	keysState[KeyCodeToIdx::LeftShift] = event->key.keysym.mod & KMOD_LSHIFT;
	keysState[KeyCodeToIdx::RightShift] = event->key.keysym.mod & KMOD_RSHIFT;
	keysState[KeyCodeToIdx::LeftAlt] = event->key.keysym.mod & KMOD_LALT;
	keysState[KeyCodeToIdx::RightAlt] = event->key.keysym.mod & KMOD_RALT;

	if(event->type == SDL_KEYDOWN){
		keysState[SDLKToKeyCodeIdx[event->key.keysym.sym]] = true;
	} else if (event->type == SDL_KEYUP){
		keysState[SDLKToKeyCodeIdx[event->key.keysym.sym]] = false;
	}
}

void Input::SubscribeForEvents(){
	((EventHandler*)(EngineHub::Instance().eventManager))->RegisterInputEventHandler(this);
}
