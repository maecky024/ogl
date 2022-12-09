#include <iostream>
#include "window.hpp"
#include "scene.hpp"
#include "opengl.hpp"

using namespace bitmutation::ogl;

int main(int, char**) {
    
    Window* w = &Window::getInstance(&Opengl::getInstance());
    Opengl* gl = &Opengl::getInstance();

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
