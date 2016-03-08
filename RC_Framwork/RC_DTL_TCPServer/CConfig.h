#ifndef CCONFIG_H
#define CCONFIG_H
#include "CConfigBase.h"
class CConfig : public CConfigBase
{
public:
    CConfig();
public:
    bool onParse(const QDomElement& root);

	//获取监听端口
	int getListenPort() const;
private:
	//监听端口
	int			m_iListenPort;
};

#endif // CCONFIG_H
