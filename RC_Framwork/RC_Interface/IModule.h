#ifndef IMODULE_H
#define IMODULE_H
#include <string>
struct IModule
{
    //初始化
    virtual bool initialize() = 0;

    //反初始化
    virtual bool unInitialize() = 0;

    //启动
    virtual bool startup() = 0;

    //关闭
    virtual bool shutdown() = 0;

    //接口查询
    virtual bool query(const std::string& uiid, void** interface) = 0;
};
#endif // IMODULE_H
