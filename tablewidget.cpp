#include "tablewidget.h"
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QStringList>
#include <QSpinBox>
#include <QPushButton>
#include <QComboBox>
#include <QApplication>
#include <QPainter>
#include <QDateTime>
#include <QCheckBox>
#include <QLabel>
#include <QPixmap>
//=====================Delegate(委托)==================
ProgressBarDelegate::ProgressBarDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
    progressBarOption=new QStyleOptionProgressBar;
}

void ProgressBarDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

    if(index.column() == 4)
    {
        int progress = index.model ()->data(index, Qt::DisplayRole).toInt ();   //获取列表中对应的数据转换为整型
        //QStyleOptionProgressBar progressBarOption;
        progressBarOption->state = QStyle:: State_Enabled;
        progressBarOption->direction = QApplication:: layoutDirection ();
        progressBarOption->rect = option.rect;      //绘制的大小为表格的大小填充

        int nLeft=8;
        int nTop=8;
        int nWidth=option.rect.width()-2*nLeft;
        int nHeight=option.rect.height()-2*nTop;

        //重绘进度条矩形使其不是充满整个表格更美观
        progressBarOption->rect=QRect(option.rect.left()+nLeft,option.rect.top()+nTop,nWidth,nHeight);

        progressBarOption->fontMetrics = QApplication:: fontMetrics (); //holds used font
        progressBarOption->minimum = 0;
        progressBarOption->maximum = 100;
        progressBarOption->textAlignment = Qt:: AlignCenter;    //文本对齐方式
        progressBarOption->textVisible = true;      //文本可见
        progressBarOption->progress = progress;
        progressBarOption->text = QString("%1%").arg(progressBarOption->progress);
        QApplication:: style()->drawControl(QStyle::CE_ProgressBar, progressBarOption, painter);
    } else {
        return QStyledItemDelegate::paint (painter, option, index);
    }
}
//=============================TableWidget=======================
TableWidget::TableWidget(int row, int column, QWidget *parent)
    :QTableWidget(parent)
{
    //表头
    headList<<tr(u8"选择")<<tr(u8"数字")<<tr(u8"文件名与图标")<<tr(u8"大小")<<tr(u8"进度")<<tr(u8"图片")<<tr(u8"下拉选项")<<tr(u8"修改日期");
    this->setWindowTitle("tableWidget sample");
    this->setRowCount(row);     //设置行
    this->setColumnCount(column);  //设置列

    this->setSelectionMode(QAbstractItemView::SingleSelection);  //设置选择的模式为单选
    this->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择为整行
    this->setShowGrid(false);       //不显示格子线
    this->setHorizontalHeaderLabels(headList);      //表头标签需要先设置了列数才能正常显示
    this->horizontalHeader()->setStretchLastSection(true);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);       //设置表格不可编辑

    ProgressBarDelegate *barDelegate=new ProgressBarDelegate;
    this->setItemDelegate(barDelegate);

    //初始化行宽度
    this->setColumnWidth(0,30);
    this->setColumnWidth(1,50);
    this->setColumnWidth(2,150);
    this->setColumnWidth(3,60);
    this->setColumnWidth(4,120);
    this->setColumnWidth(5,100);
    this->setColumnWidth(6,100);

    //this->setHorizontalHeaderLabels(header);
    extName="mb";   //初始一下变量

    initData();     //填充初始数据
}
TableWidget::~TableWidget()
{

}

QIcon TableWidget::relIcon(const QString &extName)
{
    //表中的图标初始化
    QIcon mayaIcon,houdiniIcon;
    mayaIcon.addFile(":/ico/maya_2015.png",QSize(25,25));
    houdiniIcon.addFile(":/ico/houdini_icon.png",QSize(25,25));

    if(extName=="ma" || extName=="mb")
    {
        return mayaIcon;
    }
    return houdiniIcon;
}
//文件大小计算
QString TableWidget::calcSize(QFileInfo &fileInfo)
{
    QString fileSize="";
    if (fileInfo.size()>(1024*1024*1024))
        fileSize=QString::asprintf("%.2fGB",fileInfo.size()/(1024.0 * 1024.0 * 1024.0));
    else if (fileInfo.size()>(1024*1024))
        fileSize=QString::asprintf("%.2fMB",fileInfo.size()/(1024.0 * 1024.0));
    else if (fileInfo.size()>(1024))
        fileSize=QString::asprintf("%.2fKB",fileInfo.size()/(1024.0));
    else
        fileSize=QString::asprintf("%d bytes",int(fileInfo.size()));
    return fileSize;
}
//速度转换函数
QString TableWidget::convertSpeed(double speed)
{
    QString strUnit;
    if(speed<=0)
    {
        speed=0;
        strUnit="Bytes/S";
    }else if(speed<1024){
        strUnit="Bytes/S";
    }else if(speed<1024*1024){
        speed/=1024;
        strUnit="KB/S";
    }else if(speed<1024*1024*1024){
        speed/=(1024*1024);
        strUnit="MB/S";
    }else{
        speed /= (1024*1024*1024);
        strUnit="GB/S";
    }
    QString strSpeed=QString::number(speed,'f',2);
    return QString("%1 %2").arg(strSpeed).arg(strUnit);
}
void TableWidget::initData()
{
    //表中的图标初始化
    QIcon mayaIcon,houdiniIcon;
    mayaIcon.addFile(":/icon/maya_2017.png",QSize(25,25));
    houdiniIcon.addFile(":/icon/houdini_icon.png",QSize(25,25));

    int addRowCount=this->rowCount();  //初始化总行数
    int addColumnCount=headList.count();    //列数为取得表并没有的数量

    for(int row=0;row<addRowCount;++row)
    {
        for(int column=0;column<addColumnCount;++column)
        {
            if(column==0)
            {
                QTableWidgetItem *checkbox=new QTableWidgetItem;
                checkbox->setCheckState(Qt::Checked);       //设置初为checkbox状态
                this->setItem(row,column,checkbox);
            }else if(column==1){
                QSpinBox *spinBox=new QSpinBox;
                spinBox->setValue(row);
                this->setCellWidget(row,column,spinBox);       //在第二列创建QSpinBox
            }else if(column==2){
                QTableWidgetItem *Item3=new QTableWidgetItem((row%2)?mayaIcon:houdiniIcon,tr(u8"图标和文件名数据"));
                this->setItem(row,column,Item3);
            }else if(column==3){
                this->setItem(row,column,new QTableWidgetItem("280 MB"));
            }else if(column==4){
                this->setItem(row,column,new QTableWidgetItem("68"));
            }else if(column==8){
                QLabel *label=new QLabel;
                label->setPixmap(QPixmap(":/icon/folder.png"));
                this->setCellWidget(row,column,label);
            }else if(column==6){
                QComboBox *comboBox=new QComboBox;
                comboBox->addItem(mayaIcon,"maya");
                comboBox->addItem(houdiniIcon,"houdini");
                this->setCellWidget(row,column,comboBox);
            }else if(column==7){
                QDateTime systemTime=QDateTime::currentDateTime();
                QString strSystemTime=systemTime.toString("yyyy-MM-dd hh:mm:ss ddd");   //显示的时间格式
                this->setItem(row,column,new QTableWidgetItem(strSystemTime));
            }else{
                this->setItem(row,column,new QTableWidgetItem(tr(u8"文字显示")));
            }
        }
    }

}

