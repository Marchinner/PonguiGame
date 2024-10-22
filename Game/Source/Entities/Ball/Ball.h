#pragma once

#include "../BaseEntity.h"

class Ball : public BaseEntity
{
public:
	Ball();

	void Update(float screenWidth, float screenHeight);
	virtual void Draw();

private:
	void Move(Direction direction, float deltaTime);

private:
	glm::vec3 mDefaultColor;
};

