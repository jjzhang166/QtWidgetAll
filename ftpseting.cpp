#include "ftpseting.h"
#include "ui_ftpseting.h"

FtpSeting::FtpSeting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FtpSeting)
{
    ui->setupUi(this);
    this->setWindowTitle("FtpSetin Window");
}

FtpSeting::~FtpSeting()
{
    delete ui;
}
