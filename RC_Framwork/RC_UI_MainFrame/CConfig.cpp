#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
	m_strFilePath = "Config";

    m_strFileName = "RC_MainFrame.xml";
}

bool CConfig::onParse(const QDomElement &root)
{
	//解析菜单类型
	QDomElement menuType = root.firstChildElement("MenuType");

	if(menuType.isElement())
	{
		m_strMenuType = menuType.text();
	}

	QDomElement pageSwitchEvent = root.firstChildElement("PageSwitchEvent");

	if(!pageSwitchEvent.isElement())//有些程序可能不用切换界面，所以可以返回true
	{
		return true;
	}

	int iSize = pageSwitchEvent.childNodes().size();

	QDomNodeList &children = pageSwitchEvent.childNodes();

	for(int i = 0; i < iSize; ++i)
	{
		QDomElement item = children.at(i).toElement();

		if(!item.hasAttribute("menuid"))
		{
			continue;
		}

		m_mapPageSwitchEventInfo.insert(item.attribute("menuid"), item.attribute("pagekey"));
	}
    return true;
}
//获取菜单类型
QString CConfig::getMenuType() const
{
	return m_strMenuType;
}

//获取页面切换事件信息
const QMap<QString, QString>& CConfig::getPageSwitchEventInfo() const
{
	return m_mapPageSwitchEventInfo;
}