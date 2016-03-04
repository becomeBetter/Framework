#ifndef CMODULE_H
#define CMODULE_H
#include "CModuleBase.h"
#include "CConfig.h"
#include "CMainWindow.h"
class CModule : public CModuleBase
{
public:
    CModule(IModule *platform, const std::string& key);
private:
    //初始化事件
    bool onInitialize();

    //反初始化事件
    bool onUnInitialize();

    //启动事件
    bool onStartup();

    //关闭事件
    bool onShutdown();

    //接口查询事件
    bool onQuery(const std::string &uiid, void **interface);
private:
    //配置
    CConfig*                m_pConfig;

    //平台
    IModule*                m_pPlatform;
    
    //主界面
    CMainWindow*            m_pMainWindow;

	QString                 m_strKey;
};

#endif // CMODULE_H
