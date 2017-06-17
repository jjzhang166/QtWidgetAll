#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QTextEdit>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);       //设置工具栏显示文字和图标
    //删除主窗口中的所有窗口，全部使用DockWidget类
    QWidget* p=this->takeCentralWidget();
    if(p)
        delete p;   //如takeCentralWidget存在就删除
    this->setWindowTitle(tr("QT 3k QWidget"));
    this->setDockNestingEnabled(true);  //使DockWidget窗可以放在mainWindow的中间

    CalssDockWidget=new QDockWidget;
    QDockWidget *bottomDockWidget=new QDockWidget;
    bottomDockWidget->setWindowTitle("TopBottomDock");
    bottomDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    //this->addDockWidget(Qt::BottomDockWidgetArea,bottomDockWidget);
    QTextEdit *textEdit=new QTextEdit;
    const int dockWidgetCout=8;
    QDockWidget *ItemDockWidget[dockWidgetCout];
    for(int i=0;i<dockWidgetCout;++i)
    {
        ItemDockWidget[i]=new QDockWidget;
        ItemDockWidget[i]->setWindowTitle(QString("TableDock%1").arg(i+1));
        ItemDockWidget[i]->setAllowedAreas(Qt::AllDockWidgetAreas);
        this->addDockWidget(Qt::RightDockWidgetArea,ItemDockWidget[i]);
        if(i!=0)
            this->tabifyDockWidget(ItemDockWidget[i-1],ItemDockWidget[i]);       //tabs标签方式摆放dockwidget窗口
       // hashDockWidget.insert(QString("TableItemDockWidget%1").arg(i),ItemDockWidget[i]);

    }


    CalssDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    CalssDockWidget->setWindowTitle(tr("Class"));
    CalssDockWidget->setWidget(textEdit);

    //TableItem_DockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    //TableItem_DockWidget->setWindowTitle(tr("TableItem"));

    this->addDockWidget(Qt::LeftDockWidgetArea,CalssDockWidget);


    //this->splitDockWidget(LeftCalss_DockWidget, LeftItem_DockWidget, Qt::Vertical);   //分割dockWidget窗口
    this->setTabPosition(Qt::RightDockWidgetArea,QTabWidget::North);        //第一个参数表示那里的dockwidgetArea窗口？第二个参数表示在那绘制

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
