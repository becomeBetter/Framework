#ifndef IINTERFACEHANDLER_H
#define IINTERFACEHANDLER_H
#include <string>
#include "IModule.h"
#include "IInterfaceQuery.h"
namespace Framework {
    template<class T>
    bool getInterface(IModule* platform, const std::string& key, const std::string& uiid, T** interface)
    {
		if(NULL == platform)
		{
			return false;
		}

		if(NULL != *interface)//防止重复查询带来的性能问题，所以对用户来说interface要初始化
		{
			return true;
		}

        IInterfaceQuery* pQuery = NULL;

        bool bRet = platform->query(IID_PLATFORM_QUERY, (void**)&pQuery);

        if(false == bRet)
        {
            *interface = NULL;

            return bRet;
        }

        return pQuery->platformQuery(key, uiid, (void**)interface);
    }
}

#endif // IINTERFACEHANDLER_H
