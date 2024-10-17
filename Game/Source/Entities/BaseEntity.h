#pragma once

#include <glm/glm.hpp>
#include "../../Engine/Renderer/Shader.h"

enum Type
{
	TRIANGLE,
	PADDLE,
	BALL
};

class BaseEntity
{
protected:
	BaseEntity(Type type, glm::vec3 position, glm::vec3 velocity, Shader* shader);
	~BaseEntity() = default;

	virtual void Update();
	virtual void Draw();

	glm::vec3 GetPosition() const;
	glm::vec3 GetVelocity() const;
protected:
	Shader* mShader;

private:
	Type mType;
	glm::vec3 mPosition;
	glm::vec3 mVelocity;
	unsigned int mVAO;
	unsigned int mVBO;
	unsigned int mEBO;
};

