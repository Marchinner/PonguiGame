#pragma once

#include "../BaseEntity.h"

struct Window;

class Ball : public BaseEntity
{
public:
	Ball();

	void Update(Window* gameWindow);
	virtual void Draw();

private:
	void Move(Direction direction, float deltaTime);

private:
	glm::vec3 mDefaultColor;
};

