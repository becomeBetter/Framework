#include "CMainWindow.h"
#include "CMenuButton.h"
#include <QWidget>
#include <QButtonGroup>
#include <QVariant>
CMainWindow::CMainWindow(IModule *platform, CConfig *config, QWidget *parent):
    QFrame(parent),
    m_pPlatform(platform),
    m_pConfig(config)
{
    createMainFramework();
}
//获取UI
QWidget *CMainWindow::getUI()
{
    return static_cast<QWidget*>(this);
}

//获取菜单ID
QString CMainWindow::getMenuID(unsigned int index) const
{
	if(index >= m_pMainLayout->count())
	{
		return "";
	}

	CMenuButton* pMenuBtn = dynamic_cast<CMenuButton*>(m_pMainLayout->itemAt(index)->widget());

	if(NULL == pMenuBtn)
	{
		return "";
	}

	return pMenuBtn->id();
}

//使index处的菜单处于选中状态
void CMainWindow::setChecked(unsigned int index)
{
	if(index >= m_pMainLayout->count())
	{
		return ;
	}

	CMenuButton* pMenuBtn = dynamic_cast<CMenuButton*>(m_pMainLayout->itemAt(index)->widget());

	if(NULL == pMenuBtn)
	{
		return ;
	}

	pMenuBtn->setChecked(true);
}
//开始事件
void CMainWindow::onStartup()
{

}

//结束事件
void CMainWindow::onShutdown()
{

}
//创建主要界面
void CMainWindow::createMainFramework()
{
    if(NULL == m_pConfig)
    {
        return;
    }

    m_pMainLayout = new QHBoxLayout(this);

	QButtonGroup* pBtnGroup = new QButtonGroup(this);

    QVector<CMenuItem>& menuItems = m_pConfig->getMenuItems();

    QVector<CMenuItem>::iterator iter = menuItems.begin();

    for(iter; iter != menuItems.end(); ++iter)
    {
        CMenuButton *pMenuBtn = new CMenuButton(iter->strId, iter->strText, iter->strIcon);

		m_pMainLayout->addWidget(pMenuBtn);

		pBtnGroup->addButton(pMenuBtn);

        connect(pMenuBtn, SIGNAL(clicked()), this, SLOT(slotForItemClicked()));
    }

	pBtnGroup->setExclusive(true);

	m_pMainLayout->setMargin(0);

	m_pMainLayout->setSpacing(0);

	m_pMainLayout->addStretch(0);

	setProperty("TabMenu", true);
}
//响应菜单点击事件
void CMainWindow::slotForItemClicked()
{
    CMenuButton* pMenuBtn = static_cast<CMenuButton*>(sender());

    emit signalItemClicked(pMenuBtn->id());
}
