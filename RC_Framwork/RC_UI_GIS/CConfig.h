#ifndef CCONFIG_H
#define CCONFIG_H
#include "CConfigBase.h"
class CConfig : public CConfigBase
{
public:
    CConfig();
public:
    bool onParse(const QDomElement& root);

	QString getFileURL() const;
private:
	QString				m_strFileURL;
};

#endif // CCONFIG_H
