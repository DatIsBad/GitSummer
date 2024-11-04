#include "Scene.h"

Scene::Scene() {
	m_DO.push_back(DrawableObject());
	m_DO[0].addModel(3);
	//m_shaders.push_back(Shader());
}

Scene::~Scene() {
	
}

int Scene::runScene() {
	int ret_value = 1;

	//TODO
	for (int k = 0; k < m_shaders.size(); k++) {
		m_shaders[k].useShaderProgram();
		m_DO[k].drawModels();
	}

	for (int i = 0; i < m_shaders.size(); i++) {
		if (m_shaders[i].checkShaderProgram() == -1)
		{
			ret_value = -1;
		}
	}

	return ret_value;
}

void Scene::addDOShader() {
	m_DO.push_back(DrawableObject());
	m_shaders.push_back(Shader());
}

void Scene::addDOShader(const char* vertex_shader, const char* fragment_shader) {
	m_DO.push_back(DrawableObject());
	m_shaders.push_back(Shader(vertex_shader, fragment_shader));
}

void Scene::addModel(int doID, int model) { //choose model
	m_DO[doID].addModel(model);
}

void Scene::addModel(int doID) {	//chooses random model
	m_DO[doID].addModel();
}