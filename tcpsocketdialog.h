#ifndef TCPSOCKETDIALOG_H
#define TCPSOCKETDIALOG_H

#include <QDialog>

namespace Ui {
class TcpSocketDialog;
}

class TcpSocketDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TcpSocketDialog(QWidget *parent = 0);
    ~TcpSocketDialog();

private:
    Ui::TcpSocketDialog *ui;
};

#endif // TCPSOCKETDIALOG_H
