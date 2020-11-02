#ifndef GL_OBJECT
#define GL_OBJECT
#include <GL/glew.h>

class Object
{
private:
    GLuint vao;
    GLuint vbo;
public:
    struct Vertex
    {
        GLfloat position[2];
    };
    Object(GLint size, GLsizei vertex_count, const Vertex* vertex);
    virtual ~Object();
};

#endif