#ifndef CSERVICE_H
#define CSERVICE_H
#include "IService.h"
struct IModule;
class CService : public IService
{
public:
    CService();
public:
    //组件类型
    int getType() const;

    //创建实例
    IModule* createInstance(IModule* platform, const std::string& key, void* param);

    //销毁实例
    bool destroyInstance(IModule* instance);
};

#endif // CSERVICE_H
