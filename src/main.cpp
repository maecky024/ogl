#include <iostream>
#include "window.hpp"
#include "scene.hpp"
#include "opengl.hpp"
#include "vulkan.hpp"
#include "configuration.hpp"

using namespace bitmutation::ogl;

int main(int, char**) {
    
    Configuration * config = &Configuration::getInstance(std::string("myConfig.ini"));
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
