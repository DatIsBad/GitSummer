#include "Model.h"

Model::Model() {
	//vertex buffer object (VBO)
	VBO = 0;

	//Vertex Array Object (VAO)
	VAO = 0;

	triangles = -1;
}

Model::Model(const char* mod) {
	//vertex buffer object (VBO)
	VBO = 0;

	//Vertex Array Object (VAO)
	VAO = 0;

	if (strcmp(mod, "bushes") == 0) {
		setPoint(bushes, std::size(bushes));
	}
	else if (strcmp(mod, "gift") == 0) {
		setPoint(bushes, std::size(gift));
	}
	else if (strcmp(mod, "sphere") == 0) {
		setPoint(bushes, std::size(sphere));
	}
	else if (strcmp(mod, "tree") == 0) {
		setPoint(bushes, std::size(tree));
	}
	else if (strcmp(mod, "suzi_flat") == 0) {
		setPoint(bushes, std::size(suziFlat));
	}
	else if (strcmp(mod, "suzi_smooth") == 0) {
		setPoint(bushes, std::size(suziSmooth));
	}
	else {
		triangles = -1;
	}
}

void Model::setPoint(float arr[], int size) {
	triangles = size / 6;

	//vertex buffer object (VBO)
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, (4 * size), arr, GL_STATIC_DRAW); //(4 bites per element in array)

	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
}

void Model::setPoint(const float arr[], int size) {
	triangles = size / 6;

	//vertex buffer object (VBO)
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, (4 * size), arr, GL_STATIC_DRAW); //(4 bites per element in array)

	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(const float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(const float), (GLvoid*)(3 * sizeof(float)));
}

int Model::drawModel() {
	if (triangles > 0) {
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, triangles);
		return 1;
	}
	else {
		printf("Model is empty, thus impossible to bind\n");
		return -1;
	}
}