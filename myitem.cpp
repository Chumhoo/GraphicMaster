#include "myitem.h"
#include <QVariant>

MyItem::MyItem()
{
    clearFocus();
    setAcceptDrops(true);  //设置接收拖放!!!
    lineColor = QColor(Qt::lightGray);
    fillColor = QColor(255, 255, 255, 200);

    //setFlag(QGraphicsItem::ItemIsSelectable);  //添加本性质则可同时选择多项
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);
}

QRectF MyItem::boundingRect() const
{
    return QRectF(rect.x()-2, rect.y()-2, rect.width()+4, rect.height()+4).normalized();
}

void MyItem::setBoundingRect(QRectF newRect)
{
    rect = newRect;
    //通知场景scene即将发生的变化，这样场景可以刷新item的位置下标。否则，场景将不会察觉到item的变化，结果也未知
    prepareGeometryChange();
    update(boundingRect());
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    painter->setPen(lineColor);
    painter->setBrush(fillColor);
    drawBoarder(painter);
}

void MyItem::drawBoarder(QPainter *painter)
{
    if(hasFocus()) {
        //        QPixmap pix;
        //        pix.load(":/icons/boarder.png");
        //        painter->drawPixmap(boundingRect().left(), boundingRect().top(), boundingRect().width(), boundingRect().height(), pix);
        painter->setPen(QPen(QColor(255,0,0), 1, Qt::DashLine));
        painter->setBrush(QColor(0, 0, 255, 10));
        painter->drawRect(boundingRect().x(), boundingRect().y(), boundingRect().width(), boundingRect().height());

        painter->setPen(QPen(QColor(0,0,0), 1, Qt::SolidLine));
        painter->setBrush(QBrush(Qt::black));
        painter->drawRect(boundingRect().left(), boundingRect().top(), 4, 4);
        painter->drawRect(boundingRect().right() - 4, boundingRect().top(), 4, 4);
        painter->drawRect(boundingRect().left(), boundingRect().bottom() - 4, 4, 4);
        painter->drawRect(boundingRect().right() - 4, boundingRect().bottom() - 4, 4, 4);
        painter->drawRect(boundingRect().left(), (boundingRect().top() + boundingRect().bottom())/2 - 2, 4, 4);
        painter->drawRect(boundingRect().right() - 4, (boundingRect().top() + boundingRect().bottom())/2 - 2, 4, 4);
        painter->drawRect((boundingRect().left() + boundingRect().right())/2 - 2, boundingRect().top(),  4, 4);
        painter->drawRect((boundingRect().left() + boundingRect().right())/2 - 2, boundingRect().bottom() - 4, 4, 4);
        painter->setBrush(QBrush(Qt::transparent));
    }
    else {
        painter->setPen(QPen(QColor(100,100,100), 1, Qt::SolidLine));
    }
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event->type();
    setFocus();
    // QGraphicsItem::mousePressEvent(event);
}


void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << event->scenePos().x() << event->scenePos().y() << boundingRect().x() << boundingRect().y();
    QGraphicsItem::mouseMoveEvent(event);

    if (resizeDir == EMPTY)
    {
        setFlag(ItemIsMovable, true);
    }
    else if (resizeDir == LEFT)
    {
        setFlag(ItemIsMovable, false);
        QRectF newRect;
        newRect = rect;
        newRect = newRect.normalized();

        if (event->scenePos().x() < this->x() + newRect.right()) newRect.setLeft(event->scenePos().x() - this->x());
        else resizeDir = RIGHT;
        setBoundingRect(newRect);
    }
    else if (resizeDir == RIGHT)
    {
        setFlag(ItemIsMovable, false);
        QRectF newRect;
        newRect = rect;
        newRect = newRect.normalized();

        if (event->scenePos().x() > this->x() + newRect.left()) newRect.setRight(event->scenePos().x() - this->x());
        else resizeDir = LEFT;
        setBoundingRect(newRect);
    }
    else if (resizeDir == UP)
    {
        setFlag(ItemIsMovable, false);
        QRectF newRect;
        newRect = rect;
        newRect = newRect.normalized();

        if (event->scenePos().y() < this->y() + newRect.bottom()) newRect.setTop(event->scenePos().y() - this->y());
        else resizeDir = DOWN;
        setBoundingRect(newRect);
    }
    else if (resizeDir == DOWN)
    {
        setFlag(ItemIsMovable, false);
        QRectF newRect;
        newRect = rect;
        newRect = newRect.normalized();

        if (event->scenePos().y() > this->y() + newRect.top()) newRect.setBottom(event->scenePos().y() - this->y());
        else resizeDir = UP;
        setBoundingRect(newRect);
    }
    else if (resizeDir == LEFTTOP)
    {
        setFlag(ItemIsMovable, false);
        QRectF newRect;
        newRect = rect;
        newRect = newRect.normalized();

        if (event->scenePos().x() < this->x() + newRect.right())
            newRect.setTopLeft(QPoint(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
        else resizeDir = RIGHTBOTTOM;
        setBoundingRect(newRect);
    }
    else if (resizeDir == RIGHTBOTTOM)
    {
        setFlag(ItemIsMovable, false);
        QRectF newRect;
        newRect = rect;
        newRect = newRect.normalized();

        if (event->scenePos().x() > this->x() + newRect.left())
            newRect.setBottomRight(QPoint(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
        else resizeDir = LEFTTOP;
        setBoundingRect(newRect);
    }
    else if (resizeDir == LEFTBOTTOM)
    {
        setFlag(ItemIsMovable, false);
        QRectF newRect;
        newRect = rect;
        newRect = newRect.normalized();

        if (event->scenePos().x() < this->x() + newRect.right())
            newRect.setBottomLeft(QPoint(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
        else resizeDir = RIGHTTOP;
        setBoundingRect(newRect);
    }
    else if (resizeDir == RIGHTTOP)
    {
        setFlag(ItemIsMovable, false);
        QRectF newRect;
        newRect = rect;
        newRect = newRect.normalized();

        if (event->scenePos().x() > this->x() + newRect.left())
            newRect.setTopRight(QPoint(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
        else resizeDir = LEFTBOTTOM;
        setBoundingRect(newRect);
    }
}

void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    hovering = true;

}

void MyItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    if (hasFocus())
    {
        qreal mouseX, mouseY, left, right, top, bottom;
        mouseX = event->scenePos().x();
        mouseY = event->scenePos().y();
        left = this->x() + boundingRect().left();
        right = this->x() + boundingRect().right();
        top = this->y() + boundingRect().top();
        bottom = this->y() + boundingRect().bottom();

        if (mouseX > left - 5 && mouseX < left + 5)
        {
            if (mouseY > top - 5 && mouseY < top + 5)
            {
                setCursor(Qt::SizeFDiagCursor);
                resizeDir = LEFTTOP;
            }
            else if (mouseY > bottom - 5 && mouseY < bottom + 5)
            {
                setCursor(Qt::SizeBDiagCursor);
                resizeDir = LEFTBOTTOM;
            }
            else
            {
                setCursor(Qt::SizeHorCursor);
                resizeDir = LEFT;
            }
        }
        else if (mouseX > right - 5 && mouseX < right + 5)
        {
            if (mouseY > top - 5 && mouseY < top + 5)
            {
                setCursor(Qt::SizeBDiagCursor);
                resizeDir = RIGHTTOP;
            }
            else if (mouseY > bottom - 5 && mouseY < bottom + 5)
            {
                setCursor(Qt::SizeFDiagCursor);
                resizeDir = RIGHTBOTTOM;
            }
            else
            {
                setCursor(Qt::SizeHorCursor);
                resizeDir = RIGHT;
            }
        }
        else if (mouseY > top - 5 && mouseY < top + 5)
        {
            setCursor(Qt::SizeVerCursor);
            resizeDir = UP;
        }
        else if (mouseY > bottom - 5 && mouseY < bottom + 5)
        {
            setCursor(Qt::SizeVerCursor);
            resizeDir = DOWN;
        }
        else
        {
            setCursor(Qt::ArrowCursor);
            resizeDir = EMPTY;
        }
    }
}

void MyItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
    //qDebug() << event->type();
    hovering = false;
    resizeDir = EMPTY;
    //this->setPen(QColor(Qt::lightGray));
    //fillColor = QColor(255, 255, 255, 200);
}

/////////////////////////

void MyRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    painter->setPen(lineColor);
    painter->setBrush(fillColor);
    painter->drawRect(boundingRect());

    drawBoarder(painter);
}

void MyEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    painter->setPen(lineColor);
    painter->setBrush(fillColor);
    painter->drawEllipse(boundingRect());

    drawBoarder(painter);
}


void MyLineItem::setLineStart(QPoint point)
{
    startPoint.setX(point.x());
    startPoint.setY(point.y());
}

void MyLineItem::setLineEnd(QPoint point)
{
    endPoint.setX(point.x());
    endPoint.setY(point.y());
}


void MyLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    painter->setPen(lineColor);
    painter->setBrush(fillColor);
    painter->drawLine(startPoint, endPoint);

    drawBoarder(painter);
}
