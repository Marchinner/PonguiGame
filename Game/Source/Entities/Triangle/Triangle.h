#pragma once

#include "../BaseEntity.h"

class Triangle : public BaseEntity
{
public:
	Triangle() :
		BaseEntity{ Type::TRIANGLE, glm::vec3{0.0f}, glm::vec3{0.0005f}, new Shader("./Source/Entities/Triangle/triangle.vert","./Source/Entities/Triangle/triangle.frag")}
	{
	}

	virtual void Update();
	virtual void Draw();
	virtual void Move(Direction direction);
};

