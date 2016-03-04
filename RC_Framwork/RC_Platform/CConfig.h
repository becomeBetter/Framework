#ifndef CCONFIG_H
#define CCONFIG_H
#include "CConfigBase.h"
#include <map>
#include <string>
class CConfig : public CConfigBase
{
public:
    CConfig();
public:
    bool onParse(const QDomElement& root);

    std::map<std::string, std::string>& getComponents();

private:
    //组件列表 key动态库实例标志 value为动态库名称
    std::map<std::string, std::string>      m_mapComponents;
};

#endif // CCONFIG_H
