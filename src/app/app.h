#ifndef APP_H
#define APP_H
#include <memory>

class AppBase
{
public:
    virtual void Init() = 0;
    virtual void MainLoop() = 0;
    virtual void Shutdown() = 0;

    static std::unique_ptr<AppBase> CreateInstance();
};

#endif