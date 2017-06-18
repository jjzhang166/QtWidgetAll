#include "tablewidget.h"
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QStringList>
TableWidget::TableWidget(int row, int column, QWidget *parent)
    :QTableWidget(parent)
{
    QStringList headList;
    headList<<"选项"<<"序号"<<"文件名与图标"<<"大小"<<"进度"<<"图片"<<"下拉选项"<<"修改日期";

    //this->horizontalHeader()->setVisible(true);
    this->setWindowTitle("tableWidget sample");
    this->setRowCount(row);     //设置行
    this->setColumnCount(column);  //设置列

    this->setSelectionMode(QAbstractItemView::SingleSelection);  //设置选择的模式为单选
    this->setSelectionBehavior(QAbstractItemView::SelectRows);  //设置选择为整行
    this->setShowGrid(false);       //不显示格子线
    this->setHorizontalHeaderLabels(headList);      //表头标签需要先设置了列数才能正常显示
    this->horizontalHeader()->setStretchLastSection(true);

    //this->setHorizontalHeaderLabels(header);
    this->setItem(0,0,new QTableWidgetItem("Jan"));
    this->setItem(1,0,new QTableWidgetItem("Feb"));
    this->setItem(2,0,new QTableWidgetItem("Mar"));
}
TableWidget::~TableWidget()
{

}
