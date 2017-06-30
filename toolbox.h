#ifndef TOOLBOX_H
#define TOOLBOX_H

#include <QToolBox>
class ToolBox : public QToolBox
{
public:
    ToolBox(QWidget *parent=0);
    virtual QSize sizeHint() const
    {
        return QSize(150,600);
    }
};

#endif // TOOLBOX_H
