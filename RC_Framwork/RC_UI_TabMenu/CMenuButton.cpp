#include "CMenuButton.h"

CMenuButton::CMenuButton(const QString &id, const QString &text, const QString &icon, QWidget *parent) :
    QToolButton(parent),
    m_strId(id)
{
    setText(text);

    setIcon(QIcon(icon));
	
	setIconSize(QSize(128, 64));

    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

	setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Ignored);

	setCheckable(true);

	setMaximumWidth(128);
}

QString CMenuButton::id() const
{
    return m_strId;
}
