#ifndef MATERIAL_H
#define MATERIAL_H

#include<GL/glew.h>
#include<string>
#include<glm/glm.hpp>

class Material {
private:
	GLuint shaderProgram;
	GLuint vertexShader, fragmentShader;

public:
	std::string ReadFile(const char *file);
	bool LoadShader(std::string file);
	bool LoadVertexShader(const std::string &filename);
	bool LoadFragmentShader(const std::string &filename);
	bool LinkShaders();
	void PrintShaderLinkingError(int32_t shaderId);
	void PrintShaderCompilationErrorInfo(int32_t shaderId);
	void SetMVPMatrix(glm::mat4 mat);

	void OnInit();
	void OnRenderBegin();
	void OnRenderEnd();
	void OnQuit();
};

#endif
