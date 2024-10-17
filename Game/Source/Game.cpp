#include "Game.h"
#include <iostream>
#include "../Engine/Input/Input.h"

Game::Game() :
	GameBase{ 800, 600, "Pongui" },
	mTriangle{ nullptr }
{
}

Game::~Game()
{
	if (mTriangle)
	{
		delete mTriangle;
		mTriangle = nullptr;
	}
}

void Game::Start()
{
	std::cout << "Starting Pongui..." << std::endl;

	GameBase::Initialize();

	mTriangle = new Triangle();

	std::cout << "Pongui started!" << std::endl;

	Run();
}

void Game::Run()
{
	GameBase::Run();
}

void Game::Update()
{
	processPlayerInputs();


}

void Game::Render()
{
	GameBase::Render();

	mTriangle->Draw();
}

void Game::processPlayerInputs()
{
	if (Input::IsKeyPressed(GLFW_KEY_ESCAPE))
		GameBase::Stop();
}
