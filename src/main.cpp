#include <iostream>
#include "window.h"

using namespace bitmutation::ogl;

int main(int, char**) {
    
    Window* w = &bitmutation::ogl::Window::getInstance();

    if (w->init()==0)
    {
        while (!w->shouldWindowClose())
        {
            w->draw();
            w->handleInput();
        }
    }
}