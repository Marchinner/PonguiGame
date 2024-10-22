#pragma once

struct GLFWwindow;

class ImGuiRenderer
{
public:
	ImGuiRenderer(GLFWwindow* window);
	virtual ~ImGuiRenderer();

	void Render();

private:
	void cleanup();
};

