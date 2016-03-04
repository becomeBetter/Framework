#include "CAppLauncher.h"
#include "CConfig.h"
#include "IModule.h"
#include "IService.h"
#include "IWidget.h"
#include <QLibrary>
#include <QWidget>
#include <QFile>
#include <QApplication>
#include <QDir>
CAppLauncher::CAppLauncher(CConfig *config):
    m_pConfig(config)
{
    m_pMainFrame = NULL;

    m_pMainFrameService = NULL;

    m_pPlatform = NULL;

    m_pPlatformService = NULL;
}
//启动事件
void CAppLauncher::onStartup()
{
    //加载平台 平台加载其他组件

    if(false == startPlatform())
    {
        return;
    }

    //启动主界面
    bool bRet = startMainFrame(m_pPlatform);

    //设置皮肤
    bRet = setSkin();
}

//关闭事件
void CAppLauncher::onShutdown()
{
    //调用平台的shutdown
    if(m_pPlatform)
    {
        m_pPlatform->shutdown();
    }

    if(m_pPlatform && m_pPlatformService)
    {
        m_pPlatformService->destroyInstance(m_pPlatform);
    }

    if(m_pMainFrame)
    {
        m_pMainFrame->shutdown();
    }

    if(m_pMainFrame && m_pMainFrameService)
    {
        m_pMainFrameService->destroyInstance(m_pMainFrame);
    }

    m_pMainFrame = NULL;

    m_pMainFrameService = NULL;

    m_pPlatform = NULL;

    m_pPlatformService = NULL;
}

exportIService CAppLauncher::loadLibrary(const std::string &dll)
{
    exportIService pIService = NULL;

    QLibrary lib(QString::fromStdString(dll));

    lib.load();

    do
    {
        if(!lib.isLoaded())
        {
            break;
        }

        pIService = (exportIService)lib.resolve("getIService");

    }while(0);

    return pIService;
}

bool CAppLauncher::startPlatform()
{
    bool bRet = false;

    do
    {
        exportIService pIservice = loadLibrary(m_pConfig->getPlatform());

        if(NULL == pIservice)
        {
            break;
        }

        //创建实例
        IService* pService = pIservice();

        IModule* pModule = pService->createInstance(NULL, "", NULL);

        if(NULL == pModule)
        {
            break;
        }
        //启动平台
        pModule->startup();

        m_pPlatformService = pService;

        m_pPlatform = pModule;

        bRet = true;

    }while(0);

    return bRet;
}

bool CAppLauncher::startMainFrame(IModule* platform)
{
    bool bRet = false;

    do
    {
        exportIService pIservice = loadLibrary(m_pConfig->getMainUI());

        if(NULL == pIservice)
        {
            break;
        }

        //创建实例
        IService* pService = pIservice();

        IModule* pModule = pService->createInstance(platform, "", NULL);

        if(NULL == pModule)
        {
            break;
        }

        pModule->startup();

        m_pMainFrame = pModule;

        m_pMainFrameService = pService;

        IWidget* pMainUI = NULL;

        bRet = pModule->query(IID_WIDGET, (void**)&pMainUI);

        if(bRet == false)
        {
            break;
        }

        QWidget* pMainFrame = pMainUI->getUI();

		pMainFrame->showMaximized();

        bRet = true;
    }while(0);

    return bRet;
}

bool CAppLauncher::setSkin()
{
    bool bRet = false;

    do
    {
		QFile file(QString::fromStdString(m_pConfig->getThemeFile()));
		
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            break;
        }

        qApp->setStyleSheet(file.readAll());

        file.close();

        bRet = true;
    }while(0);

    return bRet;
}
