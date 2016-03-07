#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
	m_strFilePath = "Config";

    m_strFileName = "RC_UI_Template.xml";
}

bool CConfig::onParse(const QDomElement &root)
{

    return true;
}
