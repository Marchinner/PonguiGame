#pragma once

#include <glm/glm.hpp>
#include "../../Engine/Renderer/Shader.h"

class BaseEntity
{
protected:
	BaseEntity(glm::vec3 position, glm::vec3 velocity, Shader shader);
	~BaseEntity() = default;

	virtual void Update();
	virtual void Draw();

	glm::vec3 GetPosition() const;
	glm::vec3 GetVelocity() const;
private:
	glm::vec3 mPosition;
	glm::vec3 mVelocity;
	Shader mShader;
};

