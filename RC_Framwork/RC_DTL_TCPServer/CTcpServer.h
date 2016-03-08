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
	//监听端口
	unsigned int				m_iPort;

	//客户端列表
	QVector<QTcpSocket*>		m_vecClients;
signals:
	//数据到来
	void signalDataComing(QByteArray data, void* client);

private slots:
	//响应新连接
	void slotForNewConnectionComing();

	//响应客户端的数据到来
	void slotForDataComing();

	//响应客户端断开请求
	void slotForDisconnect();
};

#endif // CTCPSERVER_H
