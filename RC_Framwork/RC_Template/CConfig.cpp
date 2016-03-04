#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
    m_strFilePath = "";

    m_strFileName = "";
}

bool CConfig::onParse(const QDomElement &root)
{

    return true;
}
