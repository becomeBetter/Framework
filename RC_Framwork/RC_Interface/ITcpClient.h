#ifndef ITCPCLIENT_H_
#define ITCPCLIENT_H_
#define IID_TCP_CLIENT ("DCF398E5-B074-45D9-AC22-503401957032")

struct ITcpClient
{
	//����
	//!ip:Զ��ip��ַ
	//!port:Զ�˶˿�
	virtual bool connect(char* ip, unsigned int port) = 0;

	//�Ͽ�����
	virtual bool disconnect() = 0;

	//��������
	//!data:���͵�����
	//!length:���ݳ���
	virtual int sendData(char* data, unsigned int length) = 0;

	//��ȡ����
	//!buffer:��ȡ���ݻ�����
	//!size:��������С
	virtual int readData(char* buffer, unsigned int size) = 0;
};
#endif