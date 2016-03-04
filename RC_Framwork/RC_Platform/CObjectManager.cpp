#include "CObjectManager.h"
#include "CConfig.h"
#include "IService.h"
#include "IModule.h"
#include <QLibrary>

CObjectManager::CObjectManager(IModule* platform, CConfig *config):
    m_pConfig(config),
    m_pPlatform(platform)
{

}

void CObjectManager::onStartup()
{
    std::map<std::string, std::string> &mapComponents = m_pConfig->getComponents();

    std::map<std::string, std::string>::iterator iter = mapComponents.begin();

    for(iter; iter != mapComponents.end(); ++iter )
    {
        //加载动态库 返回getIService接口
        exportIService pIservice = loadLibrary(iter->first, iter->second);

        if(NULL == pIservice)
        {
            continue;
        }

        //创建实例
        IService* pService = pIservice();

        IModule* pModule = pService->createInstance(m_pPlatform, iter->first, NULL);

        if(NULL == pModule)
        {
            continue;
        }
        //添加到列表
        m_mapObjects.insert(std::map<std::string, IModule*>::value_type(iter->first, pModule));

        m_mapService.insert(std::map<std::string, IService*>::value_type(iter->first, pService));
    }

    std::map<std::string, IModule*>::iterator insIter = m_mapObjects.begin();

    for(insIter; insIter != m_mapObjects.end(); ++insIter)
    {
        //启动
        insIter->second->startup();
    }
}

void CObjectManager::onShutdown()
{
    std::map<std::string, IModule*>::iterator insIter = m_mapObjects.begin();

    for(insIter; insIter != m_mapObjects.end(); ++insIter)
    {
        //关闭
        insIter->second->shutdown();
    }

    insIter = m_mapObjects.begin();

    for(insIter; insIter != m_mapObjects.end(); ++insIter)
    {
        //销毁
        std::map<std::string, IService*>::iterator srvIter = m_mapService.find(insIter->first);

        if(srvIter != m_mapService.end())
        {
            IService* pIService = srvIter->second;

            pIService->destroyInstance(insIter->second);
        }
    }

    m_mapObjects.clear();

    m_mapService.clear();
}

bool CObjectManager::onQuery(const std::string &uiid, void **interface)
{
    bool bRet = false;

    std::map<std::string, IModule*>::iterator insIter = m_mapObjects.begin();

    for(insIter; insIter != m_mapObjects.end(); ++insIter)
    {
        //关闭
        bRet = insIter->second->query(uiid, interface);

        if(bRet)
        {
            break;
        }
    }
    return bRet;
}

bool CObjectManager::onQuery(const std::string &key, const std::string &uiid, void **interface)
{
    bool bRet = false;

    std::map<std::string, IModule*>::iterator insIter = m_mapObjects.begin();

    for(insIter; insIter != m_mapObjects.end(); ++insIter)
    {
        if(key != insIter->first)
        {
            continue;
        }
        //关闭
        bRet = insIter->second->query(uiid, interface);

        if(bRet)
        {
            break;
        }
    }
    return bRet;
}

exportIService CObjectManager::loadLibrary(const std::string &key, const std::string &dll)
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
