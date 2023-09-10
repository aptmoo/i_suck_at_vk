#include "vkapp.h"
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstring>

void glfwErorCallback(int error, const char* desc)
{
    std::cerr << "GLFW error " << error << ":\n" << desc << '\n';
}

void VkApp::InitWindow()
{
    if(!glfwInit())
    {
        throw std::runtime_error("Failed to init glfw");
    }
    glfwSetErrorCallback(glfwErorCallback);

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_Window = glfwCreateWindow(1280, 720, "Vulkan App", nullptr, nullptr);
}

void VkApp::InitVulkan()
{
    if(s_EnableValidationLayers && !CheckValidationLayerSupport())
    {
        throw std::runtime_error("Validation layers are not available!");
    }

    VkInstanceCreateInfo instanceCreateInfo = {};
    
    uint32_t extensionCount = 0;
    const char** extensions;
    extensions = glfwGetRequiredInstanceExtensions(&extensionCount);

    instanceCreateInfo.enabledExtensionCount = extensionCount;
    instanceCreateInfo.ppEnabledExtensionNames = extensions;
    instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;

    if(s_EnableValidationLayers)
    {
        instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(m_ValidationLayers.size());
        instanceCreateInfo.ppEnabledLayerNames = m_ValidationLayers.data();
    }
    else
    {
        instanceCreateInfo.enabledLayerCount = 0;
    }

    if(vkCreateInstance(&instanceCreateInfo, nullptr, &m_VkInstance))   
        throw std::runtime_error("Failed to create vulkan instance");

    std::vector<VkExtensionProperties> extensionProps(extensionCount);
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensionProps.data());

    for(const auto& extensionProp : extensionProps)
    {
        std::cout << extensionProp.extensionName << '\n';
    }
}

bool VkApp::CheckValidationLayerSupport()
{
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);
    
    std::vector<VkLayerProperties> layerProps(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, layerProps.data());

    for(const char* layerName : m_ValidationLayers)
    {
        bool layerFound;

        for(const auto& layerProp : layerProps)
        {
            if(strcmp(layerName, layerProp.layerName))
            {
                layerFound = true;
                break;
            }
        }

        if(!layerFound)
            return false;
    }

    return true;
}

void VkApp::Init()
{
    InitWindow();
    InitVulkan();
}

void VkApp::MainLoop()
{
    while(!glfwWindowShouldClose(m_Window))
    {

        glfwPollEvents();
    }
    return;
}

void VkApp::Shutdown()
{
    vkDestroyInstance(m_VkInstance, nullptr);
    glfwTerminate();
}