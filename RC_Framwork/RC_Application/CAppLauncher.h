#ifndef CAPPLAUNCHER_H
#define CAPPLAUNCHER_H
#include <string>
struct CConfig;
struct IService;
struct IModule;
typedef IService* (*exportIService)();
class CAppLauncher
{
public:
    CAppLauncher(CConfig* config);

    //启动事件
    void onStartup();

    //关闭事件
    void onShutdown();
private:
    exportIService loadLibrary(const std::string& dll);

    //启动平台
    bool startPlatform();

    //启动主界面
    bool startMainFrame(IModule* platform);
    
    //设置皮肤
    bool setSkin();
private:
    //配置
    CConfig*            m_pConfig;

    //平台IService
    IService*           m_pPlatformService;

    //平台实例
    IModule*            m_pPlatform;

    //主界面IService
    IService*           m_pMainFrameService;

    //主界面实例
    IModule*            m_pMainFrame;
};

#endif // CAPPLAUNCHER_H
