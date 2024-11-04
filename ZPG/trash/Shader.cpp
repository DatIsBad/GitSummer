#include "Shader.h"

Shader::Shader(const char* vertex_shader, const char* fragment_shader) : 
	m_vertex_shader(vertex_shader), m_fragment_shader(fragment_shader) {
	
	//create and compile shaders
	GLuint m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_vertexShader, 1, &m_vertex_shader, NULL);
	glCompileShader(m_vertexShader);
	GLuint m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_fragmentShader, 1, &m_fragment_shader, NULL);
	glCompileShader(m_fragmentShader);
	m_shaderProgram = glCreateProgram();
	glAttachShader(m_shaderProgram, m_fragmentShader);
	glAttachShader(m_shaderProgram, m_vertexShader);
	glLinkProgram(m_shaderProgram);
}

Shader::Shader() {
	const char* vs =
		"#version 330\n"
		"layout(location=0) in vec3 vp;"
		"layout(location=1) in vec3 normal;"
		"uniform mat4 modelMatrix;"
		"out vec3 color;"
		"void main () {"
		"     color = vp;"
		"     gl_Position = vec4 (vp, 1.0);"
		"}";



	const char* fs =
		"#version 330\n"
		"out vec4 frag_colour;"
		"in vec3 color;"
		"void main () {"
		"	frag_colour = vec4 (color, 1.0);"
		"}";

	Shader(vs, fs);
}

Shader::~Shader() {

}

void Shader::useShaderProgram() {
	glUseProgram(m_shaderProgram);
}

int Shader::checkShaderProgram() {
	GLint status;
	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(m_shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(m_shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;

		return -1;
	}

	return 1;
}

void Shader::useShaderMatrix(glm::mat4 matrix) {
	//TODO
}
