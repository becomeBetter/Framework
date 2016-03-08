#include "CMainWindow.h"
#include "IInterfaceHandler.h"
#include "CConfig.h"
#include "ITcpService.h"
#include <QWidget>
#include <QTextBrowser>
CMainWindow::CMainWindow(IModule *platform, CConfig* config, QWidget *parent):
    QMainWindow(parent),
    m_pPlatform(platform),
	m_pConfig(config)
{
    QTextBrowser* pBrowser = new QTextBrowser;

	setCentralWidget(pBrowser);

	m_pBrowser = pBrowser;
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

	bool bRet = Framework::getInterface<ITcpService>(m_pPlatform, "tcpserver", IID_TCP_SERVICE, &pService);

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