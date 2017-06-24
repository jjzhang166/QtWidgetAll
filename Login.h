#ifndef TOOLBAR_H
#define TOOLBAR_H

//#include <QLineEdit>
#include <QWidget>
#include <QHBoxLayout>
QT_BEGIN_NAMESPACE
class QLineEdit;
class QLabel;
class QPushButton;
class QHBoxLayout;
QT_END_NAMESPACE
class Login :public QHBoxLayout
{
    Q_OBJECT
private:

    QLabel *Namelabel;
    QLabel *passlabel;

    QLineEdit *NamelineEdit;
    QLineEdit *passlineEdit;
public:
    Login();
    ~Login();
    QPushButton *buttonlogin;
    QString getUserName();
    QString getPassword();
public slots:


};

#endif // TOOLBAR_H
