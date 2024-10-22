#pragma once
#include "ImGuiRenderer.h"
class Renderer
{
public:
	Renderer(GLFWwindow* window);
	virtual ~Renderer();

	void Render();

private:
	ImGuiRenderer* mImGuiRenderer;
};

