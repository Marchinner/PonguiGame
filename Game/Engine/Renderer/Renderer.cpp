#include "Renderer.h"

#include <glad/glad.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"

Renderer::Renderer(GLFWwindow* window)
{
}

void Renderer::Render()
{
	glClearColor(0.2f, .5f, .8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
