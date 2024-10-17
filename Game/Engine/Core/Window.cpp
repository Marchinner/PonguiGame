#include "Window.h"

#include <iostream>

Window::Window(int width, int height, const std::string& title) :
	mWidth{ width },
	mHeight{ height },
	mTitle{ title },
	mWindow{ nullptr }
{
}

Window::~Window()
{
	if (mWindow)
	{
		glfwDestroyWindow(mWindow);
		glfwTerminate();
	}
}

bool Window::Initialize()
{
	if (glfwInit() == GLFW_FALSE)
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		glfwTerminate();
	}

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), NULL, NULL);
	if (mWindow == NULL)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		return false;
	}

	glfwMakeContextCurrent(mWindow);

	return true;
}

bool Window::ShouldClose() const
{
	return glfwWindowShouldClose(mWindow);
}

void Window::PollEvents()
{
	glfwPollEvents();
}

void Window::SwapBuffers()
{
	glfwSwapBuffers(mWindow);
}

GLFWwindow* Window::GetWindow() const
{
	return mWindow;
}
