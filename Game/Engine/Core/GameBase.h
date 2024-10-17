#pragma once
#include <string>

#include "Window.h"
#include "../Renderer/Renderer.h"

struct GLFWwindow;

class GameBase
{
protected:
	GameBase(int windowWidth, int windowHeight, const std::string& windowTitle);
	virtual ~GameBase();

	bool Initialize();
	void Stop();
	virtual void Run();
	virtual void Update();
	virtual void Render();

private:
	bool mRunning;
	Window* mWindow;
	Renderer* mRenderer;
};

