#include"Camera.h"
#include<glm/gtc/matrix_transform.hpp>
#include"Transform.h"

Camera *Camera::main = NULL;

Camera::Camera(){
	fov = 60.0;
	nearClippingPlane = 0.1;
	farClippingPlane = 100.0;
	if(! Camera::main)  Camera::main = this;
}

Camera::Camera(float FOV, float nearPlane, float farPlane){
	fov = FOV;
	nearClippingPlane = nearPlane;
	farClippingPlane = farPlane;
	if(! Camera::main)  Camera::main = this;
}

Camera::~Camera(){}

glm::mat4 Camera::GetViewMatrix(){
	Transform *transform = ((Transform*)(attachedGameObject->GetTransform()));
	return glm::lookAt(transform->position, transform->position + (glm::vec3)(transform->rotation * glm::vec4(0,0,1,1)), (glm::vec3)(transform->rotation * glm::vec4(0,1,0,1)));
}

glm::mat4 Camera::GetProjectionMatrix(){
	return glm::perspective(glm::radians(fov), 1.0f, nearClippingPlane, farClippingPlane);
}

glm::mat4 Camera::GetCameraMatrix(){
	return GetProjectionMatrix() * GetViewMatrix();
}

void Camera::OnInit(){};
void Camera::OnRender(){};
void Camera::OnQuit(){};
void Camera::Start(){};
void Camera::Update(){};
void Camera::OnDestroy(){};
