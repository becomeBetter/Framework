#include "CMainWindow.h"
#include "CConfig.h"
#include <QWidget>

CMainWindow::CMainWindow(IModule *platform, CConfig* config, QWidget *parent):
    QMainWindow(parent),
    m_pPlatform(platform),
	m_pConfig(config)
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
