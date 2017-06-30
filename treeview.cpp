#include "treeview.h"

TreeView::TreeView(QWidget *parent)
    :QTreeView(parent)
{
    treeModel=new TreeModel;
    this->setModel(treeModel);
}
TreeView::~TreeView()
{
    treeModel->deleteLater();
}
