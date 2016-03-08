#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include "IWidget.h"
#include "ITcpDataWatcher.h"
#include <QMainWindow>
struct IModule;
class CConfig;
class QTextBrowser;
class CMainWindow : public QMainWindow, public IWidget,public ITcpDataWatcher
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

	//数据到来通知
	//!data: 数据
	//!client:客户端指针
	void tcpDataComingNotify(QByteArray& data, void* client);
private:
    //平台
    IModule*                    m_pPlatform;

	//配置
	CConfig*					m_pConfig;

	//数据展示窗口
	QTextBrowser*				m_pBrowser;
signals:

public slots:
};

#endif // CMAINWINDOW_H
