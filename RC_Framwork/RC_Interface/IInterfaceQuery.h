#ifndef IINTERFACEQUERY_H
#define IINTERFACEQUERY_H
#include <string>
#define IID_PLATFORM_QUERY ("A57FC9F1-49B1-463F-960D-31BAA3127F2F")

struct IInterfaceQuery
{
    //接口查询
    virtual bool platformQuery(const std::string& key, const std::string& uiid, void** interface) = 0;
};
#endif // IINTERFACEQUERY_H
