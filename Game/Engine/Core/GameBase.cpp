#include "GameBase.h"
#include <iostream>
#include "../Input/Input.h"

GameBase::GameBase(int windowWidth, int windowHeight, const std::string& windowTitle) :
	mRunning{ false },
	mWindow{ new Window(windowWidth, windowHeight, windowTitle) },
	mRenderer{ nullptr }
{
}

GameBase::~GameBase()
{
	if (mRenderer)
	{
		delete mRenderer;
		mRenderer = nullptr;
	}

	if (mWindow)
	{
		delete mWindow;
		mWindow = nullptr;
	}
}

bool GameBase::Initialize()
{
	if (!mWindow->Initialize())
	{
		std::cerr << "Failed to initialize the game window" << std::endl;
		return false;
	}

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	Input::SetWindow(mWindow->GetWindow());
	mRenderer = new Renderer();

	mRunning = true;

	return true;
}

void GameBase::Stop()
{
	std::cout << "Stoping..." << std::endl;

	glfwSetWindowShouldClose(mWindow->GetWindow(), true);
}

void GameBase::Run()
{
	while (mRunning && !mWindow->ShouldClose())
	{
		Update();

		Render();

		mWindow->SwapBuffers();
		mWindow->PollEvents();
	}
}

void GameBase::Update()
{

}

void GameBase::Render()
{
	mRenderer->Render();
}
