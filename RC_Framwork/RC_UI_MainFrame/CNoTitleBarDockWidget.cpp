#include "CNoTitleBarDockWidget.h"

CNoTitleBarDockWidget::CNoTitleBarDockWidget(QWidget *parent)
	: QDockWidget(parent)
{
	setFeatures(QDockWidget::NoDockWidgetFeatures);

	QWidget *pTitleBar = new QWidget;

	setTitleBarWidget(pTitleBar);

	pTitleBar->setVisible(false);
}

CNoTitleBarDockWidget::~CNoTitleBarDockWidget()
{

}
