#include"Material.h"

#include <sstream>
#include <fstream>
#include <iostream>

#include<glm/gtc/type_ptr.hpp>

std::string Material::ReadFile(const char *file){
	std::ifstream t(file);
	std::stringstream buffer;
	buffer << t.rdbuf();
	std::string fileContent = buffer.str();
	return fileContent;
}

bool Material::LoadShader(std::string shaderName){
	shaderProgram = glCreateProgram();
	glBindAttribLocation(shaderProgram, 0, "in_Position");
	std::string vertexFilePath = "Resources/Shaders/" + shaderName + ".vert";
	std::string fragmentFilePath = "Resources/Shaders/" + shaderName + ".frag";

	if (!LoadVertexShader(vertexFilePath)) return false;
	if (!LoadFragmentShader(fragmentFilePath)) return false;
	bool result = LinkShaders();
	if(result) glUseProgram(shaderProgram);
	return result;
}

bool Material::LoadVertexShader(const std::string &filename)
{
	std::string str = ReadFile(filename.c_str());
	char* src = const_cast<char*>( str.c_str());
	int32_t size = str.length();

	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &src, &size);
	glCompileShader(vertexShader);

	int wasCompiled = 0;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &wasCompiled );
	if (wasCompiled == 0){
		PrintShaderCompilationErrorInfo(vertexShader);
		return false;
	}

	glAttachShader(shaderProgram, vertexShader);
	return true;
}

bool Material::LoadFragmentShader(const std::string &filename)
{
	std::string str = ReadFile(filename.c_str());
	char* src = const_cast<char*>( str.c_str());
	int32_t size = str.length();

	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &src, &size);
	glCompileShader(fragmentShader);

	int wasCompiled = 0;
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &wasCompiled );
	if (wasCompiled == false){
		PrintShaderCompilationErrorInfo(fragmentShader);
		return false;
	}

	glAttachShader(shaderProgram, fragmentShader);
	return true;
}

bool Material::LinkShaders(){
	glLinkProgram(shaderProgram);
	int isLinked;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == false) PrintShaderLinkingError(shaderProgram);
	return isLinked != 0;
}

void Material::PrintShaderLinkingError(int32_t shaderId){
	std::cout << "=======================================\n";
	std::cout << "Shader linking failed : " << std::endl;

	int maxLength;
	glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
	std::cout << "Info Length : " << maxLength << std::endl;
	char* shaderProgramInfoLog = new char[maxLength];
	glGetProgramInfoLog(shaderProgram, maxLength, &maxLength, shaderProgramInfoLog);
	std::cout << "Linker error message : " << shaderProgramInfoLog << std::endl;

	delete shaderProgramInfoLog;
	return;
}

// If something went wrong whil compiling the shaders, we'll use this function to find the error
void Material::PrintShaderCompilationErrorInfo(int32_t shaderId)
{
	std::cout << "=======================================\n";
	std::cout << "Shader compilation failed : " << std::endl;

	int maxLength;
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
	char* shaderInfoLog = new char[maxLength];
	glGetShaderInfoLog(shaderId, maxLength, &maxLength, shaderInfoLog );
	std::cout << "\tError info : " << shaderInfoLog << std::endl;

	std::cout << "=======================================\n\n";
	delete shaderInfoLog;
}

void Material::SetMVPMatrix(glm::mat4 mat){
	float *MVPMatrix = glm::value_ptr(mat);
	GLuint MVPMatrixUniform = glGetUniformLocation(shaderProgram, "MVPMatrix");
	glUniformMatrix4fv(MVPMatrixUniform, 1, GL_FALSE, MVPMatrix);
}

void Material::OnInit(){

}

void Material::OnRenderBegin(){
	glUseProgram(shaderProgram);
}

void Material::OnRenderEnd(){
	glUseProgram(0);
}

void Material::OnQuit(){

}
