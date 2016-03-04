#ifndef CCONFIG_H
#define CCONFIG_H
#include "CConfigBase.h"
class CConfig : public CConfigBase
{
public:
    CConfig();
public:
    //解析配置
    bool onParse(const QDomElement& root);

    //获取平台dll名称
    std::string getPlatform() const;

    //获取主界面dll名称
    std::string getMainUI() const;

    //获取主题文件名
    std::string getThemeFile() const;
private:
    //平台dll名称
    std::string             m_strPlatform;

    //主界面dll名称
    std::string             m_strMainFrame;

    //主题文件
    std::string             m_strThemeFile;
};

#endif // CCONFIG_H
