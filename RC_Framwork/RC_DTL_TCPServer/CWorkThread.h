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
	//观察者注册
	bool registry(ITcpDataWatcher* watcher);

	//观察者取消注册
	bool unRegistry(ITcpDataWatcher* watcher);
protected:
	void run();
private:
	//配置
	CConfig*							m_pConfig;

	//观察者列表
	QVector<ITcpDataWatcher*>			m_vecWatchers;
private slots:
	//响应数据到来
	void slotForDataComing(QByteArray data, void* client);
};

#endif // CWORKTHREAD_H
