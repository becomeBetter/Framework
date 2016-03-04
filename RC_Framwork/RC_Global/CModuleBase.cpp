#include "CModuleBase.h"
#include "EComponentType.h"
CModuleBase::CModuleBase(const std::string &key):
   m_strKey(key),
   m_iStatus(0)
{

}

bool CModuleBase::initialize()
{
    if(RC_Framework::EMS_UNINITIALIZED ==  m_iStatus)
    {
        m_iStatus = RC_Framework::EMS_INITIALIZING;

        bool bRet = onInitialize();

        if(bRet == false)
        {
            m_iStatus = RC_Framework::EMS_UNINITIALIZED;
        }else
        {
            m_iStatus = RC_Framework::EMS_INITIALIZED;
        }
    }

    return m_iStatus ==  RC_Framework::EMS_INITIALIZED;
}

bool CModuleBase::unInitialize()
{

    if(RC_Framework::EMS_INITIALIZED == m_iStatus)
    {
        return onUnInitialize();
    }

    return false;
}

bool CModuleBase::startup()
{
    if(m_iStatus != RC_Framework::EMS_INITIALIZED)
    {
        return false;
    }

    return onStartup();
}

bool CModuleBase::shutdown()
{
    if(m_iStatus != RC_Framework::EMS_INITIALIZED)
    {
        return false;
    }

    return onShutdown();
}

bool CModuleBase::query(const std::string &uiid, void **interface)
{
    if(m_iStatus != RC_Framework::EMS_INITIALIZED)
    {
        return false;
    }

    return onQuery(uiid, interface);
}

bool CModuleBase::onInitialize()
{

    return true;
}

bool CModuleBase::onUnInitialize()
{
    return true;
}

bool CModuleBase::onStartup()
{
    return true;
}

bool CModuleBase::onShutdown()
{
    return true;
}

bool CModuleBase::onQuery(const std::string &uiid, void **interface)
{
    return false;
}
