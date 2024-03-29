#include "vulkan.hpp"
#ifdef _WIN32
#include <windows.h>
#endif
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>
#include "logger.hpp"

bitmutation::ogl::Vulkan::Vulkan()
{
    Logger::getInstance().Log("Init Vulkan");

    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "GLEngine";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_1;

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

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
    std::vector<VkExtensionProperties> extensions(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

    for (const auto& extension : extensions) {
        Logger::getInstance().Log("\t " + std::string(extension.extensionName));
    }

    vkDestroyInstance(instance, nullptr);

}
	
bool bitmutation::ogl::Vulkan::isVulkan()
{
    return true;
}

bitmutation::ogl::Vulkan::~Vulkan()
{
	
}

void bitmutation::ogl::Vulkan::draw(Scene *scene)
{
    
}

void bitmutation::ogl::Vulkan::init()
{

}