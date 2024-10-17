#include "Triangle.h"

#include <GLFW/glfw3.h>

void Triangle::Update()
{
}

void Triangle::Draw()
{
	mShader->Use();

	mShader->SetVec3("color", glm::vec3(0.5, sin(glfwGetTime()), 0.3f));

	BaseEntity::Draw();
}
