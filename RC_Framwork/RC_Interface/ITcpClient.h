#ifndef ITCPCLIENT_H_
#define ITCPCLIENT_H_
#define IID_TCP_CLIENT ("DCF398E5-B074-45D9-AC22-503401957032")

struct ITcpClient
{
	//连接
	//!ip:远端ip地址
	//!port:远端端口
	virtual bool connect(char* ip, unsigned int port) = 0;

	//断开连接
	virtual bool disconnect() = 0;

	//发送数据
	//!data:发送的数据
	//!length:数据长度
	virtual int sendData(char* data, unsigned int length) = 0;

	//读取数据
	//!buffer:读取数据缓冲区
	//!size:缓冲区大小
	virtual int readData(char* buffer, unsigned int size) = 0;
};
#endif