#include "Ball.h"
#include "../../../ThirdParty/Includes/GLFW/glfw3.h"

Ball::Ball() :
	BaseEntity(PADDLE, glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.5f,
		new Shader{ "./Source/Entities/Ball/shaders/ball.vert", "./Source/Entities/Ball/shaders/ball.frag" }),
	mDefaultColor{ glm::vec3(1.0f, 1.0f, 1.0f) }
{
}

void Ball::Update(float screenWidth, float screenHeight)
{
}

void Ball::Draw()
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
	model = glm::scale(model, glm::vec3(-0.04f, 0.04f, 0.0f));
	mShader->SetMat4("model", model);

	mShader->SetVec3("color", mDefaultColor);

	BaseEntity::Draw();
}

void Ball::Move(Direction direction, float deltaTime)
{
}
