#pragma once
#include "ITcpClient.h"
#include <QByteArray>
#include <QTcpSocket>
#include <QObject>
class CTcpClient:public QObject, public ITcpClient
{
	Q_OBJECT
public:
	CTcpClient(QObject* parent = 0);
	~CTcpClient(void);
	//连接
	//!ip:远端ip地址
	//!port:远端端口
	bool connect(char* ip, unsigned int port);

	//断开连接
	bool disconnect();

	//发送数据
	//!data:发送的数据
	//!length:数据长度
	int sendData(char* data, unsigned int length);

	//读取数据
	//!buffer:读取数据缓冲区
	//!size:缓冲区大小
	int readData(char* buffer, unsigned int size);
private:
	//客户端
	QTcpSocket*						m_pClient;

	//接收到的数据
	QByteArray						m_objRecvData;
private slots:
	//响应数据到来
	void slotForDataComing();
};

