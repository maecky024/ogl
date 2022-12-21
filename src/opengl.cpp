#include "opengl.hpp"  
#include <vulkan/vulkan_core.h>
#ifdef _WIN32
#include <windows.h>
#endif

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

bitmutation::ogl::Opengl::Opengl()
{

}

bool bitmutation::ogl::Opengl::isVulkan()
{
    return false;
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
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
}