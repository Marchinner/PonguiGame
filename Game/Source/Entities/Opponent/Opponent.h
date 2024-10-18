#pragma once
#include "../BaseEntity.h"
class Opponent : public BaseEntity
{
public:
	Opponent();

	virtual void Update();
	virtual void Draw();
	virtual void Move(Direction direction, float deltaTime);
};

