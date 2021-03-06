#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "program.h"
#include "Shape.h"
#include "window.h"

constexpr Object::Vertex rectangleVertex[] = 
{
    {-0.5f, -0.5f},
    {0.5f, -0.5f},
    {0.5f, 0.5f},
    {-0.5f, 0.5f}
};

GLboolean printProgramInfo(GLuint program)
{
    GLint status;
    glGetProgramiv(program, GL_LINK_STATUS, &status);
    if(status == GL_FALSE) std::cerr << "Link error" << std::endl;
    GLsizei bufsize;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufsize);

    if(bufsize > 1)
    {
        std::vector<GLchar> infoLog(bufsize);
        GLsizei length;
        glGetProgramInfoLog(program, bufsize, &length, &infoLog[0]);
        std::cerr << &infoLog[0] << std::endl;
    }
    return static_cast<GLboolean>(status);
}

int main(void)
{
    if(glfwInit() == GLFW_FALSE)
    {
        std::cerr << "Can't initialize GLFW" << std::endl;
        return 1;
    }

    /*
    GLFWwindow* const window(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
    if(window == NULL)
    {
        std::cerr << "Can't create window" << std::endl;
        return 1;
    }
    */
    Window window;
    atexit(glfwTerminate);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
    {
        std::cerr << "Can't initiallize GLEW" << std::endl;
        return 1;
    }
    glfwSwapInterval(1);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    const GLuint program(loadProgram("point.vert", "point.frag"));
    const GLint aspectLoc(glGetUniformLocation(program, "aspect"));
    std::unique_ptr<const Shape> shape(new Shape(2, 4, rectangleVertex));
    while(window)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(program);
        glUniform1f(aspectLoc, window.getAspect());
        shape->draw();
        window.swapBuffer();
        glfwWaitEvents();
    }
    return 0;
}