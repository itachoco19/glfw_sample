#ifndef GL_WINDOW
#define GL_WINDOW
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window
{
    GLFWwindow* const window;
    GLfloat aspect;
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
        glfwSetWindowUserPointer(window, this);
        glfwSetWindowSizeCallback(window, resize);
        resize(window, width, height);
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
    static void resize(GLFWwindow* const window, int width, int height)
    {
        int fbWidth, fbHeight;
        glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
        glViewport(0, 0, fbWidth, fbHeight);
        Window* const instance(static_cast<Window*>(glfwGetWindowUserPointer(window)));
        if(instance != NULL)
        {
            instance->aspect = static_cast<GLfloat>(width) / static_cast<GLfloat>(height);
        }
    }
    GLfloat getAspect() const {return this->aspect;}
};

#endif