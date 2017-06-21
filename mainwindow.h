#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSize>
#include <QHash>
#include <QMainWindow>
#include <QDockWidget>

#include "ftpseting.h"
namespace Ui {
class MainWindow;
}
class ClassDockWidget;
class AttribDockWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setConnect();
private:
    Ui::MainWindow *ui;

    QHash<QString,QDockWidget *> hashDockWidget;
    ClassDockWidget *classDockWidget;
    AttribDockWidget *attribDockWidget;

    FtpSeting *ftpseting;
};
class ClassDockWidget : public QDockWidget
{
public:
    virtual QSize sizeHint() const
    {
        return QSize(200,700);
    }
};
//重载QDockwidget类设置初始化大小
class AttribDockWidget : public QDockWidget
{
public:
    virtual QSize sizeHint() const
    {
        return QSize(200,700);
    }
};

#endif // MAINWINDOW_H
