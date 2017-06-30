#include "toolbox.h"
#include "treewidget.h"
#include "treeview.h"

ToolBox::ToolBox(QWidget *parent)
    :QToolBox(parent)
{
    //类的实列
    QWidget *widget=new QWidget();
    TreeWidget *treeWidget=new TreeWidget;
    TreeView *treeView=new TreeView(this);
    //初始设置
    this->setObjectName("ToolBox");
    this->addItem(treeView,tr("Qt"));
    this->addItem(treeWidget,tr("C++"));
    this->addItem(widget,tr("Qt Date Class"));   
}
