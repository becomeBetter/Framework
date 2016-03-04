#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
	m_strFilePath = "Config";

    m_strFileName = "RC_MainFrame.xml";
}

bool CConfig::onParse(const QDomElement &root)
{
	//�����˵�����
	QDomElement menuType = root.firstChildElement("MenuType");

	if(menuType.isElement())
	{
		m_strMenuType = menuType.text();
	}

	QDomElement pageSwitchEvent = root.firstChildElement("PageSwitchEvent");

	if(!pageSwitchEvent.isElement())//��Щ������ܲ����л����棬���Կ��Է���true
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
//��ȡ�˵�����
QString CConfig::getMenuType() const
{
	return m_strMenuType;
}

//��ȡҳ���л��¼���Ϣ
const QMap<QString, QString>& CConfig::getPageSwitchEventInfo() const
{
	return m_mapPageSwitchEventInfo;
}