#ifndef BEHAVIOURCOMPONENT_H
#define BEHAVIOURCOMPONENT_H

#include"Behaviour.h"
#include"../EngineBase/GameObject.h"

class BehaviourComponent : public Behaviour {};

#endif
/*
## Each component must declare and implement the same body:

class ComponentName : public BehaviourComponent {
public:
	ComponentName();
	~ComponentName();

	void OnInit();
	void OnRender();
	void OnQuit();
	void Start();
	void Update();
	void OnDestroy();
}
//*/
