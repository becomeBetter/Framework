#include "CAppLauncher.h"
#include "CConfig.h"
#include <QApplication>
#include <QDir>
#include <QDebug>
int main(int argc, char *argv[])
{
	qDebug()<<QDir::currentPath();

    QApplication a(argc, argv);

    CConfig config;

    config.parse("Root");

    CAppLauncher launcher(&config);

    launcher.onStartup();

    bool bRet = a.exec();

    launcher.onShutdown();

    return bRet;
}
