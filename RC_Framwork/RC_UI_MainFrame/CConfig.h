#ifndef CCONFIG_H
#define CCONFIG_H
#include "CConfigBase.h"
#include <QString>
#include <QMap>
class CConfig : public CConfigBase
{
public:
    CConfig();
public:
    bool onParse(const QDomElement& root);

	//获取菜单类型
	QString getMenuType() const;

	//获取页面切换事件信息
	const QMap<QString, QString>& getPageSwitchEventInfo() const;
private:
	//菜单类型
	QString								m_strMenuType;

	//页面切换事件信息
	QMap<QString, QString>				m_mapPageSwitchEventInfo;

};

#endif // CCONFIG_H
