#ifndef FTPSETING_H
#define FTPSETING_H

#include <QDialog>

namespace Ui {
class FtpSeting;
}

class FtpSeting : public QDialog
{
    Q_OBJECT

public:
    explicit FtpSeting(QWidget *parent = 0);
    ~FtpSeting();

private:
    Ui::FtpSeting *ui;
};

#endif // FTPSETING_H
