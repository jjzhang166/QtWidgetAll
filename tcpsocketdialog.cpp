#include "tcpsocketdialog.h"
#include "ui_tcpsocketdialog.h"

TcpSocketDialog::TcpSocketDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpSocketDialog)
{
    ui->setupUi(this);
    setWindowTitle("TcpS");
}

TcpSocketDialog::~TcpSocketDialog()
{
    delete ui;
}
