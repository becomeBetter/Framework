#include "CModule.h"

CModule::CModule(IModule *platform, const std::string &key):
    CModuleBase(key),
    m_pConfig(NULL),
    m_pPlatform(platform)
{

}

bool CModule::onInitialize()
{

    m_pConfig = new CConfig;

    m_pConfig->parse("Root");

	m_pClient = new CTcpClient;

    return true;
}

bool CModule::onUnInitialize()
{
    if(NULL != m_pConfig)
    {
        delete m_pConfig;

        m_pConfig = NULL;
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

	if(IID_TCP_CLIENT == uiid)
	{
		*interface = static_cast<ITcpClient*>(m_pClient);
	}else if (IID_TCP_SERVICE == uiid)
	{
		*interface = static_cast<ITcpService*>(m_pClient);
	}
	else
	{
		bRet = false;
	}
    return bRet;
}
