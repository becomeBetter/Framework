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

	//��ȡ�˵�����
	QString getMenuType() const;

	//��ȡҳ���л��¼���Ϣ
	const QMap<QString, QString>& getPageSwitchEventInfo() const;
private:
	//�˵�����
	QString								m_strMenuType;

	//ҳ���л��¼���Ϣ
	QMap<QString, QString>				m_mapPageSwitchEventInfo;

};

#endif // CCONFIG_H
