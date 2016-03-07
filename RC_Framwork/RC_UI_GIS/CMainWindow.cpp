#include "CMainWindow.h"
#include "CConfig.h"
#include <QWebView>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWebPage>
#include <QWebFrame>
CMainWindow::CMainWindow(IModule *platform, CConfig* config,  QWidget *parent):
    QMainWindow(parent),
    m_pPlatform(platform),
	m_pConfig(config)
{
    createMainFramework();
}
//获取UI
QWidget *CMainWindow::getUI()
{
    return static_cast<QWidget*>(this);
}

//开始事件
void CMainWindow::onStartup()
{

}

//结束事件
void CMainWindow::onShutdown()
{

}

void CMainWindow::createMainFramework()
{
	m_pView = new QWebView();

	m_pView->load(m_pConfig->getFileURL());

	QWidget *pCentralWidget = new QWidget;

	QVBoxLayout *pMainLayout = new QVBoxLayout(pCentralWidget);

	QPushButton* pTest = new QPushButton("Test");

	pMainLayout->addWidget(m_pView);

	pMainLayout->addWidget(pTest);

	setCentralWidget(pCentralWidget);

	connect(pTest, SIGNAL(clicked()), this, SLOT(slotForTestButtonClicked()));
}

void CMainWindow::slotForTestButtonClicked()
{
	QString strCode = "removeTrafficControl();";

	m_pView->page()->mainFrame()->evaluateJavaScript(strCode);
}