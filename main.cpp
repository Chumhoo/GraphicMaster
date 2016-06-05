#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QtGui>
#include "myitem.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime())); //设置随机数初值
    w.show();

    return a.exec();
}
