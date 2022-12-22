#include "window.hpp"

#include <GLFW/glfw3.h>
#include <iostream>
#include <locale>
#include <string>
#include "logger.hpp"

bitmutation::ogl::Window::Window(Renderer *r)
{
    this->renderer=r;
    this->glfwwin = 0;
    Logger::getInstance().Log("Window::CTOR()");
}

bitmutation::ogl::Window::~Window()
{
    Logger::getInstance().Log("Window::DTOR()");

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
        Logger::getInstance().Log("Window Vulkan found");
    }
    else{
        Logger::getInstance().Log("Window OpenGL found");
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
        Logger::getInstance().Log(std::string("Key with code " + std::to_string(key) + "(" + std::string(1,key) + ") pressed"));
    }
}

void bitmutation::ogl::Window::mb_callback(GLFWwindow*window ,int button, int action, int mods)
{
     if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
     {
        Logger::getInstance().Log("Mouse RIGHT pressed");
     }
     else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
     {
        Logger::getInstance().Log("Mouse LEFT pressed");
     }
}

void bitmutation::ogl::Window::cursor_enter_callback(GLFWwindow* window, int entered)
{
    if (entered)
    {
        Logger::getInstance().Log("Cursor entered");

    }
    else{
        Logger::getInstance().Log("Cursor left");
    }
}

void bitmutation::ogl::Window::window_close_callback(GLFWwindow* window)
{
    Logger::getInstance().Log("Windows close CB");

}

void bitmutation::ogl::Window::window_size_callback(GLFWwindow* window, int width, int height)
{
    //Logger::getInstance().Log(std::string("Windows SIZE CB " + std::to_string(width) + "x" + std::to_string(height)));
}

void bitmutation::ogl::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //Logger::getInstance().Log(std::string("Windows SIZE CB " + std::to_string(width) + "x" + std::to_string(height)));

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
    scene->render(this->renderer);
    glfwSwapBuffers(this->glfwwin);
}
    
