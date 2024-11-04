#pragma once
#include<iostream>
#include<vector>

#include "Shader.h"
#include "DrawableObject.h"

class Scene
{
public:
	Scene();
	~Scene();
	int runScene(); //TODO
	void addDOShader();
	void addDOShader(const char* vertex_shader, const char* fragment_shader);
	void addModel(int doID, int model);
	void addModel(int doID);
	

private:
	std::vector<Shader> m_shaders;
	std::vector<DrawableObject> m_DO;
};

