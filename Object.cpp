#include "Object.h"

Object::Object(GLint size, GLsizei vertex_count, const Vertex* vertex)
{
    glGenVertexArrays(1, &(this->vao));
    glBindVertexArray(this->vao);
    glGenBuffers(1, &(this->vbo));
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, vertex_count * sizeof(Vertex), vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, size, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);
}

void Object::bind() const
{
    glBindVertexArray(this->vao);
}

Object::~Object()
{
    glDeleteVertexArrays(1, &(this->vao));
    glDeleteBuffers(1, &(this->vbo));
}