
#ifndef __BM_WINDOW_H
#define __BM_WINDOW_H

#include "scene.hpp"
#include "renderer.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace bitmutation {
namespace ogl {
class Window {
public:
  static Window &getInstance(Renderer *r) {
    static Window instance(r);
    return instance;
  }

  static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
  static void mb_callback(GLFWwindow *window, int button, int action, int mods);
  static void cursor_enter_callback(GLFWwindow *window, int entered);
  static void window_close_callback(GLFWwindow *window);
  static void window_size_callback(GLFWwindow *window, int width, int height);
  static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

  void renderScene(Scene *scene);
  int init();
  void handleInput();
  bool shouldWindowClose();

  GLFWwindow *getGLFWWindow();

private:
  Renderer *renderer;

  GLFWwindow *glfwwin;
  Window(Renderer *r);
  ~Window();

public:
  Window(Window const &) = delete;
  void operator=(Window const &) = delete;
};
} // namespace ogl
} // namespace bitmutation

#endif