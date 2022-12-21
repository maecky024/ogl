#include "scene.hpp"  
#include <iostream>

bitmutation::ogl::Scene::Scene()
{
	
}
	
bitmutation::ogl::Scene::~Scene()
{
	
}

bool bitmutation::ogl::Scene::loadScene(std::string filename) 
{
    std::cout << "Scene Loaded" << std::endl;

    return true;            
}

bool bitmutation::ogl::Scene::render(Renderer *renderer)
{
    //std::cout << "render" << std::endl;
    renderer->draw(this);
    return true;
}
