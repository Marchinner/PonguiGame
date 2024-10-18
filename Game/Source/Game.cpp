#include "Game.h"
#include <iostream>
#include "../Engine/Input/Input.h"

Game::Game() :
	GameBase{ 800, 600, "Pongui" },
	mTriangle{ nullptr },
	mPlayer{ nullptr },
	mOpponent{ nullptr },
	mGameState{ RUNNING }
{
}

Game::~Game()
{
	if (mTriangle)
	{
		delete mTriangle;
		mTriangle = nullptr;
	}

	if (mPlayer)
	{
		delete mPlayer;
		mPlayer = nullptr;
	}

	if (mOpponent)
	{
		delete mOpponent;
		mOpponent = nullptr;
	}
}

void Game::Start()
{
	std::cout << "Starting Pongui..." << std::endl;

	GameBase::Initialize();

	mTriangle = new Triangle();
	mPlayer = new Player();
	mOpponent = new Opponent();

	std::cout << "Pongui started!" << std::endl;

	Run();
}

void Game::Run()
{
	GameBase::Run();
}

void Game::Update()
{
	GameBase::Update();

	processPlayerInputs();
}

void Game::Render()
{
	if (mGameState == RUNNING)
	{
		GameBase::Render();

		mPlayer->Draw();

		mOpponent->Draw();
	}
}

void Game::processPlayerInputs()
{
	if (Input::IsKeyPressed(GLFW_KEY_ESCAPE))
	{
		if (mGameState == GameState::RUNNING)
			mGameState = GameState::PAUSED;
		else
			GameBase::Stop();
	}

	if (Input::IsKeyPressed(GLFW_KEY_ENTER))
		if (mGameState == GameState::PAUSED)
			mGameState = GameState::RUNNING;

	if (Input::IsKeyPressed(GLFW_KEY_UP) || Input::IsKeyHeld(GLFW_KEY_UP))
		mPlayer->Move(Direction::UP, deltaTime);

	if (Input::IsKeyPressed(GLFW_KEY_DOWN) || Input::IsKeyHeld(GLFW_KEY_DOWN))
		mPlayer->Move(Direction::DOWN, deltaTime);
}
