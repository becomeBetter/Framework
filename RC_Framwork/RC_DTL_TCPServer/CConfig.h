#ifndef CCONFIG_H
#define CCONFIG_H
#include "CConfigBase.h"
class CConfig : public CConfigBase
{
public:
    CConfig();
public:
    bool onParse(const QDomElement& root);

	//��ȡ�����˿�
	int getListenPort() const;
private:
	//�����˿�
	int			m_iListenPort;
};

#endif // CCONFIG_H
