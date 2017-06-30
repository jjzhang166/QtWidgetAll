#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSize>
#include <QHash>
#include <QMainWindow>
#include <QDockWidget>
#include <QComboBox>
#include "ftpseting.h"
#include "Login.h"
#include "tcpserverdialog.h"
#include "tcpsocketdialog.h"

namespace Ui {
class MainWindow;
}

class ItemDockWidget;
class ClassDockWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setConnect();
    void createMainTools();
    void createLogin();
private slots:
    void currentStyle(const int &index);
private:
    Ui::MainWindow *ui;
    Login *m_login;

    QComboBox *mt_ComboBox;

    QHash<QString,QDockWidget *> hashDockWidget;
    QDockWidget *classDockWidget;
    QDockWidget *attribDockWidget;
    QDockWidget *detailDockWidget;
    QDockWidget *codeDockWidget;

    FtpSeting *ftpseting;
    TcpServerDialog *tcpServerDialog;
    TcpSocketDialog *tcpSocketDialog;
};
class ItemDockWidget : public QDockWidget
{
public:
    virtual QSize sizeHint() const
    {
        return QSize(450,600);
    }
};
#endif // MAINWINDOW_H
