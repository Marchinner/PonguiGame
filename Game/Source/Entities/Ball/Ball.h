#pragma once

#include "../../../Engine/Core/Window.h"
#include "../BaseEntity.h"

class Ball : public BaseEntity
{
public:
	Ball();

	void Update(Window* gameWindow, float deltaTime);
	virtual void Draw(glm::mat4 projection);
	glm::vec3 GetPosition() const;
	void ResetPosition();
private:
	void Move(float deltaTime);

private:
	glm::vec3 mDefaultColor;
};

