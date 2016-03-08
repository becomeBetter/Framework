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
private:
	//�ͻ���
	QTcpSocket*						m_pClient;

	//���յ�������
	QByteArray						m_objRecvData;
private slots:
	//��Ӧ���ݵ���
	void slotForDataComing();
};

