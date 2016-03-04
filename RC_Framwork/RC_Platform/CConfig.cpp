#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
    m_strFilePath = "Config";

    m_strFileName = "RC_Platform.xml";
}

bool CConfig::onParse(const QDomElement &root)
{
    int iSize = root.childNodes().size();

    QDomNodeList& children = root.childNodes();

    for(int i = 0; i < iSize; ++i)
    {
        QDomElement item = children.at(i).toElement();

        if(!item.hasAttribute("key"))//排除注释节点
        {
            continue;
        }
        std::string strKey = item.attribute("key").toStdString();

        std::string strValue = item.attribute("value").toStdString();

        m_mapComponents.insert(std::map<std::string, std::string>::value_type(strKey, strValue));
    }
    return true;
}

std::map<std::string, std::string> &CConfig::getComponents()
{

    return m_mapComponents;
}
