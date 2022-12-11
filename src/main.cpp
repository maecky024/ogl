#include <iostream>
#include "renderer.hpp"
#include "window.hpp"
#include "scene.hpp"
#include "opengl.hpp"
#include "vulkan.hpp"
#include "configuration.hpp"

using namespace bitmutation::ogl;

int main(int, char**) {
    
    Configuration * config = &Configuration::getInstance(std::string("myConfig.ini"));
    Renderer* renderer=NULL;
    
    if(config->ReadConfig("Renderer") == "Vulkan")
    {
        renderer = &Vulkan::getInstance();
    }
    else{
        renderer = &Opengl::getInstance();
    }

    Window* w = &Window::getInstance(renderer);
    std::cout << config->ReadConfig("Fullscreen") << std::endl;

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
