#pragma once

#include "../BaseEntity.h"

class Triangle : public BaseEntity
{
public:
	Triangle();

	virtual void Update();
	virtual void Draw();
	virtual void Move(Direction direction, float deltaTime);
};

