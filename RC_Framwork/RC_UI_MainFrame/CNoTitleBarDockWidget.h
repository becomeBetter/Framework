#ifndef CNOTITLEBARDOCKWIDGET_H
#define CNOTITLEBARDOCKWIDGET_H

#include <QDockWidget>

class CNoTitleBarDockWidget : public QDockWidget
{
	Q_OBJECT

public:
	CNoTitleBarDockWidget(QWidget *parent = 0);
	~CNoTitleBarDockWidget();

private:
	
};

#endif // CNOTITLEBARDOCKWIDGET_H
