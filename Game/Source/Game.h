#pragma once

#include "../Engine/Core/GameBase.h"
#include "Entities/Triangle/Triangle.h"
#include "Entities/Player/Player.h"
#include "Entities/Opponent/Opponent.h"
#include "Entities/Ball/Ball.h"

enum GameState
{
	PAUSED,
	RUNNING
};

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
	ImGuiRenderer* mImGuiRenderer;
	Triangle* mTriangle;
	Player* mPlayer;
	Opponent* mOpponent;
	Ball* mBall;
	GameState mGameState;
};

