#include <iostream>
#include "window.hpp"
#include "scene.hpp"
#include "opengl.hpp"
#include "vulkan.hpp"

using namespace bitmutation::ogl;

int main(int, char**) {
    
    //Opengl* renderer = &Opengl::getInstance();
    Vulkan* renderer = &Vulkan::getInstance();

    Window* w = &Window::getInstance(renderer);

    Scene* s = new Scene();
    s->loadScene("data/scene.msc");
    
    if (w->init()==0)
    {
        while (!w->shouldWindowClose())
        {
            w->renderScene(s);
            w->handleInput();
        }
    }
}
