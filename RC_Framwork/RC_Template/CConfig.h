#ifndef CCONFIG_H
#define CCONFIG_H
#include "CConfigBase.h"
class CConfig : public CConfigBase
{
public:
    CConfig();
public:
    bool onParse(const QDomElement& root);
};

#endif // CCONFIG_H
