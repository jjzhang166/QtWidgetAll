#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setStyle("Fusion");
    w.resize(QSize(1440,800));
    w.show();
    return a.exec();
}
