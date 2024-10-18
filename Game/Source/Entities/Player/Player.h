#pragma once
#include "../BaseEntity.h"
class Player : public BaseEntity
{
public:
	Player();

	virtual void Update();
	virtual void Draw();
	virtual void Move(Direction direction, float deltaTime);
};

