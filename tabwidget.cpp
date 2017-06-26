#include "tabwidget.h"
#include "framelayout.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
TabWidget::TabWidget(QWidget *parent)
    :QTabWidget(parent)
{
    //新建第一个页面的部件
    QVBoxLayout *mainVbox=new QVBoxLayout(this);
    mainVbox->setSpacing(2);
    FrameLayout *frameLayout=new FrameLayout;
    frameLayout->setFrameText(tr(u8"属性栏"));

    QWidget *widget = new QWidget(this);
    QLineEdit *lineEdit = new QLineEdit();
    QPushButton *pushButton = new QPushButton("Test");
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setSpacing(0);
    vLayout->addWidget(lineEdit);
    vLayout->addWidget(pushButton);
    frameLayout->setFrameLayout(vLayout);
    mainVbox->addLayout(frameLayout);
    mainVbox->addStretch();
    widget->setLayout(mainVbox);

    //新建第二个页面的部件
    QLabel *label = new QLabel("Hello Qt");

    //新建第三个页面的部件
    QPushButton *pushButton3 = new QPushButton("Click Me");

    //向Qthis中添加第一个页面
    QIcon icon1(":/icon/maya_2017.png");
    this->addTab(widget, icon1, "MayaStyle");

    //向Qthis中添加第二个页面
    QIcon icon2(":/icon/houdini_icon.png");
    this->addTab(label, icon2, "HoudiniStyle");

    //向Qthis中添加第三个页面
    QIcon icon3(":/icon/maya_2017.png");
    this->addTab(pushButton3, icon3, "VsStyle");

}
