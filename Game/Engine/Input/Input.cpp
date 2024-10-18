#include "Input.h"

#include <GLFW/glfw3.h>

GLFWwindow* Input::mWindow = nullptr;
std::unordered_map<int, KeyState> Input::mKeyStates;

void Input::Initialize(GLFWwindow* window)
{
	mWindow = window;
}

void Input::Update()
{
	for (auto& key : mKeyStates)
	{
		int keyCode = key.first;

		bool isPressed = glfwGetKey(mWindow, keyCode) == GLFW_PRESS;

		switch (key.second)
		{
		case KeyState::NOT_PRESSED:
			if (isPressed)
				key.second = KeyState::JUST_PRESSED;
			break;
		case KeyState::JUST_PRESSED:
			if (isPressed)
				key.second = KeyState::HELD_DOWN;
			else
				key.second = KeyState::JUST_RELEASED;
			break;
		case KeyState::HELD_DOWN:
			if (!isPressed)
				key.second = KeyState::JUST_RELEASED;
			break;
		case KeyState::JUST_RELEASED:
			if (!isPressed)
				key.second = KeyState::NOT_PRESSED;
			break;
		}
	}
}

KeyState Input::GetKeyState(int keycode)
{
	if (mKeyStates.find(keycode) == mKeyStates.end())
	{
		mKeyStates[keycode] = KeyState::NOT_PRESSED;
	}

	return mKeyStates[keycode];
}

bool Input::IsKeyPressed(int keycode)
{
	return GetKeyState(keycode) == KeyState::JUST_PRESSED;
}

bool Input::IsKeyHeld(int keycode)
{
	return GetKeyState(keycode) == KeyState::HELD_DOWN;
}

bool Input::IsKeyReleased(int keycode)
{
	return GetKeyState(keycode) == KeyState::JUST_RELEASED;
}
