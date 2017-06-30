#include "mainwindow.h"
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
#include "Login.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //加载窗口类的创建
    ftpseting=new FtpSeting(this);
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
    QFtp *ftp=new QFtp;
    m_login=new Login;
    TabWidget *tabWidget=new TabWidget;
    ToolBox *toolBox=new ToolBox;
    TableWidget *tableWidget=new TableWidget(50,8);
    //dockWidget实例
    classDockWidget=new QDockWidget;;        //左边类窗口
    //classDockWidget->setFixedSize(220,600);
    attribDockWidget=new AttribDockWidget;       //右边属性窗口

    //初始化的一些函数
    setConnect();
    createMainTools();
    createLogin();

    QDockWidget *detailDockWidget=new QDockWidget;
    detailDockWidget->setWindowTitle("Details");
    detailDockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    //this->addDockWidget(Qt::BottomDockWidgetArea,detailDockWidget);

    const int dockWidgetCout=3;
    //ItemDockWidget *ItemDockWidget[dockWidgetCout];
    for(int i=0;i<dockWidgetCout;++i)
    {
        itemDockWidget[i]=new ItemDockWidget;
        itemDockWidget[i]->setWindowTitle(TabsName.at(i).toLocal8Bit().constData());
        itemDockWidget[i]->setAllowedAreas(Qt::AllDockWidgetAreas);
        //this->addDockWidget(Qt::RightDockWidgetArea,ItemDockWidget[i]);
        //if(i!=0)
         //  this->tabifyDockWidget(ItemDockWidget[i-1],ItemDockWidget[i]);
        hashDockWidget.insert(TabsName.at(i).toLocal8Bit().constData(),itemDockWidget[i]);

    }
    hashDockWidget.squeeze();   //重新排序一下

    hashDockWidget.value(TabsName.at(0))->setWidget(tableWidget);
    QTextEdit *textEdit=new QTextEdit;
    hashDockWidget.value(TabsName.at(1))->setWidget(textEdit);

    classDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    classDockWidget->setWindowTitle(tr("ClassWindow"));

    classDockWidget->setWidget(toolBox);
    classDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    attribDockWidget->setWidget(tabWidget);

    attribDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
    attribDockWidget->setWindowTitle("AttribWindow");
    attribDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);

    this->addDockWidget(Qt::LeftDockWidgetArea,classDockWidget);
    this->splitDockWidget(classDockWidget,hashDockWidget.value(TabsName.at(0)), Qt::Horizontal);

    this->splitDockWidget(classDockWidget,detailDockWidget,Qt::Vertical);
    this->splitDockWidget(hashDockWidget.value(TabsName.at(0)),attribDockWidget, Qt::Horizontal);   //从左到右分割dockWidget窗口
    this->splitDockWidget(hashDockWidget.value(TabsName.at(0)),hashDockWidget.value(TabsName.at(1)),Qt::Vertical);
    this->tabifyDockWidget(itemDockWidget[1],itemDockWidget[2]);       //tabs标签方式摆放dockwidget窗口
    itemDockWidget[1]->raise();         //提升dockwidget为顶部窗口槽

    this->setTabPosition(Qt::LeftDockWidgetArea,QTabWidget::North);        //第一个参数表示那里的dockwidgetArea窗口？第二个参数表示在那绘制

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setConnect()
{
    connect(ui->actionFtpSeting,SIGNAL(triggered()),ftpseting,SLOT(exec()));
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
