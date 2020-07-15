#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>

class GameContext
{
public:
	bool init();
	void run();

private:
	GLFWwindow *window;

	static void fbResize(GLFWwindow* window, int width, int height);
	void handleInput();
	void renderScene();
};

