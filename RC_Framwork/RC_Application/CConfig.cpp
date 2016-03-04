#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
    m_strFilePath = "Config";

    m_strFileName = "RC_Application.xml";
}
//解析配置
bool CConfig::onParse(const QDomElement &root)
{
	QDomElement theme = root.firstChildElement("Theme");//主题

	if(theme.isElement())
	{
		m_strThemeFile = theme.text().toStdString();
	}

	QDomElement platform = root.firstChildElement("Platform");//平台

	if(platform.isElement())
	{
		m_strPlatform = platform.text().toStdString();
	}

	QDomElement mainframe = root.firstChildElement("MainFrame");//主界面

	if(mainframe.isElement())
	{
		m_strMainFrame = mainframe.text().toStdString();
	}
    return true;
}

//获取平台dll名称
std::string CConfig::getPlatform() const
{
    return m_strPlatform;
}

//获取主界面dll名称
std::string CConfig::getMainUI() const
{
    return m_strMainFrame;
}

//获取主题文件名
std::string CConfig::getThemeFile() const
{
    return m_strThemeFile;
}
