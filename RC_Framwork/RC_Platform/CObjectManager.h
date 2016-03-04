#ifndef COBJECTMANAGER_H
#define COBJECTMANAGER_H
#include <map>
#include <string>
class CConfig;
struct IModule;
struct IService;
typedef IService* (*exportIService)();
class CObjectManager
{

public:
    CObjectManager(IModule* platform, CConfig* config);

public:
    //开始事件
    void onStartup();

    //结束事件
    void onShutdown();

    //不用key查询
    bool onQuery(const std::string &uiid, void **interface);

    //用key查询
    bool onQuery(const std::string& key, const std::string &uiid, void **interface);
private:
    exportIService loadLibrary(const std::string& key, const std::string& dll);
private:
    //平台
    IModule*                                m_pPlatform;

    //配置
    CConfig*                                m_pConfig;

    //组件映射表
    std::map<std::string, IModule*>         m_mapObjects;

    //组件映射表
    std::map<std::string, IService*>        m_mapService;
};

#endif // COBJECTMANAGER_H
