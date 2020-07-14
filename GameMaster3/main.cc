#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

void fbResize(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, 1024, 768);
}

void handleInput(GLFWwindow* window)
{
    
}

int main(int argc, char **argv)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    auto window = glfwCreateWindow(1024, 768, "Learn OpenGL", NULL, NULL);
    if (window == nullptr)
    {
        spdlog::critical("Could not create window :(");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        spdlog::critical("Failed to initialize GLAD");
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, fbResize);

    while (!glfwWindowShouldClose(window))
    {
        handleInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    spdlog::info("Thank you! <3");
    glfwTerminate();
    return 0;
}