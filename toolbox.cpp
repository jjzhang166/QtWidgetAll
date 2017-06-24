#include "toolbox.h"
#include "treewidget.h"
ToolBox::ToolBox(QWidget *parent)
    :QToolBox(parent)
{
    this->setObjectName("ToolBox");
    QWidget *widget=new QWidget();
    TreeWidget *treeWidget=new TreeWidget;
    this->addItem(treeWidget,tr("Qt GUI Class"));
    this->addItem(widget,tr("Qt Network Class"));
    this->addItem(widget,tr("Qt Date Class"));

}
