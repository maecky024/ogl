#include <GL/gl.h>
#include <iostream>
#include <GLFW/glfw3.h>

#include "window.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void mb_callback(GLFWwindow*window ,int button, int action, int mods);
static void cursor_enter_callback(GLFWwindow* window, int entered);
static void window_close_callback(GLFWwindow* window);
static void window_size_callback(GLFWwindow* window, int width, int height);
static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void draw(GLFWwindow* window);

int main(int, char**) {

    //std::cout << "Hello, world!\n";

    if (!glfwInit())
    {
        // Initialization failed
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

// FULLSCREEN
// GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", glfwGetPrimaryMonitor(), NULL);


    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        // Window or OpenGL context creation failed
    }


    // Set Callbacks
    glfwSetWindowCloseCallback(window, window_close_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetCursorEnterCallback(window, cursor_enter_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mb_callback);
    

    glfwMakeContextCurrent(window);    

    while (!glfwWindowShouldClose(window))
    {
        // Keep running
        draw(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

void draw(GLFWwindow* window)
{
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

static void mb_callback(GLFWwindow*window ,int button, int action, int mods)
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

void cursor_enter_callback(GLFWwindow* window, int entered)
{
    if (entered)
    {
        std::cout << "Cursor entered" << std::endl;
    }
    else{
        std::cout << "Cursor left" << std::endl;
    }
}

static void window_close_callback(GLFWwindow* window)
{
    std::cout << "Windows close CB" << std::endl;
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
    std::cout << "Windows SIZE CB " << width << "x" << height << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
        std::cout << "FW SIZE CB " << width << "x" << height << std::endl;

        glViewport(0, 0, width, height);
        draw(window);
}