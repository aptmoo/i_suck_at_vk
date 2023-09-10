#include "app/app.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char const *argv[])
{
    std::unique_ptr<AppBase> app = AppBase::CreateInstance();
    try
    {
        app->Init();
        app->MainLoop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    app->Shutdown();
    return 0;
}
