#ifndef PROGRAM
#define PROGRAM
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint createProgram(const char* vsrc, const char* fsrc);
GLuint loadProgram(const char* vert, const char* frag);
#endif