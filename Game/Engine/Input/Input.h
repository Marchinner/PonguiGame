#pragma once

struct GLFWwindow;

static GLFWwindow* gameWindow;

class Input
{
public:
	static bool IsKeyPressed(int keycode);
	static void SetWindow(GLFWwindow* window);
};

