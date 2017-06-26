#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSize>
#include <QHash>
#include <QMainWindow>
#include <QDockWidget>
#include <QtGui>
#include <QComboBox>
#include "Login.h"
#include "ftpseting.h"
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
    ClassDockWidget *classDockWidget;
    QDockWidget *attribDockWidget;
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
class ClassDockWidget : public QDockWidget
{
public:
    virtual QSize sizeHint() const
    {
        return QSize(150,600);
    }
};

#endif // MAINWINDOW_H
