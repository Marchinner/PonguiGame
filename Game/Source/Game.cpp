#include "Game.h"
#include <iostream>
#include "../Engine/Input/Input.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

Game::Game() :
	GameBase{ 800, 600, "Pongui" },
	mImGuiRenderer{ nullptr },
	mTriangle{ nullptr },
	mPlayer{ nullptr },
	mOpponent{ nullptr },
	mBall{ nullptr },
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

	if (mBall)
	{
		delete mBall;
		mBall = nullptr;
	}
}

void Game::Start()
{
	std::cout << "Starting Pongui..." << std::endl;

	GameBase::Initialize();

	mImGuiRenderer = new ImGuiRenderer(GetGameWindow()->GetWindow());

	mTriangle = new Triangle();
	mPlayer = new Player();
	mOpponent = new Opponent();
	mBall = new Ball();

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

	mBall->Update(GetGameWindow());
}

void Game::Render()
{
	if (mGameState == RUNNING)
	{
		GameBase::Render();

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		ImGui::Begin("Debug");
		ImGui::Text("Ball Position: (%.2f, %.2f", mBall->GetPosition());
		ImGui::End();

		ImGui::ShowDemoWindow();

		mPlayer->Draw();

		mOpponent->Draw();

		mBall->Draw();

		mImGuiRenderer->Render();
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
