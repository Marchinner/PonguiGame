#include "BaseEntity.h"

BaseEntity::BaseEntity(glm::vec3 position, glm::vec3 velocity, Shader shader) :
	mPosition{ position },
	mVelocity{ velocity },
	mShader{ shader }
{
}

void BaseEntity::Update()
{
}

void BaseEntity::Draw()
{
	mShader.Use();
}

glm::vec3 BaseEntity::GetPosition() const
{
	return mPosition;
}

glm::vec3 BaseEntity::GetVelocity() const
{
	return mVelocity;
}
