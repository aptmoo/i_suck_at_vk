#ifndef VKAPP_H
#define VKAPP_H
#include "app.h"
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <vector>

class VkApp : public AppBase
{
public:
    virtual void Init() override;
    virtual void MainLoop() override;
    virtual void Shutdown() override;
private:
    void InitWindow();
    void InitVulkan();

    bool CheckValidationLayerSupport();

    VkInstance m_VkInstance;
    GLFWwindow* m_Window;

    std::vector<const char*> m_ValidationLayers = 
    {
        "VK_LAYER_KHRONOS_validation"
    };

    #ifdef NDEBUG
    static const bool s_EnableValidationLayers = false;
    #else
    static const bool s_EnableValidationLayers = true;
    #endif
};

#endif