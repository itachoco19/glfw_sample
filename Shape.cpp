#include "Shape.h"

void Shape::draw() const
{
    object->bind();
    this->execute();
}

void Shape::execute() const
{
    glDrawArrays(GL_LINE_LOOP, 0, vertex_count);
}