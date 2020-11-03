#ifndef OBJECT_SHAPE
#define OBJECT_SHAPE

#include <memory>
#include "Object.h"

class Shape
{
private:
    std::shared_ptr<const Object> object;
protected:
    const GLsizei vertex_count;
public:
    Shape(GLint size, GLsizei vertex_count, const Object::Vertex* vertex) : object(new Object(size, vertex_count, vertex)), vertex_count(vertex_count){}
    void draw() const;
    virtual void execute() const;
};

#endif