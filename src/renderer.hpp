#ifndef RENDERER_H
#define RENDERER_H
#pragma once



namespace bitmutation {
	namespace ogl {
		class Scene;
		class Renderer {
private:
public:
			Renderer();
  			~Renderer();
			virtual bool isVulkan()=0;
			virtual void draw(Scene *scene)=0;
			virtual void init()=0;
		};
	} // namespace ogl
} // namespace bitmutation
#endif