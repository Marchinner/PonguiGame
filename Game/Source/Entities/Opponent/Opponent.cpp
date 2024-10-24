#include "Opponent.h"
#include <GLFW/glfw3.h>

Opponent::Opponent() :
    BaseEntity(PADDLE, glm::vec3{ 1.5f, 0.0f, 0.0f }, 2.0f,
        new Shader{ "./Source/Entities/Opponent/shaders/opponent.vert", "./Source/Entities/Opponent/shaders/opponent.frag" })
{
}

void Opponent::Update()
{
}

void Opponent::Draw(glm::mat4 projection)
{
    mShader->Use();

    // create transformations
    glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    // pass transformation matrices to the shader
    mShader->SetMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
    mShader->SetMat4("view", view);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, BaseEntity::GetPosition());
    model = glm::scale(model, glm::vec3(-0.08f, 0.5f, 0.0f));
    mShader->SetMat4("model", model);

    mShader->SetVec3("color", glm::vec3(sin(glfwGetTime()), sin(-glfwGetTime()), cos(-glfwGetTime())));

    BaseEntity::Draw();
}

void Opponent::Move(Direction direction, float deltaTime)
{
    BaseEntity::Move(direction, deltaTime);
}
