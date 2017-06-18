#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H
#include <QTableWidget>
class TableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TableWidget(int row, int column, QWidget *parent=0);
    ~TableWidget();
private:
};

#endif // TABLEWIDGET_H
