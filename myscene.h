#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include <QtGui>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QWidget>
#include <QVariant>
#include <QColor>
#include <QDebug>

#include "myitem.h"

enum MOUSEMODE{DRAG, RECTANGLE, ELLIPSE, LINE};

class MyScene : public QGraphicsScene
{
public:
    MyScene();
    void changeMouseMode(MOUSEMODE newMouseMode);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    bool pressing = false;
    MOUSEMODE mouseMode = LINE;
    MyRectItem *rectangle;
    MyEllipseItem *ellipse;
    MyLineItem *line;
};

#endif // MYSCENE_H
