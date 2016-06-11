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

enum MOUSEMODE{DRAG, PENCIL, SELECT, RECTANGLE, ELLIPSE, LINE, ROUNDRECT, POLYGON, TEXT, SCALE};

class MyScene : public QGraphicsScene
{
public:
    MyScene();
    void changeMouseMode(MOUSEMODE newMouseMode);
    MOUSEMODE mouseMode = DRAG;
    void setBrush(const QBrush &newBrush) { brush = newBrush; }
    void setPen(const QPen &newPen) { pen = newPen; }
    void setTextFormat(const QFont newFont, const QColor newColor) {textColor = newColor; font = newFont;}
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
private:
    QBrush brush = QBrush(QColor(255, 255, 255));
    QPen pen = QPen(QColor(0, 0, 0));
    QColor textColor = QColor(0, 0, 0);
    QFont font;
    bool pressing = false;
    MyItem *fixedGraph = NULL;
    MyLineItem *line = NULL;
    MyPolygonItem *polygon = NULL;
    MyPencilItem *pencil = NULL;
    MyTextItem *textItem = NULL;
    QGraphicsRectItem *selectArea = NULL;
};

#endif // MYSCENE_H
