#ifndef GL_OBJECT
#define GL_OBJECT
#include <GL/glew.h>

class Object
{
private:
    GLuint vao = 0;
    GLuint vbo = 0;
    Object(const Object& o);
    Object &operator=(const Object& o);
public:
    struct Vertex
    {
        GLfloat position[2];
    };
    Object(GLint size, GLsizei vertex_count, const Vertex* vertex);
    void bind() const;
    virtual ~Object();
};

#endif