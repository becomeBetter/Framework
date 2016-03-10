#pragma once
#include "ITcpClient.h"
#include "ITcpService.h"
#include <QByteArray>
#include <QTcpSocket>
#include <QObject>
#include <QVector>
class ITcpDataWatcher;
class CTcpClient:public QObject, public ITcpClient,public ITcpService
{
	Q_OBJECT
public:
	CTcpClient(QObject* parent = 0);
	~CTcpClient(void);
	//����
	//!ip:Զ��ip��ַ
	//!port:Զ�˶˿�
	bool connect(char* ip, unsigned int port);

	//�Ͽ�����
	bool disconnect();

	//��������
	//!data:���͵�����
	//!length:���ݳ���
	int sendData(char* data, unsigned int length);

	//��ȡ����
	//!buffer:��ȡ���ݻ�����
	//!size:��������С
	int readData(char* buffer, unsigned int size);

	//�۲���ע��
	bool registry(ITcpDataWatcher* watcher);

	//�۲���ȡ��ע��
	bool unRegistry(ITcpDataWatcher* watcher);

private:
	//�ͻ���
	QTcpSocket*						m_pClient;

	//���յ�������
	QByteArray						m_objRecvData;

	//�۲����б�
	QVector<ITcpDataWatcher*>		m_vecWatchers;

private slots:
	//��Ӧ���ݵ���
	void slotForDataComing();
};

