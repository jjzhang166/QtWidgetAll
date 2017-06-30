#-------------------------------------------------
#
# Project created by QtCreator 2017-06-22T14:26:51
#
#-------------------------------------------------

QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtWidgetAll
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    mainwindow.cpp \
    framelayout.cpp \
    ftpseting.cpp \
    Login.cpp \
    qftp.cpp \
    qurlinfo.cpp \
    tableview.cpp \
    tablewidget.cpp \
    tabwidget.cpp \
    toolbox.cpp \
    treemodel.cpp \
    treeview.cpp \
    treewidget.cpp \
    tcpsocketdialog.cpp \
    tcpserverdialog.cpp

HEADERS  += mainwindow.h \
    ftpseting.h \
    tableview.h \
    tablewidget.h \
    treemodel.h \
    treeview.h \
    treewidget.h \
    framelayout.h \
    Login.h \
    toolbox.h \
    tabwidget.h \
    qftp.h \
    qurlinfo.h \
    tcpsocketdialog.h \
    tcpserverdialog.h

FORMS    += mainwindow.ui \
    ftpseting.ui \
    tcpsocketdialog.ui \
    tcpserverdialog.ui

RESOURCES += \
    qrc.qrc

DISTFILES += \
    readme.txt
