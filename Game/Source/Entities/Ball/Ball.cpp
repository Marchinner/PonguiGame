#include "Ball.h"

Ball::Ball() :
	BaseEntity(PADDLE, glm::vec3{ 0.0f, 0.0f, 0.0f }, 1.5f,
		new Shader{ "./Source/Entities/Ball/shaders/ball.vert", "./Source/Entities/Ball/shaders/ball.frag" }),
	mDefaultColor{ glm::vec3(1.0f, 1.0f, 1.0f) }
{
}

void Ball::Update(Window* gameWindow, float deltaTime)
{
	Move(deltaTime);
}

void Ball::Draw(glm::mat4 projection)
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
	model = glm::scale(model, glm::vec3(-0.04f, 0.04f, 0.0f));
	mShader->SetMat4("model", model);

	mShader->SetVec3("color", mDefaultColor);

	BaseEntity::Draw();
}

glm::vec3 Ball::GetPosition() const
{
	return BaseEntity::GetPosition();
}

void Ball::ResetPosition()
{
	SetPosition(glm::vec3(0.0f));
}

void Ball::Move(float deltaTime)
{
	glm::vec3 direction = glm::vec3(-GetVelocity() * deltaTime, 0.0f, 0.0f);
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, direction);
	glm::vec4 position = glm::vec4(GetPosition(), 1.0f);
	position = trans * position;
	BaseEntity::SetPosition(position);
}
