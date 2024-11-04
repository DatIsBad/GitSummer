#include "Buffer.h"

Buffer::Buffer() {
	//vertex buffer object (VBO)
	VBO = 0;

	//Vertex Array Object (VAO)
	VAO = 0;
}

void Buffer::addPoint(float arr[], int size) {
	//vertex buffer object (VBO)
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER,(4 * size), arr, GL_STATIC_DRAW); //(4 bites per element in array)

	//Vertex Array Object (VAO)
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (GLvoid*)(3 * sizeof(float)));
}

void Buffer::addPoint(const float arr[], int size) {
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

void Buffer::addPoint(Object obj) {
	addPoint(obj.getPoints(), obj.getSize());
}

void Buffer::addPoint() {
	float points[] = {
	0.0f, 0.5f, 0.0f, 0, 0, 1,
	0.5f, -0.5f, 0.0f, 0, 0, 1,
	-0.5f, -0.5f, 0.0f, 0, 0, 1
	};

	addPoint(points, 18);
}


void Buffer::bindVAO() {
	glBindVertexArray(VAO);
}