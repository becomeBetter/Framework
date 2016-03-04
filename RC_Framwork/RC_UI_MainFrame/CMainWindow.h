#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include "IWidget.h"
#include "CConfig.h"
#include "CNoTitleBarDockWidget.h"
#include <QMainWindow>
#include <QVBoxLayout>
struct IModule;
class CMainWindow : public QMainWindow, public IWidget
{
    Q_OBJECT
public:
    explicit CMainWindow(IModule* platform, CConfig* config, QWidget *parent = 0);
public:
    //获取UI
    QWidget* getUI();
public:
    //开始
    void onStartup();
    
    //结束
    void onShutdown();
private:
	//创建主要框架
	void createMainFramework();

	//加载菜单
	void loadMenu(const QString& menutype);

	//加载tabmenu类型的菜单
	void loadTabMenu(const QString& menutype);

	//初始化界面显示,即默认显示第一个tab页
	void initializeDisplay();
private:
    //平台
    IModule*                    m_pPlatform;

	//配置
	CConfig*					m_pConfig;

	//主布局
	QVBoxLayout*				m_pMainLayout;

	//框架主界面容器
	CNoTitleBarDockWidget*		m_pMainFrameContainer;  
signals:

public slots:
	//响应Tab菜单点击事件
	void slotForTabMenuItemClicked(const QString& menuid);
};

#endif // CMAINWINDOW_H
