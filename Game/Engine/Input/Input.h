#pragma once
#include <unordered_map>

struct GLFWwindow;

enum KeyState
{
	JUST_PRESSED,
	HELD_DOWN,
	JUST_RELEASED,
	NOT_PRESSED
};

class Input
{
public:
	static void Initialize(GLFWwindow* window);
	static void Update();

	static KeyState GetKeyState(int keycode);
	static bool IsKeyPressed(int keycode);
	static bool IsKeyHeld(int keycode);
	static bool IsKeyReleased(int keycode);

private:
	static GLFWwindow* mWindow;
	static std::unordered_map<int, KeyState> mKeyStates;
};

