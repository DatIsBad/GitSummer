#pragma once
//Include GLM  
#include"Transformation.h"

class Translate : public Transformation
{
public:
	Translate(float x, float y, float z);
	glm::mat4 getValue() const override;
private:
	glm::vec3 translation;
};
