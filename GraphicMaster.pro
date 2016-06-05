#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T21:07:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicMaster
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myitem.cpp \
    myscene.cpp \
    myview.cpp

HEADERS  += mainwindow.h \
    myitem.h \
    myscene.h \
    myview.h

FORMS    += mainwindow.ui

RESOURCES += \
    icons.qrc
