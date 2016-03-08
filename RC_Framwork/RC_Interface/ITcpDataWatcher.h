#ifndef ITCPDATAWATCHER_H_
#define ITCPDATAWATCHER_H_
#define IID_TCP_DATA_WATCHER ("1D3D8E2E-5BE6-429F-BC48-9764E77319EE")

class QByteArray;

struct ITcpDataWatcher 
{
	//���ݵ���֪ͨ
	//!data: ����
	//!client:�ͻ���ָ��
	virtual void tcpDataComingNotify(QByteArray& data, void* client) = 0;
};
#endif//ITCPDATAWATCHER_H_