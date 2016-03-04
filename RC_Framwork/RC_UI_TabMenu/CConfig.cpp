#include "CConfig.h"

CConfig::CConfig():
    CConfigBase()
{
    m_strFilePath = "Config";

    m_strFileName = "RC_UI_TabMenu.xml";
}

bool CConfig::onParse(const QDomElement &root)
{
    int iSize = root.childNodes().size();

    QDomNodeList& children = root.childNodes();

    for(int i = 0; i < iSize; ++i)
    {
        QDomElement item = children.at(i).toElement();

        if(!item.hasAttribute("text"))//排除注释节点
        {
            continue;
        }

        CMenuItem menuitem;

        menuitem.strId = item.attribute("id");

        menuitem.strText = item.attribute("text");

        menuitem.strIcon = item.attribute("icon");

        m_vecMenuItems.append(menuitem);
    }
    return true;
}

QVector<CMenuItem> &CConfig::getMenuItems()
{
    return m_vecMenuItems;
}
