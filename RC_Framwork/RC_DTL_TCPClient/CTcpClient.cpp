#include "CTcpClient.h"

#include <QHostAddress>
CTcpClient::CTcpClient(QObject* parent):
QObject(parent)
{
	m_pClient = new QTcpSocket;

	QObject::connect(m_pClient, SIGNAL(readyRead()), this, SLOT(slotForDataComing()));
}


CTcpClient::~CTcpClient(void)
{
}
//连接
//!ip:远端ip地址
//!port:远端端口
bool CTcpClient::connect(char* ip, unsigned int port)
{
	m_pClient->connectToHost(QHostAddress(ip), port);

	return m_pClient->isValid();
}

//断开连接
bool CTcpClient::disconnect()
{
	m_pClient->disconnectFromHost();

	return true;
}

//发送数据
//!data:发送的数据
//!length:数据长度
int CTcpClient::sendData(char* data, unsigned int length)
{
	if (m_pClient->isValid())
	{
		return m_pClient->write(data, length);
	} 
	else
	{
		return 0;
	}
}

//读取数据
//!buffer:读取数据缓冲区
//!size:缓冲区大小
int CTcpClient::readData(char* buffer, unsigned int size)
{
	if (size >= m_objRecvData.size() && m_objRecvData.size() != 0 )
	{
		int iSize = m_objRecvData.size();

		memcpy(buffer, m_objRecvData.data(), m_objRecvData.size());

		m_objRecvData.clear();

		return iSize;
	} 
	else if (size < m_objRecvData.size() && m_objRecvData.size() != 0)
	{
		memcpy(buffer, m_objRecvData.data(), size);

		m_objRecvData.remove(0, size);

		return size;
	}else
	{
		return 0;
	}
}

//响应数据到来
void CTcpClient::slotForDataComing()
{
	m_objRecvData.append(m_pClient->readAll());
}