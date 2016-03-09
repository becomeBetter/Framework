#include "CModuleBase.h"
#include "EComponentType.h"
CModuleBase::CModuleBase(const std::string &key):
   m_strKey(key),
   m_iStatus(0)
{

}
//初始化
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

//反初始化
bool CModuleBase::unInitialize()
{

    if(RC_Framework::EMS_INITIALIZED == m_iStatus)
    {
        return onUnInitialize();
    }

    return false;
}

//启动
bool CModuleBase::startup()
{
    if(m_iStatus != RC_Framework::EMS_INITIALIZED)
    {
        return false;
    }

    return onStartup();
}

//关闭
bool CModuleBase::shutdown()
{
    if(m_iStatus != RC_Framework::EMS_INITIALIZED)
    {
        return false;
    }

    return onShutdown();
}

//获取key
std::string CModuleBase::key() const
{
	return m_strKey;
}

//获取状态 
unsigned int CModuleBase::status() const
{
	return m_iStatus;
}
//接口查询
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
