#include "CMainWindow.h"
#include <QWidget>

CMainWindow::CMainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_pPlatform(NULL)
{
	
}

CMainWindow::CMainWindow(IModule *platform, QWidget *parent):
    QMainWindow(parent),
    m_pPlatform(platform)
{
    
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
