#include "app.h"
#include "vkapp.h"

std::unique_ptr<AppBase> AppBase::CreateInstance()
{
    return std::make_unique<VkApp>();
}