#include "window.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <locale>

bitmutation::ogl::Window::Window(Renderer *r)
{
    this->renderer=r;
    std::cout << "Window::CTOR()" << std::endl;
}

bitmutation::ogl::Window::~Window()
{
    std::cout << "Window::DTOR()" << std::endl;
    glfwDestroyWindow(this->glfwwin);
    glfwTerminate();
}

GLFWwindow *bitmutation::ogl::Window::getGLFWWindow()
{
    return this->glfwwin;
}

int bitmutation::ogl::Window::init()
{
    if (!glfwInit())
    {
        // Initialization failed
        return 1;
    }
    
    if (renderer->isVulkan()){
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        std::cout << "Window Vulkan found" << std::endl;
    }
    else{
        std::cout << "Window OpenGL found" << std::endl;
    }
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

// FULLSCREEN
// GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", glfwGetPrimaryMonitor(), NULL);

    glfwwin = glfwCreateWindow(1280, 720, "My Title", NULL, NULL);
    if (!glfwwin)
    {
        return 2;
        // Window or OpenGL context creation failed
    }

    // Set Callbacks
    glfwSetWindowCloseCallback(glfwwin, window_close_callback);
    glfwSetWindowSizeCallback(glfwwin, window_size_callback);
    glfwSetCursorEnterCallback(glfwwin, cursor_enter_callback);
    glfwSetFramebufferSizeCallback(glfwwin, framebuffer_size_callback);

    glfwSetKeyCallback(glfwwin, key_callback);
    glfwSetMouseButtonCallback(glfwwin, mb_callback);
    
    glfwMakeContextCurrent(glfwwin);    

    return 0;
}

void bitmutation::ogl::Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    else{
        std::cout << "Key with code 0x" << std::hex <<  key << "(" << char(key) << ") pressed" << std::endl;
    }
}

void bitmutation::ogl::Window::mb_callback(GLFWwindow*window ,int button, int action, int mods)
{
     if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
     {
         std::cout << "Mouse RIGHT pressed" << std::endl;
     }
     else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
     {
         std::cout << "Mouse LEFT pressed" << std::endl;
     }
}

void bitmutation::ogl::Window::cursor_enter_callback(GLFWwindow* window, int entered)
{
    if (entered)
    {
        std::cout << "Cursor entered" << std::endl;
    }
    else{
        std::cout << "Cursor left" << std::endl;
    }
}

void bitmutation::ogl::Window::window_close_callback(GLFWwindow* window)
{
    std::cout << "Windows close CB" << std::endl;
}

void bitmutation::ogl::Window::window_size_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "Windows SIZE CB " << width << "x" << height << std::endl;
}

void bitmutation::ogl::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
        std::cout << "FW SIZE CB " << width << "x" << height << std::endl;
        //glViewport(0, 0, width, height);
        //glfwSwapBuffers(::glfwGetCurrentContext());

}

void bitmutation::ogl::Window::handleInput() 
{
    glfwPollEvents();
}

bool bitmutation::ogl::Window::shouldWindowClose()
{
    return glfwWindowShouldClose(this->glfwwin);
}

void bitmutation::ogl::Window::renderScene(Scene* scene) 
{
    scene->render();
    glfwSwapBuffers(this->glfwwin);
}
    
