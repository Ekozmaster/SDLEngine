#include"EngineBase/Application.h"
#include<iostream>


int main(int argc, char **argv){
	Application app = Application();
	if(!app.OnInit()){
		app.OnQuit();
		return -1;
	}



	// Main Loop
	while(app.IsRunning()){
		app.OnLoop();
		app.OnRender();
	}
	app.OnQuit();
	return 0;
}
