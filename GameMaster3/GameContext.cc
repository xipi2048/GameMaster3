#include "GameContext.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <functional>
using namespace std::placeholders;

bool GameContext::init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1024, 768, "Learn OpenGL", NULL, NULL);

    if (window == nullptr)
    {
        spdlog::critical("Could not create window :(");
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::critical("Failed to initialize GLAD");
        return false;
    }

    glfwSetFramebufferSizeCallback(window, fbResize);

    return true;
}

void GameContext::run()
{
    while (!glfwWindowShouldClose(window))
    {
        handleInput();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();

        renderScene();

        glfwSwapBuffers(window);
    }

    spdlog::info("Thank you! <3");
    glfwTerminate();
}

void GameContext::fbResize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, 1024, 768);
}

void GameContext::handleInput()
{
    /////////////////////
    //register events here for quicker handling
    ///////////////////////////////////////

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

void GameContext::renderScene()
{

}