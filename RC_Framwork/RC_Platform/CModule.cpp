#include "CModule.h"

CModule::CModule(IModule *platform, const std::string &key):
    CModuleBase(key),
    m_pConfig(NULL),
    m_pPlatform(platform),
    m_pObjectManger(NULL)
{
}

bool CModule::onInitialize()
{

    m_pConfig = new CConfig;

    m_pConfig->parse("Root");


    m_pObjectManger = new CObjectManager(this, m_pConfig);

    m_pObjectManger->onStartup();

    return true;
}

bool CModule::onUnInitialize()
{
    if(NULL != m_pConfig)
    {
        delete m_pConfig;

        m_pConfig = NULL;
    }

    if(NULL != m_pObjectManger)
    {
        m_pObjectManger->onShutdown();

        delete m_pObjectManger;

        m_pObjectManger = NULL;
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
    if(IID_PLATFORM_QUERY == uiid)
    {
        *interface = static_cast<IInterfaceQuery*>(this);

        return true;
    }

    return m_pObjectManger->onQuery(uiid, interface);
}

bool CModule::platformQuery(const std::string &key, const std::string &uiid, void **interface)
{
    return m_pObjectManger->onQuery(key, uiid, interface);
}
