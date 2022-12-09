#include "opengl.hpp"  
#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include "GLFW/glfw3.h"

bitmutation::ogl::Opengl::Opengl()
{
	
}
	
bitmutation::ogl::Opengl::~Opengl()
{
	
}

void bitmutation::ogl::Opengl::draw()
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void bitmutation::ogl::Opengl::init()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
}