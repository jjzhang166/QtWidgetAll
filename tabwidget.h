#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
class TabWidget : public QTabWidget
{
public:
    TabWidget(QWidget *parent=0);
    virtual QSize sizeHint() const
    {
        return QSize(220,600);
    }
};

#endif // TABWIDGET_H
