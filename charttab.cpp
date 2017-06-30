#include "charttab.h"

ChartTab::ChartTab(QWidget *parent) : QTabWidget(parent)
{
    QWidget *TabOne=new QWidget(this);
    QWidget *TabTwo=new QWidget(this);
    QWidget *TabThree=new QWidget(this);
    QWidget *TabFour=new QWidget(this);
    //向Qthis中添加第一个页面
    QIcon icon1(":/icon/houdini_icon.png");
    //向Qthis中添加第二个页面
    QIcon icon2(":/icon/maya_2017.png");
    this->addTab(TabOne,icon1,"Chart1");
    this->addTab(TabTwo,icon2,"Chart2");
    this->addTab(TabThree,icon1,"Chart3");
    this->addTab(TabFour,icon2,"Chart4");
    this->setTabPosition(QTabWidget::West); //设置Tab标签放在左边
    //this->setTabPosition(QTabWidget::East);     //设置Tab标签放在右边
    //this->setTabPosition(QTabWidget::South);    //设置Tab标签放在下边默认在上边
}
