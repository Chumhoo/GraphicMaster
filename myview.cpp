#include "myview.h"
#include <QKeyEvent>

MyView::MyView(QWidget *parent) :
    QGraphicsView(parent)
{
}

void MyView::keyPressEvent(QKeyEvent *event)
{
   qDebug("*********MyView::keyPressEvent***************");
    QGraphicsView::keyPressEvent(event);
}

void MyView::mousePressEvent(QMouseEvent *event)
{
    qDebug("************MyView::mousePressEvent*****************");
    QGraphicsView::mousePressEvent(event);
}

void MyView::paintEvent(QPaintEvent *event)
{
    qDebug("************MyView::paintEvent*****************");
    QGraphicsView::paintEvent(event);
}

void MyView::mouseMoveEvent(QMouseEvent *event)
{
    //qDebug("************MyView::mouseMoveEvent*****************");
    QGraphicsView::mouseMoveEvent(event);
}

