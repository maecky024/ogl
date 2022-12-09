#ifndef OPENGL_H
#define OPENGL_H
#pragma once

#include "renderer.hpp"


namespace bitmutation 
{ 
	namespace ogl 
	{
		class Opengl : public Renderer
		{
		public:
			static Opengl &getInstance() {
			static Opengl instance;
			return instance;
		}

		private:
			Opengl();
			~Opengl();

		public:
			void init();
			void draw();
			bool isVulkan() override;
			Opengl(Opengl const &) = delete;
			void operator=(Opengl const &) = delete;
		};
	}
}
#endif