#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setStyle("Fusion");
    w.resize(QSize(1200,700));
    w.show();
    return a.exec();
}
