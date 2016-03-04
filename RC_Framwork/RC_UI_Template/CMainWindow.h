#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H
#include "IWidget.h"
#include <QMainWindow>
struct IModule;
class CMainWindow : public QMainWindow, public IWidget
{
    Q_OBJECT
public:
    explicit CMainWindow(QWidget *parent = 0);
    
    explicit CMainWindow(IModule* platform, QWidget *parent = 0);
public:
    //获取UI
    QWidget* getUI();
public:
    //开始
    void onStartup();
    
    //结束
    void onShutdown();
private:
    //平台
    IModule*                    m_pPlatform;


signals:

public slots:
};

#endif // CMAINWINDOW_H
