#include "Triangle.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Triangle::Triangle() :
    BaseEntity{ Type::TRIANGLE, glm::vec3{0.0f}, 2.0f, new Shader("./Source/Entities/Triangle/shaders/triangle.vert","./Source/Entities/Triangle/shaders/triangle.frag") }
{
}

void Triangle::Update()
{
}

void Triangle::Draw()
{
	mShader->Use();

    // create transformations
    glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    // pass transformation matrices to the shader
    mShader->SetMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    mShader->SetMat4("view", view);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, BaseEntity::GetPosition());
    mShader->SetMat4("model", model);

	mShader->SetVec3("color", glm::vec3(sin(-glfwGetTime()), sin(glfwGetTime()), cos(glfwGetTime())));

	BaseEntity::Draw();
}

void Triangle::Move(Direction direction, float deltaTime)
{
    BaseEntity::Move(direction, deltaTime);
}
