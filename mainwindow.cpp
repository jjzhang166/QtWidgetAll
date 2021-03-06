﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qdebug.h"
#include <QApplication>
#include <QTextEdit>
#include <QStringList>
#include <QVBoxLayout>
#include <QLabel>
#include <QFile>
#include "tablewidget.h"
#include "toolbox.h"
#include "tabwidget.h"
#include "qftp.h"
#include "datecomponent.h"
#include "charttab.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //加载窗口类的创建
    ftpseting=new FtpSeting(this);
    QStringList TabsName;
    TabsName<<"TableWidget"<<"TableView"<<"component"<<"Date"<<"Chart"<<"Plug";
    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);       //设置工具栏显示文字和图标
    //删除主窗口中的所有窗口，全部使用DockWidget类
    QWidget* p=this->takeCentralWidget();
    if(p)
        delete p;   //如takeCentralWidget存在就删除
    this->setWindowTitle(tr("QT 3k QWidget"));
    this->setDockNestingEnabled(true);  //使DockWidget窗可以放在mainWindow的中间


    //类的实例
    QFtp *ftp=new QFtp;
    m_login=new Login;
    ChartTab *charTab=new ChartTab(this);
    DateComponent *dateComponent=new DateComponent(this);
    tcpServerDialog=new TcpServerDialog(this);
    tcpSocketDialog=new TcpSocketDialog(this);
    TabWidget *tabWidget=new TabWidget;
    ToolBox *toolBox=new ToolBox;
    TableWidget *tableWidget=new TableWidget(20,8);

    //初始化的一些函数
    setConnect();
    createMainTools();
    createLogin();

    //dockWidget实例

    classDockWidget=new QDockWidget(this);        //左边类窗口
    detailDockWidget=new QDockWidget(this);
    //classDockWidget->setFixedSize(220,600);
    attribDockWidget=new QDockWidget;       //右边属性窗口
    codeDockWidget=new QDockWidget(this);
    const int dockWidgetCout=6;
    ItemDockWidget *itemDockWidget[dockWidgetCout];
    for(int i=0;i<dockWidgetCout;++i)
    {
        itemDockWidget[i]=new ItemDockWidget;
        itemDockWidget[i]->setWindowTitle(TabsName.at(i).toLocal8Bit().constData());
        itemDockWidget[i]->setAllowedAreas(Qt::AllDockWidgetAreas);
        itemDockWidget[i]->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
        //this->addDockWidget(Qt::RightDockWidgetArea,ItemDockWidget[i]);
        //if(i!=0)
         //  this->tabifyDockWidget(ItemDockWidget[i-1],ItemDockWidget[i]);
        hashDockWidget.insert(TabsName.at(i).toLocal8Bit().constData(),itemDockWidget[i]);      //将dockwidget放到容器中

    }
    //hashDockWidget.squeeze();   //重新排序一下

    itemDockWidget[0]->setWidget(tableWidget);
    QTextEdit *textEdit=new QTextEdit;
    //itemDockWidget[1]->setWidget(textEdit);

    //DockWidget属性设置
    classDockWidget->setWindowTitle(tr("ClassWindow"));
    classDockWidget->setWidget(toolBox);
    classDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    classDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    detailDockWidget->setWindowTitle("Details");
    //this->addDockWidget(Qt::BottomDockWidgetArea,detailDockWidget);
    detailDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);

    codeDockWidget->setWidget(textEdit);
    codeDockWidget->setWindowTitle("Code");
    codeDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);

    attribDockWidget->setWidget(tabWidget);
    attribDockWidget->setWindowTitle("AttribWindow");
    //attribDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    //attribDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    this->addDockWidget(Qt::LeftDockWidgetArea,classDockWidget);
    this->splitDockWidget(classDockWidget,itemDockWidget[0], Qt::Horizontal);
    this->splitDockWidget(itemDockWidget[0],attribDockWidget, Qt::Horizontal);   //从左到右分割dockWidget窗口
    this->splitDockWidget(classDockWidget,detailDockWidget,Qt::Vertical);
    this->splitDockWidget(itemDockWidget[0],codeDockWidget,Qt::Vertical);
    for(int i=0;i<dockWidgetCout;++i)
    {
        if(i<dockWidgetCout-1)
            this->tabifyDockWidget(itemDockWidget[i],itemDockWidget[i+1]);       //tabs标签方式摆放dockwidget窗口
    }
    itemDockWidget[0]->raise();         //提升dockwidget为顶部窗口槽
    this->setTabPosition(Qt::LeftDockWidgetArea,QTabWidget::North);        //第一个参数表示那里的dockwidgetArea窗口？第二个参数表示在那绘制
    //dockwidget数组面板设置
    itemDockWidget[3]->setWidget(dateComponent);
    itemDockWidget[4]->setWidget(charTab);

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setConnect()
{
    connect(ui->actionFtpSeting,SIGNAL(triggered()),ftpseting,SLOT(exec()));
    connect(ui->actionSocketServer,SIGNAL(triggered()),tcpServerDialog,SLOT(show()));
    connect(ui->actionSocketClinet,SIGNAL(triggered()),tcpSocketDialog,SLOT(show()));
}

void MainWindow::createMainTools()
{
    QWidget *mt_Widget=new QWidget;
    QHBoxLayout *mt_hbox=new QHBoxLayout;
    QLabel *mt_label=new QLabel(tr(u8"主题风格:"));
    mt_ComboBox=new QComboBox(mt_Widget);
    mt_ComboBox->addItem(QIcon(":/icon/maya_2017.png"),tr(u8"小清新风格"));
    mt_ComboBox->addItem(QIcon(":/icon/houdini_icon.png"),tr(u8"暗橙稳重"));
    mt_ComboBox->addItem(QIcon(":/icon/maya_2017.png"),tr(u8"黑色炫酷"));
    mt_ComboBox->addItem(QIcon(":/icon/houdini_icon.png"),tr(u8"白色靓丽"));
    mt_ComboBox->addItem(QIcon(":/icon/maya_2017.png"),tr(u8"QDarkStyleSheet"));
    mt_hbox->addWidget(mt_label);
    mt_hbox->addWidget(mt_ComboBox);
    mt_Widget->setLayout(mt_hbox);
    ui->mainToolBar->addWidget(mt_Widget);
    ui->mainToolBar->setObjectName("MainTools");

    connect(mt_ComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(currentStyle(int)));
}

void MainWindow::createLogin()
{
    QWidget *LoginWidget=new QWidget;
    LoginWidget->setLayout(m_login);

    ui->toolBar->addWidget(LoginWidget);
    ui->toolBar->setObjectName(tr("login"));
    //connect(mlogin->buttonlogin,SIGNAL(clicked(bool)),table_view,SLOT(connectserver(QString,QString)));
}

void MainWindow::currentStyle(const int &index)
{
    qDebug()<<index;
    if(index>0)
    {
        QFile qssFile(QString(":/theme/theme%1.qss").arg(index));
        qssFile.open(QFile::ReadOnly);
        qApp->setStyleSheet(qssFile.readAll());
        qssFile.close();
    }else{
        QFile qssFile(":/theme/default.qss");
        qssFile.open(QFile::ReadOnly);
        qApp->setStyleSheet(qssFile.readAll());
        qssFile.close();
    }
}
