#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class Window
{
public:
	Window(int width, int height, const std::string& title);
	~Window();

	bool Initialize();
	bool ShouldClose() const;
	void PollEvents();
	void SwapBuffers();
	GLFWwindow* GetWindow() const;

private:
	int mWidth;
	int mHeight;
	std::string mTitle;
	GLFWwindow* mWindow;
};

