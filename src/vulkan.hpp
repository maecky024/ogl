#ifndef VULKAN_H
#define VULKAN_H
#pragma once

#include "renderer.hpp"
#include <vulkan/vulkan.h>


namespace bitmutation 
{ 
	namespace ogl 
	{
		class Vulkan : public Renderer
		{
		public:
			static Vulkan &getInstance() {
			static Vulkan instance;
			return instance;
		}

		private:
			Vulkan();
			~Vulkan();
			VkInstance instance;

		public:
			void init() override;
			void draw(Scene *scene) override;
			bool isVulkan() override;
			Vulkan(Vulkan const &) = delete;
			void operator=(Vulkan const &) = delete;
		};
	}
}
#endif