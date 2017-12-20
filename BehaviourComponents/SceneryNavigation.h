#ifndef SCENERYNAVIGATION_H
#define SCENERYNAVIGATION_H

#include"BehaviourComponent.h"

class SceneryNavigation : public BehaviourComponent{
public:
	SceneryNavigation();
	~SceneryNavigation();

	void OnInit();
	void OnRender();
	void OnQuit();
	void Start();
	void Update();
	void OnDestroy();
};

#endif
