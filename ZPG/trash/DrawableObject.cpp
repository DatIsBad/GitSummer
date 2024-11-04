#include "DrawableObject.h"

DrawableObject::DrawableObject() {
	//m_models = new std::vector<Model>;
	m_transf = new std::vector<Transformation>;
}

DrawableObject::~DrawableObject() {

	for (Model* model : m_models) {
		delete model;  
	}

	//delete m_models;
	delete m_transf;
}

void DrawableObject::addModel(int model) {
	if (model == 0) {
		m_models.push_back(new Model("bushes"));
	}
	else if (model == 1) {
		m_models.push_back(new Model("gift"));
	}
	else if (model == 2) {
		m_models.push_back(new Model("sphere"));
	}
	else if (model == 3) {
		m_models.push_back(new Model("tree"));
	}
	else if (model == 4) {
		m_models.push_back(new Model("suzi_flat"));
	}
	else if (model == 5) {
		m_models.push_back(new Model("suzi_smooth"));
	}
}

void DrawableObject::addModel() {
	std::srand(std::time(nullptr));	//current time is seed
	int num = std::rand() % 6; //generate numbers <0;5>

	addModel(num);
}

int DrawableObject::drawModels() {
	int check = 0;

	for (Model* val : m_models) {
		check = val->drawModel();
		if (check == -1) break;
	}
	

	return check;
}