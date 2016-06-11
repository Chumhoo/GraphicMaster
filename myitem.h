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
#include <QMenu>


enum resizeDirection{EMPTY, LEFT, RIGHT, UP, DOWN, LEFTTOP, RIGHTTOP, LEFTBOTTOM, RIGHTBOTTOM};


class MyItem : public QGraphicsItem
{
public:
    MyItem(QBrush newBrush, QPen newPen);
    QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
    virtual void drawBoarder(QPainter *painter);
    void setBrush(const QBrush newBrush);
    void setPen(const QPen newPen);
    void setBoundingRect(QRectF newRect);

    resizeDirection resizeDir = EMPTY;
    virtual ~MyItem() {}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    QColor selectColor;
    QRectF rect;
    QBrush brush;
    QPen pen;

private:
    bool hovering = false;
};

class MyRectItem : public MyItem
{
public:
    MyRectItem(QBrush newBrush, QPen newPen) : MyItem(newBrush, newPen){}
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
private:
    ~MyRectItem(){}
};

class MyEllipseItem : public MyItem
{
public:
    MyEllipseItem(QBrush newBrush, QPen newPen) : MyItem(newBrush, newPen){}
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
private:
    ~MyEllipseItem(){}
};

class MyRoundRectItem : public MyItem
{
public:
    MyRoundRectItem(QBrush newBrush, QPen newPen) : MyItem(newBrush, newPen){}
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
private:
    ~MyRoundRectItem(){}
};

class MyPencilItem : public MyItem
{
public:
    MyPencilItem(QBrush newBrush, QPen newPen) : MyItem(newBrush, newPen){}
    QRectF boundingRect() const;
    void setStart(QPointF point);
    void addPoint(QPointF point);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
private:
    QPainterPath path;
    ~MyPencilItem(){}
};

class MyPolygonItem : public MyItem
{
public:
    MyPolygonItem(QBrush newBrush, QPen newPen) : MyItem(newBrush, newPen){}
    bool drawing = false;
    QRectF boundingRect() const;
    void addPoint(QPointF point);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
private:
    QPolygonF polygon;
    ~MyPolygonItem(){}
};

class MyLineItem : public MyItem
{
public:
    MyLineItem(QBrush newBrush, QPen newPen) : MyItem(newBrush, newPen){}
    void setLine(QPointF startP, QPointF endP);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget);
private:
    QPointF start, end;
    ~MyLineItem(){}
};

class MyTextItem : public QGraphicsTextItem
{
public:
    MyTextItem(QFont font, QColor textColor);
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void focusOutEvent(QFocusEvent *event);
private:
    ~MyTextItem(){}
};


#endif // MYITEM_H

