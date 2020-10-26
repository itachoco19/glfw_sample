#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void)
{
    if(glfwInit() == GLFW_FALSE)
    {
        std::cerr << "Can't initialize GLFW" << std::endl;
        return 1;
    }

    GLFWwindow* const window(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
    if(window == NULL)
    {
        std::cerr << "Can't create window" << std::endl;
        return 1;
    }
    atexit(glfwTerminate);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        std::cerr << "Can't initiallize GLEW" << std::endl;
        return 1;
    }
    glfwSwapInterval(1);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    while(glfwWindowShouldClose(window) == GL_FALSE)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }
    return 0;
}