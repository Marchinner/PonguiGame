#pragma once
#include "ImGuiRenderer.h"
class Renderer
{
public:
	Renderer(GLFWwindow* window);
	~Renderer() = default;

	void Render();
};

