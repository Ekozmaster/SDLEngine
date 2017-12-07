#ifndef INPUT_H
#define INPUT_H

#include<SDL2/SDL.h>
#include"GenericManager.h"
#include"InputTables.h"

class Input : public GenericManager {
	const static int keysMapped = 53;
	bool keysState[keysMapped];
public:
	Input();
	bool GetKey(int keyCode);
	void SubscriberReceiver(SDL_Event *event);
	void SubscribeForEvents();
};

#endif
