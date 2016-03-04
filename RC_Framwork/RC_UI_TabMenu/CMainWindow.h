#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include "IWidget.h"
#include "CConfig.h"
#include "ITabMenu.h"
#include <QFrame>
#include <QHBoxLayout>
struct IModule;
class CMainWindow : public QFrame, public IWidget, public ITabMenu
{
    Q_OBJECT
public:
    explicit CMainWindow(IModule* platform, CConfig* config, QWidget *parent = 0);
public:
    //获取UI
    QWidget* getUI();
public:
	//获取菜单ID
	QString getMenuID(unsigned int index) const;

	//使index处的菜单处于选中状态
	void setChecked(unsigned int index);
public:
    //开始
    void onStartup();
    
    //结束
    void onShutdown();
private:
    //创建主要界面
    void createMainFramework();
private:
    //平台
    IModule*                    m_pPlatform;

    //配置
    CConfig*                    m_pConfig;

    //主布局
    QHBoxLayout*                m_pMainLayout;
signals:
    //菜单按钮点击事件发起此信号
    void signalItemClicked(const QString& id);
public slots:
    //响应菜单点击事件
    void slotForItemClicked();
};

#endif // CMAINWINDOW_H
