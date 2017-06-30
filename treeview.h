#ifndef TREEVIEW_H
#define TREEVIEW_H
#include <QTreeView>
#include "treemodel.h"
class TreeView : public QTreeView
{
public:
    TreeView(QWidget *parent=0);
    ~TreeView();
private:
    TreeModel *treeModel;
};

#endif // TREEVIEW_H
