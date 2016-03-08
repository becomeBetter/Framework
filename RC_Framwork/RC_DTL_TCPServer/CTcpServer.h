#ifndef CTCPSERVER_H
#define CTCPSERVER_H

#include <QTcpServer>
#include <QVector>
#include <QTcpSocket>
class CTcpServer : public QTcpServer
{
	Q_OBJECT

public:
	CTcpServer(QObject *parent, unsigned int port = 8888);

	~CTcpServer();
public:
	bool initialize();

	void unInitialize();
private:
	//�����˿�
	unsigned int				m_iPort;

	//�ͻ����б�
	QVector<QTcpSocket*>		m_vecClients;
signals:
	//���ݵ���
	void signalDataComing(QByteArray data, void* client);

private slots:
	//��Ӧ������
	void slotForNewConnectionComing();

	//��Ӧ�ͻ��˵����ݵ���
	void slotForDataComing();

	//��Ӧ�ͻ��˶Ͽ�����
	void slotForDisconnect();
};

#endif // CTCPSERVER_H
