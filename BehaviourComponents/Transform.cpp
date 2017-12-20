#include"Transform.h"
#include<iostream>
#include<glm/gtx/transform.hpp>
#include<glm/gtx/quaternion.hpp>

Transform::Transform(){
	position = glm::vec3(0,0,0);
	rotation = glm::quat(0,0,0,1);
	scale = glm::vec3(1,1,1);
}

Transform::~Transform(){}

glm::mat4 Transform::GetModelViewMatrix(){
	glm::mat4 trans = glm::translate(glm::mat4(1.0), position);
	glm::mat4 rot = glm::toMat4(rotation);
	glm::mat4 scl = glm::scale(glm::mat4(1.0), scale);
	return trans * rot * scl;

}

void Transform::OnInit(){}

void Transform::OnRender(){
	// Here goes object matrixes computation to feed the shader.
}

void Transform::OnQuit(){}
void Transform::Start(){}
void Transform::Update(){}
void Transform::OnDestroy(){}
