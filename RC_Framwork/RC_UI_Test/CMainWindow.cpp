#include "CMainWindow.h"
#include <QWidget>
#include <QLabel>
#include <QToolButton>
CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_pPlatform(NULL)
{
}

CMainWindow::CMainWindow(const QString& key, IModule *platform, QWidget *parent):
    QMainWindow(parent),
    m_pPlatform(platform)
{
	QToolButton *pBtn = new QToolButton;

	pBtn->setIcon(QIcon("Config/tabmenuicon/"+key+".png"));

	pBtn->setIconSize(QSize(256,256));

	pBtn->setCheckable(false);

    setCentralWidget(pBtn);
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
