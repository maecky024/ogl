#include "scene.hpp"  
#include <iostream>
#include "logger.hpp"

bitmutation::ogl::Scene::Scene()
{
	
}
	
bitmutation::ogl::Scene::~Scene()
{
	
}

bool bitmutation::ogl::Scene::loadScene(std::string filename) 
{
    Logger::getInstance().Log("Scene Loaded");

    return true;            
}

bool bitmutation::ogl::Scene::render(Renderer *renderer)
{
    renderer->draw(this);
    return true;
}
