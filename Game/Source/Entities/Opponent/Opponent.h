#pragma once
#include "../BaseEntity.h"
class Opponent : public BaseEntity
{
public:
	Opponent();

	virtual void Update();
	virtual void Draw(glm::mat4 projection);
	virtual void Move(Direction direction, float deltaTime);
};

