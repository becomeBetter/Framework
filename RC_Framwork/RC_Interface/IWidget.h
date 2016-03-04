#ifndef IWIDGET_H
#define IWIDGET_H
#define IID_WIDGET ("C363A725-6813-4A49-B80F-B95D8C395C16")

class QWidget;

struct IWidget
{
    //获取UI
    virtual QWidget* getUI() = 0;
};

#endif // IWIDGET_H
