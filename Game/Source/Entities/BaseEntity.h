#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../Engine/Renderer/Shader.h"

enum Type
{
	TRIANGLE,
	PADDLE,
	BALL
};

enum Direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT
};

class BaseEntity
{
protected:
	BaseEntity(Type type, glm::vec3 position, float velocity, Shader* shader);
	~BaseEntity() = default;

	virtual void Update();
	virtual void Draw();
	virtual void Move(Direction direction, float deltaTime);

	glm::vec3 GetPosition() const;
	float GetVelocity() const;
protected:
	Shader* mShader;

private:
	Type mType;
	glm::vec3 mPosition;
	float mVelocity;
	unsigned int mVAO;
	unsigned int mVBO;
	unsigned int mEBO;
};

