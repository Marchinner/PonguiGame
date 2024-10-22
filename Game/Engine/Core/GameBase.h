#pragma once
#include <string>

#include "Window.h"
#include "../Renderer/Renderer.h"
#include <glm/fwd.hpp>

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
	glm::vec2 GetGameWindowSize() const;
protected:
	static float deltaTime;

private:
	bool mRunning;
	Window* mWindow;
	Renderer* mRenderer;
	static float lastFrame;
};

