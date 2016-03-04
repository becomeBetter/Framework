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

		if(NULL != *interface)//��ֹ�ظ���ѯ�������������⣬���Զ��û���˵interfaceҪ��ʼ��
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
