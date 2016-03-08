#include "CService.h"
#include "RC_Framework_Export.h"
#include "CModule.h"
#include "EComponentType.h"
CService::CService()
{
}

//组件类型
int CService::getType() const
{
    return RC_Framework::ECT_BUSSINESS_LOGIC;
}

//创建实例
IModule *CService::createInstance(IModule *platform, const std::string &key, void *param)
{
    CModule *pModule = new CModule(platform, key);

    if(NULL == pModule)
    {
        return NULL;
    }

    if(false == pModule->initialize())
    {
        delete pModule;

        return NULL;
    }

    return pModule;
}
//销毁实例
bool CService::destroyInstance(IModule *instance)
{

    CModule *pModule = dynamic_cast<CModule*>(instance);

    if(NULL != pModule)
    {
        pModule->unInitialize();

        delete pModule;

        return true;
    }else
    {
        return false;
    }
}

//导出getIService接口
extern "C" RC_FRAMEWORKSHARED_EXPORT IService* getIService()
{
    static CService service;

    return &service;
}
