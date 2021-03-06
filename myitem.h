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
                  QWidget *widget);
    virtual void drawBoarder(QPainter *painter);
    void setColor(const QColor &brushColor) { fillColor = brushColor; }

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    QColor lineColor, fillColor;
private:
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

#endif // MYITEM_H

