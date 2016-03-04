#ifndef CCONFIG_H
#define CCONFIG_H
#include "CConfigBase.h"
#include "CMenuItem.h"
#include <QVector>
class CConfig : public CConfigBase
{
public:
    CConfig();
public:
    bool onParse(const QDomElement& root);

    //获取菜单项列表
    QVector<CMenuItem>& getMenuItems();
private:
    QVector<CMenuItem>             m_vecMenuItems;
};

#endif // CCONFIG_H
