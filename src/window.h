
#ifndef __BM_WINDOW_H
#define __BM_WINDOW_H

#include <GLFW/glfw3.h>

namespace bitmutation
{
    namespace ogl
    {
        class Window{
            public :
                static Window& getInstance()
                {
                    static Window instance;
                    return instance;
                }

                static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
                static void mb_callback(GLFWwindow*window ,int button, int action, int mods);
                static void cursor_enter_callback(GLFWwindow* window, int entered);
                static void window_close_callback(GLFWwindow* window);
                static void window_size_callback(GLFWwindow* window, int width, int height);
                static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

                void draw();
                int init();
                void handleInput();
                bool shouldWindowClose();

                GLFWwindow *getGLFWWindow();

            private:

                GLFWwindow *glfwwin;

                Window();
                ~Window();

            public:
                Window(Window const&) = delete;
                void operator=(Window const&) = delete;
        };
    }
}

#endif