#ifndef BEHAVIOUR_H
#define BEHAVIOUR_H

class GameObject;

class Behaviour{
	bool initialized;
protected:
	GameObject *attachedGameObject;
public:
	virtual ~Behaviour();
	virtual void OnInit()=0;
	virtual void OnRender()=0;
	virtual void OnQuit()=0;
	virtual void Start()=0;
	virtual void Update()=0;
	virtual void OnDestroy()=0;

	void SetInitialized();
	bool IsInitialized();
	void SetAttachedGameObject(GameObject *gm);
	GameObject *GetGameObject();
};

#endif
