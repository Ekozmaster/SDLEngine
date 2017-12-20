#ifndef CAMERA_H
#define CAMERA_H

#include"BehaviourComponent.h"
#include<glm/glm.hpp>

class Camera : public BehaviourComponent {
private:
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
public:
	static Camera *main;
	float fov, nearClippingPlane, farClippingPlane;
	Camera();
	Camera(float FOV, float nearPlane, float farPlane);
	~Camera();
	glm::mat4 GetCameraMatrix();

	void OnInit();
	void OnRender();
	void OnQuit();
	void Start();
	void Update();
	void OnDestroy();
};

#endif
