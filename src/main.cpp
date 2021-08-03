#include <GL/gl.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include "window.h"

using namespace bitmutation::ogl;

int main(int, char**) {
    
    Window* w = &bitmutation::ogl::Window::getInstance();

    if (w->init()==0)
    {
        while (!glfwWindowShouldClose(w->getGLFWWindow()))
        {
            // Keep running
            w->draw();
            glfwPollEvents();
        }
    }
}