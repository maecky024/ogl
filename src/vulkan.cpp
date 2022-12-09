#include "vulkan.hpp"
#ifdef _WIN32
#include <windows.h>
#endif
#include "GLFW/glfw3.h"
#include <iostream>

bitmutation::ogl::Vulkan::Vulkan()
{
    std::cout << "Init Vulkan" << std::endl;
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    createInfo.enabledLayerCount = 0;

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("failed to create instance!");
    }

}
	
bool bitmutation::ogl::Vulkan::isVulkan()
{
    return true;
}

bitmutation::ogl::Vulkan::~Vulkan()
{
	
}

void bitmutation::ogl::Vulkan::draw()
{
    
}

void bitmutation::ogl::Vulkan::init()
{

}