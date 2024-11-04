#pragma once
#include<iostream>
#include<vector>

//to choose random model + random transformations
#include <cstdlib>
#include <ctime>

#include"Model.h"
#include"Transformation.h"

class DrawableObject
{
public:
	DrawableObject();
	~DrawableObject();
	void addModel(int model);
	void addModel();
	int drawModels(); //TODO
	

private:
	std::vector<Model*> m_models;
	std::vector<Transformation> *m_transf;
};

