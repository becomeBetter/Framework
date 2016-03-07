#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include "IWidget.h"
#include <QMainWindow>
struct IModule;
class QWebView;
class CConfig;
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
	void createMainFramework();
private:
    //平台
    IModule*                    m_pPlatform;

	//配置
	CConfig*					m_pConfig;

	//GIS 视图
	QWebView*					m_pView;
signals:

public slots:
	//TODO: this function is for test, it should be removed later
	void slotForTestButtonClicked();
};

#endif // CMAINWINDOW_H
