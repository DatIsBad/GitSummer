#include "Scene.h"

Scene::Scene() {
	//m_model = new Model("sphere");
	std::srand(std::time(nullptr));	//current time is seed
	addDObjShader();
	m_cam = new Camera();
	m_lastCursorX = 0;
	m_lastCursorY = 0;
}

Scene::~Scene() {
	for (Shader* shader : m_shaders) {
		delete shader;  // Manually delete each allocated Shader object
	}

	for (DrawableObject* m_dobj : m_DObj) {
		delete m_dobj;  // Manually delete each allocated DrawableObject object
	}
	delete m_cam;
}

int Scene::runScene() {
	//get deltaTime
	float currentFrame = glfwGetTime();
	m_deltaTime = currentFrame - m_lastFrame;
	m_lastFrame = currentFrame;

	//draw all models
	for (size_t  i = 0; i < m_shaders.size(); ++i) {
		Shader* shader = m_shaders[i];
		DrawableObject* DObj = m_DObj[i];

		if (shader) {
			shader->useShaderProgram();
			shader->useViewMatrix(m_cam->GetViewMatrix());
			DObj->drawModels(shader);
		}
	}

	//check for shader errors
	for (Shader* shader : m_shaders) {
		// Access each Shader* in the vector
		if (shader->checkShaderProgram() == -1)
		{
			return -1;
		}
	}


	return 1;
}

void Scene::addDObjShaderOneColor() {
	m_DObj.push_back(new DrawableObject());
	m_shaders.push_back(new Shader(glm::vec3( (float)(std::rand() % 100) / (float)100, (float)(std::rand() % 100) / (float)100, (float)(std::rand() % 100) / (float)100) ));
}

void Scene::addDObjShader() {
	m_DObj.push_back(new DrawableObject());
	m_shaders.push_back(new Shader());
}

void Scene::addDObjShader(const char* vertex_shader, const char* fragment_shader) {
	m_DObj.push_back(new DrawableObject());
	m_shaders.push_back(new Shader(vertex_shader, fragment_shader));
}

void Scene::addModel(int doID, int model) { //choose model
	DrawableObject* DObj = m_DObj[doID];
	DObj->addModel(model);
}


void Scene::addRotationObjModel(int doID, int moID, float angle, glm::vec3 rotation) {
	DrawableObject* DObj = m_DObj[doID];
	DObj->addRotationModel(moID, angle, rotation);
}

void Scene::Scene::addScaleObjModel(int doID, int moID, glm::vec3 scaleValue) {
	DrawableObject* DObj = m_DObj[doID];
	DObj->addScaleModel(moID, scaleValue);
}


void Scene::addTranslationObjModel(int doID, int moID, glm::vec3 translation) {
	DrawableObject* DObj = m_DObj[doID];
	DObj->addTranslationModel(moID, translation);
}

void Scene::updateObservedKey(char userInput) {
	m_cam->ProcessKeyboard(userInput, m_deltaTime);
}

void Scene::updateObservedCursor(double x, double y) {
	float xtemp = x - m_lastCursorX;
	float ytemp = m_lastCursorY - y;

	printf("%f %f\n", xtemp, ytemp);
	m_cam->ProcessCursorMovemment(xtemp, ytemp, true);
	m_lastCursorX = x;
	m_lastCursorY = y;
}