#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

class Shader
{
public:
	Shader(const char* vertex_shader, const char* fragment_shader);
	Shader();
	~Shader();
	void useShaderProgram();
	int checkShaderProgram();
	void useShaderMatrix(glm::mat4 matrix); //for transformations


private:
	const char* m_vertex_shader;
	const char* m_fragment_shader;
	GLuint m_shaderProgram;
};

