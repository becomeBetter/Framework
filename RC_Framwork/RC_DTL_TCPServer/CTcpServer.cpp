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

//��Ӧ������
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
//��Ӧ�ͻ��˵����ݵ���
void CTcpServer::slotForDataComing()
{
	QTcpSocket* pClient = (QTcpSocket*)sender();

	QByteArray objData = pClient->readAll();

	emit signalDataComing(objData, pClient);
}

//��Ӧ�ͻ��˶Ͽ�����
void CTcpServer::slotForDisconnect()
{
	QTcpSocket* pClient = (QTcpSocket*)sender();

	pClient->write("see you again!");

	m_vecClients.remove(m_vecClients.indexOf(pClient));
}