#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSize>
#include <QHash>
#include <QMainWindow>
#include <QDockWidget>
#include <QComboBox>
#include "ftpseting.h"
#include "Login.h"
namespace Ui {
class MainWindow;
}

class ItemDockWidget;
class AttribDockWidget;

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
    AttribDockWidget *attribDockWidget;
    QDockWidget *detailDockWidget;
    ItemDockWidget *itemDockWidget[3];

    FtpSeting *ftpseting;
};
class ItemDockWidget : public QDockWidget
{
public:
    virtual QSize sizeHint() const
    {
        return QSize(500,600);
    }
};
//重载QDockwidget类设置初始化大小
class AttribDockWidget : public QDockWidget
{
public:
    virtual QSize sizeHint() const
    {
        return QSize(200,600);

    }
};

#endif // MAINWINDOW_H
