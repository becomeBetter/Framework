#ifndef CMENUBUTTON_H
#define CMENUBUTTON_H

#include <QToolButton>

class CMenuButton : public QToolButton
{
    Q_OBJECT
public:
    explicit CMenuButton(const QString& id, const QString& text, const QString& icon, QWidget *parent = 0);

public:
    QString id() const;
private:
    //id
    QString             m_strId;
signals:

public slots:

};

#endif // CMENUBUTTON_H
