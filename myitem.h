#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>
#include <QtGui>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QWidget>
#include <QVariant>
#include <QColor>


class MyItem : public QGraphicsItem
{
public:
    MyItem();
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) = 0;
    virtual void drawBoarder(QPainter *painter);
    void setColor(const QColor &brushColor) { fillColor = brushColor; }
    void setBoundingRect(QRectF newRect);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    QColor lineColor, fillColor;
private:
    QRectF rect;
    bool hovering = false;
    QPoint start, end;
    enum resizeDirection{EMPTY, LEFT, RIGHT, UP, DOWN, LEFTTOP, RIGHTTOP, LEFTBOTTOM, RIGHTBOTTOM};
    resizeDirection resizeDir = EMPTY;
};

class MyRectItem : public MyItem
{
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
};

class MyEllipseItem : public MyItem
{
public:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
};

class MyLineItem : public MyItem
{
public:
    void setLineStart(QPoint point);
    void setLineEnd(QPoint point);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget);
private:
    QPoint startPoint, endPoint;
};

#endif // MYITEM_H

