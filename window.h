#ifndef GL_WINDOW
#define GL_WINDOW
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
    GLFWwindow* const window;
public:
    Window(int width = 640, int height = 480, const char* title = "Hello!") : window(glfwCreateWindow(width, height, title, NULL, NULL))
    {
        if(window == NULL)
        {
            std::cerr << "Can't create GLFW window." << std::endl;
            exit(1);
        }
        glfwMakeContextCurrent(this->window);
        glewExperimental = GL_TRUE;
        if(glewInit() != GLEW_OK)
        {
            std::cerr << "Can't initialize GLEW" << std::endl;
            exit(1);
        }
        glfwSwapInterval(1);
    }
    virtual ~Window()
    {
        glfwDestroyWindow(window);
    }
    explicit operator bool()
    {
        glfwWaitEvents();
        return !glfwWindowShouldClose(this->window);
    }
    void swapBuffer() const
    {
        glfwSwapBuffers(this->window);
    }
};

#endif