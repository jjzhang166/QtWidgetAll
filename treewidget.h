#ifndef TREEWIDGET_H
#define TREEWIDGET_H
#include <QTreeWidget>

class TreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    TreeWidget(QWidget *parent=0);
    void initQTreeWidget();     //初始化
};

#endif // TREEWIDGET_H
