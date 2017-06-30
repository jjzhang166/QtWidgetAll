#include "tcpserverdialog.h"
#include "ui_tcpserverdialog.h"

TcpServerDialog::TcpServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpServerDialog)
{
    ui->setupUi(this);
}

TcpServerDialog::~TcpServerDialog()
{
    delete ui;
}
