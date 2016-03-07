#include "CModule.h"

CModule::CModule(IModule *platform, const std::string &key):
    CModuleBase(key),
    m_pConfig(NULL),
    m_pMainWindow(NULL),
    m_pPlatform(platform)
{
}

bool CModule::onInitialize()
{

    m_pConfig = new CConfig;

    m_pConfig->parse("Root");

    m_pMainWindow = new CMainWindow(m_pPlatform, m_pConfig);

    m_pMainWindow->onStartup();

    return true;
}

bool CModule::onUnInitialize()
{
    if(NULL != m_pConfig)
    {
        delete m_pConfig;

        m_pConfig = NULL;
    }

    if(NULL != m_pMainWindow)
    {
        m_pMainWindow->onShutdown();

        delete m_pMainWindow;

        m_pMainWindow = NULL;
    }
    return true;
}

bool CModule::onStartup()
{

    return true;
}

bool CModule::onShutdown()
{

    return true;
}

bool CModule::onQuery(const std::string &uiid, void **interface)
{
    bool bRet = true;

    if(uiid == IID_WIDGET)
    {
        *interface = static_cast<IWidget*>(m_pMainWindow);
    }else
    {
        bRet = false;
    }
    return bRet;
}
