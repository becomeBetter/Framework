#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
	m_strFilePath = "Config";

    m_strFileName = "RC_UI_GIS.xml";
}

bool CConfig::onParse(const QDomElement &root)
{
	QDomElement file = root.firstChildElement("File");

	if(file.isElement())
	{
		m_strFileURL = file.text();
	}
    return true;
}

//��ȡGIS html�ļ�·��
QString CConfig::getFileURL() const
{
	return m_strFileURL;
}	