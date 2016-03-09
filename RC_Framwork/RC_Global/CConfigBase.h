#ifndef CCONFIGBASE_H
#define CCONFIGBASE_H
#include "IConfig.h"
#include <string>
#include <QDomElement>
class CConfigBase : public IConfig
{
public:
    CConfigBase();
public:
    //解析
    bool parse(const std::string& rootkey, const std::string& inskey = "");
public:
    virtual bool onParse(const QDomElement& root);
public:
    //文件路径
    std::string                 m_strFilePath;

    //文件名
    std::string                 m_strFileName;
};

#endif // CCONFIGBASE_H
