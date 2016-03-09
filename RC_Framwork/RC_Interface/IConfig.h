#ifndef ICONFIG_H
#define ICONFIG_H
#include <string>
struct IConfig
{
    //解析
	//!rootkey:xml文件根节点标签名
	//!inskey:模块实例标签名
    virtual bool parse(const std::string& rootkey, const std::string& inskey = "") = 0;
};
#endif // ICONFIG_H
