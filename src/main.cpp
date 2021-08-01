#include <iostream>
#include <GLFW/glfw3.h>

#include "window.h"

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(int, char**) {

    std::cout << "Hello, world!\n";

    if (!glfwInit())
    {
        // Initialization failed
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
    if (!window)
    {
        // Window or OpenGL context creation failed
    }
    glfwSetKeyCallback(window, key_callback);

    glfwMakeContextCurrent(window);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    while (!glfwWindowShouldClose(window))
    {
        // Keep running

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
