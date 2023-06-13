#include "window.h"
#include "GLFW/glfw3.h"

#include <cstdio>

/*
    Counter to track the amount of windows.
    This counter is used to 
    TODO: u16?
*/
static u8 s_uWindowCount{};

static void WindowErrorCallback(int errc, const char* desc)
{
    // TODO: Error handling.
    std::printf("GLFW Error %d:\n%s\n", errc, desc);
}

CWindow::CWindow(const SWindowDesc& desc)
{
    if(!s_uWindowCount)
    {
        // TODO: Error handling
        glfwInit();
        s_uWindowCount++;
    }

    glfwSetErrorCallback(WindowErrorCallback);

    m_pWindow = glfwCreateWindow(desc.Width, desc.Height, desc.Name.c_str(), nullptr, nullptr);
}

CWindow::~CWindow()
{
    glfwDestroyWindow((GLFWwindow*)m_pWindow);

    s_uWindowCount--;
    if(!s_uWindowCount)
        glfwTerminate();
}

bool CWindow::ShouldClose()
{
    return glfwWindowShouldClose((GLFWwindow*)m_pWindow);
}

void* CWindow::GetNativeHandle()
{
    return m_pWindow;
}

