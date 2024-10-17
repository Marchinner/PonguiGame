#pragma once

#include "../Engine/Core/GameBase.h"
#include "Entities/Triangle/Triangle.h"

class Game : public GameBase
{
public:
	Game();
	~Game();

	void Start();
	virtual void Run();
	virtual void Update();
	virtual void Render();

private:
	void processPlayerInputs();

private:
	Triangle* mTriangle;
};

