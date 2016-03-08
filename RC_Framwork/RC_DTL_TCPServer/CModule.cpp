#include "CModule.h"
#include "CWorkThread.h"
CModule::CModule(IModule *platform, const std::string &key):
    CModuleBase(key),
    m_pConfig(NULL),
    m_pPlatform(platform),
	m_pTcpServerWorkThread(NULL)
{

}

bool CModule::onInitialize()
{

    m_pConfig = new CConfig;

    m_pConfig->parse("Root");

	m_pTcpServerWorkThread = new CWorkThread(m_pConfig);

    return true;
}

bool CModule::onUnInitialize()
{
    if(NULL != m_pConfig)
    {
        delete m_pConfig;

        m_pConfig = NULL;
    }
	if (NULL != m_pTcpServerWorkThread)
	{
		m_pTcpServerWorkThread->exit();

		m_pTcpServerWorkThread->wait(500);

		delete m_pTcpServerWorkThread;
	}

    return true;
}

bool CModule::onStartup()
{
	m_pTcpServerWorkThread->start();

    return true;
}

bool CModule::onShutdown()
{

    return true;
}

bool CModule::onQuery(const std::string &uiid, void **interface)
{
	bool bRet = true;

	if (IID_TCP_SERVICE == uiid)
	{
		*interface = static_cast<ITcpService*>(m_pTcpServerWorkThread);
	} 
	else
	{
		bRet = false;
	}

    return bRet;
}
