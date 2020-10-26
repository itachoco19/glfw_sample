#include <cstdlib>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "program.h"
#include <vector>

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
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    const GLuint program(loadProgram("point.vert", "point.frag"));
    while(glfwWindowShouldClose(window) == GL_FALSE)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        printProgramInfo(program);
        glUseProgram(program);
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }
    return 0;
}