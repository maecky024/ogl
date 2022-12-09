#ifndef RENDERER_H
#define RENDERER_H
#pragma once

namespace bitmutation {
	namespace ogl {
		class Renderer {
private:
public:
			Renderer();
  			~Renderer();
			virtual bool isVulkan()=0;
		};
	} // namespace ogl
} // namespace bitmutation
#endif