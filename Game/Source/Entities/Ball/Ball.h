#pragma once

#include "../BaseEntity.h"

class Ball : public BaseEntity
{
public:
	Ball();

	virtual void Update();
	virtual void Draw();
	virtual void Move(Direction direction, float deltaTime);

private:
	glm::vec3 mDefaultColor;
};

