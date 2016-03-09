#include "CMainWindow.h"
#include "CConfig.h"
#include "ITcpService.h"
#include "IInterfaceHandler.h"
#include "ITcpClient.h"
#include <QWidget>
#include <QTextBrowser>
#include <QPushButton>
#include <QVBoxLayout>
CMainWindow::CMainWindow(IModule *platform, CConfig* config, QWidget *parent):
    QMainWindow(parent),
    m_pPlatform(platform),
	m_pConfig(config)
{
	QWidget* pCentral = new QWidget;

	QVBoxLayout* pMainLayout = new QVBoxLayout(pCentral);

	QTextBrowser* pBrowser = new QTextBrowser;

	m_pBrowser = pBrowser;

	pMainLayout->addWidget(pBrowser);

	QPushButton* pConnect = new QPushButton("连接");

	QPushButton* pDisConnect = new QPushButton("断开连接");

	pMainLayout->addWidget(pConnect);

	pMainLayout->addWidget(pDisConnect);

	setCentralWidget(pCentral);

	connect(pConnect, SIGNAL(clicked()), this, SLOT(slotForConnectBtnClicked()));

	connect(pDisConnect, SIGNAL(clicked()), this, SLOT(slotForDisConnectBtnClicked()));
}
//获取UI
QWidget *CMainWindow::getUI()
{
    return static_cast<QWidget*>(this);
}
//开始事件
void CMainWindow::onStartup()
{
	ITcpService* pService = NULL; 

	bool bRet = Framework::getInterface<ITcpService>(m_pPlatform, "tcpclient", IID_TCP_SERVICE, &pService);

	if (bRet)
	{
		pService->registry(this);
	}
}

//结束事件
void CMainWindow::onShutdown()
{

}

//数据到来通知
//!data: 数据
//!client:客户端指针
void CMainWindow::tcpDataComingNotify(QByteArray& data, void* client)
{
	m_pBrowser->append(data.data());
}

void CMainWindow::slotForConnectBtnClicked()
{
	ITcpClient* pClient = NULL; 

	bool bRet = Framework::getInterface<ITcpClient>(m_pPlatform, "tcpclient", IID_TCP_CLIENT, &pClient);

	if (bRet)
	{
		bool bCon = pClient->connect("127.0.0.1", 7777);
	}
}

void CMainWindow::slotForDisConnectBtnClicked()
{
	ITcpClient* pClient = NULL; 

	bool bRet = Framework::getInterface<ITcpClient>(m_pPlatform, "tcpclient", IID_TCP_CLIENT, &pClient);

	if (bRet)
	{
		pClient->disconnect();
	}
}