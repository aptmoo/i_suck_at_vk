#ifndef WINDOW_H
#define WINDOW_H
#include <string>
#include "common/types.h"

struct SWindowDesc
{
    std::string Name;
    u32 Width, Height;
};


class CWindow
{
private:
    /**
     * @brief GLFW window handle.
     * 
     */
    void* m_pWindow;

public:
    /**
     * @brief CWindow constructor.
     * Creates window, but does not init some kind of context.
     * 
     * @param desc 
     */
    CWindow(const SWindowDesc& desc);

    /**
     * @brief Destroys this window. Any previously gotten handles are now invalid.
     * 
     */
    ~CWindow();

    void Update();
    
    /**
     * @brief Should this window close?
     * 
     * @return true 
     * @return false 
     */
    bool ShouldClose();

    /**
     * @brief Get the GLFW window handle.
     * 
     * @return void* 
     */
    void* GetNativeHandle();
};

#endif