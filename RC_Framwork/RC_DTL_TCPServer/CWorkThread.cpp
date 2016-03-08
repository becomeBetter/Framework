#include "CWorkThread.h"
#include "CTcpServer.h"
#include "CConfig.h"
#include "ITcpDataWatcher.h"
#include <QTcpServer>
CWorkThread::CWorkThread(CConfig* config, QObject *parent)
	: QThread(parent),
	m_pConfig(config)
{
	//qRegisterMetaType<QByteArray>("QByteArray");
}

CWorkThread::~CWorkThread()
{

}
//�۲���ע��
bool CWorkThread::registry(ITcpDataWatcher* watcher)
{
	m_vecWatchers.append(watcher);

	return true;
}

//�۲���ȡ��ע��
bool CWorkThread::unRegistry(ITcpDataWatcher* watcher)
{
	m_vecWatchers.remove(m_vecWatchers.indexOf(watcher));

	return true;
}

void CWorkThread::run()
{
	CTcpServer tcpServer(NULL, m_pConfig->getListenPort());

	tcpServer.initialize();

	connect(&tcpServer, SIGNAL(signalDataComing(QByteArray, void*)), SLOT(slotForDataComing(QByteArray, void*)));
	
	exec();
}
//��Ӧ���ݵ���
void CWorkThread::slotForDataComing(QByteArray data, void* client)
{
	int iSize = m_vecWatchers.size();

	for(int i = 0; i < iSize; ++i)
	{
		m_vecWatchers.at(i)->tcpDataComingNotify(data, client);
	}
}