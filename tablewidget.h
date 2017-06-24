#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H
#include <QTableWidget>
#include <QList>
#include <QFileInfo>
#include <QItemDelegate>
class ProgressBarDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    ProgressBarDelegate(QObject *parent=0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
private:
    QStyleOptionProgressBar *progressBarOption;
};
class TableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TableWidget(int row, int column, QWidget *parent=0);
    ~TableWidget();
    void initData();    //初始化一下数据
    QString calcSize(QFileInfo &fileInfo);  //计算文件大小
    QIcon relIcon(const QString &extName);        //图标切换
    QString convertSpeed(double speed); //速度转换函数
private:
    QStringList headList;       //表头
    QList<QStringList> grid_data_list;  //数据源列表
    QString extName;
};

#endif // TABLEWIDGET_H
