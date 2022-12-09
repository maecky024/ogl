#ifndef SCENE_H
#define SCENE_H
#pragma once

#include <string>

namespace bitmutation {
namespace ogl {
class Scene {
private:
	

public:
  Scene();
  ~Scene();
  bool loadScene(std::string filename);
  bool render();
};
} // namespace ogl
} // namespace bitmutation
#endif