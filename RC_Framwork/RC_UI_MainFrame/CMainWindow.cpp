#include "CMainWindow.h"
#include "IInterfaceHandler.h"
#include "ITabMenu.h"
#include <QWidget>

CMainWindow::CMainWindow(IModule *platform, CConfig* config, QWidget *parent):
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
    //加载菜单
	loadMenu(m_pConfig->getMenuType());

	initializeDisplay();
}

//结束事件
void CMainWindow::onShutdown()
{

}
//创建主框架
void CMainWindow::createMainFramework()
{
	QWidget* pCentralWidget = new QWidget;

	m_pMainLayout = new QVBoxLayout(pCentralWidget);

	m_pMainLayout->setMargin(0);

	m_pMainFrameContainer = new CNoTitleBarDockWidget;

	m_pMainLayout->addWidget(m_pMainFrameContainer, 90);

	setCentralWidget(pCentralWidget);
}

//加载菜单
void CMainWindow::loadMenu(const QString& menutype)
{
	if(menutype == "TabMenu")
	{
		loadTabMenu(menutype);
	}
}

//加载tabmenu类型的菜单
void CMainWindow::loadTabMenu(const QString& menutype)
{
	//获取菜单
    IWidget* pMenuWidget = NULL;

	bool bRet = Framework::getInterface<IWidget>(m_pPlatform, menutype.toStdString(), IID_WIDGET, &pMenuWidget);

	if(false == bRet)
	{
		return;
	}

	m_pMainLayout->insertWidget(0, pMenuWidget->getUI(), 15);

	connect(pMenuWidget->getUI(), SIGNAL(signalItemClicked(QString)), this, SLOT(slotForTabMenuItemClicked(QString)));

}

//初始化界面显示,即默认显示第一个tab页
void CMainWindow::initializeDisplay()
{
	//获取菜单
    ITabMenu* pMenu = NULL;

	bool bRet = Framework::getInterface<ITabMenu>(m_pPlatform, m_pConfig->getMenuType().toStdString(), IID_TAB_MENU, &pMenu);

	if(false == bRet)
	{
		return;
	}

	QString firstMenuId = pMenu->getMenuID(0);

	if(firstMenuId.isEmpty())
	{
		return;
	}

	slotForTabMenuItemClicked(firstMenuId);

	pMenu->setChecked(0);
}

//响应Tab菜单点击事件
void CMainWindow::slotForTabMenuItemClicked(const QString& menuid)
{
	const QMap<QString, QString>& pageSwitchInfo = m_pConfig->getPageSwitchEventInfo();

	QMap<QString, QString>::const_iterator iter = pageSwitchInfo.find(menuid);

	if(iter == pageSwitchInfo.end())
	{
		return;
	}

	IWidget* pPage = NULL;

	bool bRet = Framework::getInterface<IWidget>(m_pPlatform, iter.value().toStdString(), IID_WIDGET, &pPage);

	if(false == bRet)
	{
		return;
	}

	m_pMainFrameContainer->setWidget(pPage->getUI());
}