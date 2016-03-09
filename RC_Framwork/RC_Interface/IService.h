#ifndef ISERVICE_H
#define ISERVICE_H
#include <string>
struct IModule;
struct IService
{
    //组件类型
    virtual int getType() const = 0;

    //创建实例
    virtual IModule* createInstance(IModule* platform, const std::string& key, void* param) = 0;

    //销毁实例
    virtual bool destroyInstance(IModule* instance) = 0;

};
#endif // ISERVICE_H
