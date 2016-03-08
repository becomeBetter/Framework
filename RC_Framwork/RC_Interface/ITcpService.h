#ifndef ITCPSERVICE_H_
#define ITCPSERVICE_H_

#define IID_TCP_SERVICE ("7E6557A9-F087-4327-91C6-81D8B16A3E5F")

struct ITcpDataWatcher;

struct ITcpService
{
	//观察者注册
	virtual bool registry(ITcpDataWatcher* watcher) = 0;

	//观察者取消注册
	virtual bool unRegistry(ITcpDataWatcher* watcher) = 0;
};
#endif//ITCPSERVICE_H_