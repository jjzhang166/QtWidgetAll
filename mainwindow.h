#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QHash>
#include <QMainWindow>
#include <QDockWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QHash<QString,QDockWidget *> hashDockWidget;
    QDockWidget *ClassDockWidget;
    QDockWidget *AttribDockWidget;
};

#endif // MAINWINDOW_H
