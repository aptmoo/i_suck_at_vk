#include "common/types.h"

#include "common/window.h"

int main(int argc, char const *argv[])
{
    CWindow window({"Vulkan", 1280, 720});

    while (!window.ShouldClose())
    {
        /* code */
    }
    
    return 0;
}
