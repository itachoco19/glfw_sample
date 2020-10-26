#include "program.h"

GLuint createProgram(const char* vsrc, const char* fsrc)
{
    const GLuint program(glCreateProgram());
    if(vsrc != NULL)
    {
        const GLuint vobj(glCreateShader(GL_VERTEX_SHADER));
        glShaderSource(vobj, 1, &vsrc, NULL);
        glCompileShader(vobj);
        glAttachShader(program, vobj);
        glDeleteShader(vobj);
    }

    if(fsrc != NULL)
    {
        const GLuint fobj(glCreateShader(GL_FRAGMENT_SHADER));
        glShaderSource(fobj, 1, &fsrc, NULL);
        glCompileShader(fobj);

        glAttachShader(program, fobj);
        glDeleteShader(fobj);
    }

    glBindAttribLocation(program, 0, "position");
    glBindFragDataLocation(program, 0, "fragment");
    glLinkProgram(program);

    return program;
}

bool readShaderSource(const char* name, std::vector<GLchar> & buffer)
{
    if(name == NULL) return false;

    std::ifstream file(name, std::ios::binary);
    if(file.fail())
    {
        std::cerr << "Can't open source file: " << name << std::endl;
        return false;
    }
    file.seekg(0L, std::ios::end);
    GLsizei length = static_cast<GLsizei>(file.tellg());
    buffer.resize(length + 1);
    file.seekg(0L, std::ios::beg);
    file.read(buffer.data(), length);
    buffer[length] = '\0';
    if(file.fail())
    {
        std::cerr << "Error: Could not read source file: " << name << std::endl;
        file.close();
        return false;
    }
    file.close();
    return true;

}

GLuint loadProgram(const char* vert, const char* frag)
{
    std::vector<GLchar> vsrc;
    const bool vstat(readShaderSource(vert, vsrc));
    std::vector<GLchar> fsrc;
    const bool fstat(readShaderSource(frag, fsrc));

    return vstat && fstat ? createProgram(vsrc.data(), fsrc.data()) : 0;
}