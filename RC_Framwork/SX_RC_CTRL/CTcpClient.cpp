#include "CTcpClient.h"
#include "ITcpDataWatcher.h"
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
//����
//!ip:Զ��ip��ַ
//!port:Զ�˶˿�
bool CTcpClient::connect(char* ip, unsigned int port)
{
	m_pClient->connectToHost(QHostAddress(ip), port);

	return m_pClient->isValid();
}

//�Ͽ�����
bool CTcpClient::disconnect()
{
	m_pClient->disconnectFromHost();

	return true;
}

//��������
//!data:���͵�����
//!length:���ݳ���
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

//��ȡ����
//!buffer:��ȡ���ݻ�����
//!size:��������С
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
//�۲���ע��
bool CTcpClient::registry(ITcpDataWatcher* watcher)
{
	m_vecWatchers.append(watcher);

	return true;
}

//�۲���ȡ��ע��
bool CTcpClient::unRegistry(ITcpDataWatcher* watcher)
{
	m_vecWatchers.remove(m_vecWatchers.indexOf(watcher));

	return true;
}
//��Ӧ���ݵ���
void CTcpClient::slotForDataComing()
{
	if (m_vecWatchers.size() > 0)//�й۲���ע�ᣬ����ù۲���֪ͨ����
	{
		int iSize = m_vecWatchers.size();

		for (int i = 0; i < iSize; ++i)
		{
			m_vecWatchers.at(i)->tcpDataComingNotify(m_pClient->readAll(), (void*)sender());
		}
	}else
	{
		m_objRecvData.append(m_pClient->readAll());
	}
}