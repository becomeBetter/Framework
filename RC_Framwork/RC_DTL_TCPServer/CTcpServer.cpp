#include "CTcpServer.h"

CTcpServer::CTcpServer(QObject *parent, unsigned int port)
	: QTcpServer(parent),
	m_iPort(port)
{
	
}

CTcpServer::~CTcpServer()
{
	
}
bool CTcpServer::initialize()
{
	m_vecClients.clear();

	bool bRet = listen(QHostAddress::Any, m_iPort);

	connect(this, SIGNAL(newConnection()), this, SLOT(slotForNewConnectionComing()));

	return bRet;
}


void CTcpServer::unInitialize()
{

}

//响应新连接
void CTcpServer::slotForNewConnectionComing()
{
	while (hasPendingConnections())
	{
		QTcpSocket* pClient = nextPendingConnection();

		if(NULL == pClient)
		{
			break;
		}

		pClient->write("welcome!");

		m_vecClients.append(pClient);

		connect(pClient, SIGNAL(readyRead()), this, SLOT(slotForDataComing()));

		connect(pClient, SIGNAL(disconnected()), this, SLOT(slotForDisconnect()));
	}
}
//响应客户端的数据到来
void CTcpServer::slotForDataComing()
{
	QTcpSocket* pClient = (QTcpSocket*)sender();

	QByteArray objData = pClient->readAll();

	emit signalDataComing(objData, pClient);
}

//响应客户端断开请求
void CTcpServer::slotForDisconnect()
{
	QTcpSocket* pClient = (QTcpSocket*)sender();

	pClient->write("see you again!");

	m_vecClients.remove(m_vecClients.indexOf(pClient));
}