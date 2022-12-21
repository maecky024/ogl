#ifndef SCENE_H
#define SCENE_H
#pragma once

#include <string>
#include "renderer.hpp"

namespace bitmutation {
namespace ogl {
class Scene {
private:
	

public:
  Scene();
  ~Scene();
  bool loadScene(std::string filename);
  bool render(Renderer *renderer);
};
} // namespace ogl
} // namespace bitmutation
#endif