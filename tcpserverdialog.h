#ifndef TCPSERVERDIALOG_H
#define TCPSERVERDIALOG_H

#include <QDialog>

namespace Ui {
class TcpServerDialog;
}

class TcpServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TcpServerDialog(QWidget *parent = 0);
    ~TcpServerDialog();

private:
    Ui::TcpServerDialog *ui;
};

#endif // TCPSERVERDIALOG_H
