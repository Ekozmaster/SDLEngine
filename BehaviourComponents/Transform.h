#ifndef TRANSFORM_H
#define TRANSFORM_H

#include"BehaviourComponent.h"
#include<glm/glm.hpp>
#include<glm/gtc/quaternion.hpp>

class Transform : public BehaviourComponent {
public:
	glm::vec3 position;
	glm::quat rotation;
	glm::vec3 scale;

	Transform();
	~Transform();
	glm::mat4 GetModelViewMatrix();

	void OnInit();
	void OnRender();
	void OnQuit();
	void Start();
	void Update();
	void OnDestroy();
};

#endif
