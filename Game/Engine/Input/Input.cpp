#include "Input.h"

#include <GLFW/glfw3.h>

bool Input::IsKeyPressed(int keycode)
{
	return glfwGetKey(gameWindow, keycode) == (GLFW_PRESS || GLFW_REPEAT);
}

void Input::SetWindow(GLFWwindow* window)
{
	gameWindow = window;
}
