#ifndef ICONFIG_H
#define ICONFIG_H
#include <string>
struct IConfig
{
    //解析
    virtual bool parse(const std::string& rootkey) = 0;

};
#endif // ICONFIG_H
