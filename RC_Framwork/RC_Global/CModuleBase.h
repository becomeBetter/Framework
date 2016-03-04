#ifndef CMODULEBASE_H
#define CMODULEBASE_H
#include "IModule.h"

class CModuleBase : public IModule
{
public:
    CModuleBase(const std::string& key);
public:
    //初始化
    bool initialize();

    //反初始化
    bool unInitialize();

    //启动
    bool startup();

    //关闭
    bool shutdown();

    //接口查询
    bool query(const std::string& uiid, void** interface);
public:
    //初始化事件
    virtual bool onInitialize();

    //反初始化事件
    virtual bool onUnInitialize();

    //启动事件
    virtual bool onStartup();

    //关闭事件
    virtual bool onShutdown();

    //接口查询事件
    virtual bool onQuery(const std::string &uiid, void **interface);
private:
    //模块标识
    std::string             m_strKey;

    //模块状态
    unsigned int            m_iStatus;

};

#endif // CMODULEBASE_H
