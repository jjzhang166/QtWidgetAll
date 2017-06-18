#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QTextEdit>
#include <QStringList>
#include "tablewidget.h"
#include "treewidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList TabsName;
    TabsName<<"sample"<<"code"<<"description";
    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);       //设置工具栏显示文字和图标
    //删除主窗口中的所有窗口，全部使用DockWidget类
    QWidget* p=this->takeCentralWidget();
    if(p)
        delete p;   //如takeCentralWidget存在就删除
    this->setWindowTitle(tr("QT 3k QWidget"));
    this->setDockNestingEnabled(true);  //使DockWidget窗可以放在mainWindow的中间

    //类的实例
    TableWidget *tableWidget=new TableWidget(5,8);
    TreeWidget *treeWidget=new TreeWidget;
    //dockWidget实例
    ClassDockWidget=new QDockWidget;        //左边类窗口
    ClassDockWidget->setFixedSize(250,600);
    AttribDockWidget=new QDockWidget;       //右边属性窗口

    QDockWidget *bottomDockWidget=new QDockWidget;
    bottomDockWidget->setWindowTitle("TopBottomDock");
    bottomDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    //this->addDockWidget(Qt::BottomDockWidgetArea,bottomDockWidget);

    const int dockWidgetCout=3;
    QDockWidget *ItemDockWidget[dockWidgetCout];
    for(int i=0;i<dockWidgetCout;++i)
    {
        ItemDockWidget[i]=new QDockWidget;
        ItemDockWidget[i]->setWindowTitle(TabsName.at(i).toLocal8Bit().constData());
        ItemDockWidget[i]->setAllowedAreas(Qt::AllDockWidgetAreas);
        //this->addDockWidget(Qt::RightDockWidgetArea,ItemDockWidget[i]);
        //if(i!=0)
         //  this->tabifyDockWidget(ItemDockWidget[i-1],ItemDockWidget[i]);
        hashDockWidget.insert(TabsName.at(i).toLocal8Bit().constData(),ItemDockWidget[i]);

    }
    //hashDockWidget.squeeze();   //重新排序一下
    hashDockWidget.value(TabsName.at(0))->setWidget(tableWidget);
    QTextEdit *textEdit=new QTextEdit;
    hashDockWidget.value(TabsName.at(1))->setWidget(textEdit);

    ClassDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    ClassDockWidget->setWindowTitle(tr("ClassWindow"));
    ClassDockWidget->setWidget(treeWidget);
    ClassDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    AttribDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    AttribDockWidget->setWindowTitle("AttribWindow");
    AttribDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    this->addDockWidget(Qt::LeftDockWidgetArea,ClassDockWidget);
    this->splitDockWidget(ClassDockWidget,hashDockWidget.value(TabsName.at(0)), Qt::Horizontal);
    this->splitDockWidget(hashDockWidget.value(TabsName.at(0)),AttribDockWidget, Qt::Horizontal);   //从左到右分割dockWidget窗口
    for(int i=0;i<dockWidgetCout;++i)
    {
        if(i!=0)
           this->tabifyDockWidget(ItemDockWidget[i-1],ItemDockWidget[i]);       //tabs标签方式摆放dockwidget窗口
    }
    this->setTabPosition(Qt::LeftDockWidgetArea,QTabWidget::North);        //第一个参数表示那里的dockwidgetArea窗口？第二个参数表示在那绘制

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
