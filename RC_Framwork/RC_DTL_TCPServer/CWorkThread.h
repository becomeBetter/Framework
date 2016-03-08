#ifndef CWORKTHREAD_H
#define CWORKTHREAD_H
#include "ITcpService.h"
#include <QVector>
#include <QThread>
class CConfig;
struct ITcpDataWatcher;
class CWorkThread : public QThread,public ITcpService
{
	Q_OBJECT

public:
	CWorkThread(CConfig* config, QObject *parent = 0);
	~CWorkThread();
public:
	//�۲���ע��
	bool registry(ITcpDataWatcher* watcher);

	//�۲���ȡ��ע��
	bool unRegistry(ITcpDataWatcher* watcher);
protected:
	void run();
private:
	//����
	CConfig*							m_pConfig;

	//�۲����б�
	QVector<ITcpDataWatcher*>			m_vecWatchers;
private slots:
	//��Ӧ���ݵ���
	void slotForDataComing(QByteArray data, void* client);
};

#endif // CWORKTHREAD_H
