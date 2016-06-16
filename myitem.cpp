#include "myitem.h"

MyItem::MyItem(QBrush newBrush, QPen newPen) : brush(newBrush), pen(newPen)
{
    clearFocus();
    setAcceptDrops(true);

    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);

    //random select a color for the bound
    selectColor = QColor(qrand() % 256, qrand() % 256, qrand() % 256);
    rect = rect.normalized();
}

QRectF MyItem::boundingRect() const
{
    return QRectF(rect.x()-2, rect.y()-2, rect.width()+4, rect.height()+4).normalized();
}

void MyItem::setBoundingRect(QRectF newRect)
{
    rect = newRect;
    //inform the scene that the boundingRect is going to be changed, or there will be residual in the scene
    prepareGeometryChange();
    update(boundingRect());
}

void MyItem::setBrush(const QBrush newBrush)
{
    //set the brush
    brush = newBrush;
}

void MyItem::setPen(const QPen newPen)
{
    //set the pen
    pen = newPen;
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen);
    painter->setBrush(brush);
    drawBoarder(painter);
}

void MyItem::drawBoarder(QPainter *painter)
{
    if(hasFocus() || isSelected())
    {
        //draw the boarder rectangle
        painter->setPen(QPen(selectColor, 2, Qt::DashLine));
        painter->setBrush(QColor(0, 0, 255, 10));
        painter->drawRect(boundingRect().x(), boundingRect().y(), boundingRect().width(), boundingRect().height());

        painter->setPen(QPen(QColor(255, 255, 255), 1, Qt::SolidLine));
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
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    //pass the mouse event
    QGraphicsItem::mousePressEvent(event);
}


void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (resizeDir == EMPTY)
    {
        //move the item
        setFlag(ItemIsMovable, true);
    }
    else
    {
        setFlag(ItemIsMovable, false);
        if (resizeDir == LEFT)
        {
            //resize left boarder
            if (event->scenePos().x() < this->x() + rect.right())
                rect.setLeft(event->scenePos().x() - this->x());
            //change resize direction
            else resizeDir = RIGHT;
            setBoundingRect(rect);
        }
        else if (resizeDir == RIGHT)
        {
            //resize right boarder
            if (event->scenePos().x() > this->x() + rect.left())
                rect.setRight(event->scenePos().x() - this->x());
            //change resize direction
            else resizeDir = LEFT;
            setBoundingRect(rect);
        }
        else if (resizeDir == UP)
        {
            //resize top boarder
            if (event->scenePos().y() < this->y() + rect.bottom())
                rect.setTop(event->scenePos().y() - this->y());
            //change resize direction
            else resizeDir = DOWN;
            setBoundingRect(rect);
        }
        else if (resizeDir == DOWN)
        {
            //resize bottom boarder
            if (event->scenePos().y() > this->y() + rect.top())
                rect.setBottom(event->scenePos().y() - this->y());
            //change resize direction
            else resizeDir = UP;
            setBoundingRect(rect);
        }
        else if (resizeDir == LEFTTOP)
        {
            //resize the left top point
            if (event->scenePos().x() < this->x() + rect.right())
                rect.setTopLeft(QPointF(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
            //change resize direction
            else resizeDir = RIGHTBOTTOM;
            setBoundingRect(rect);
        }
        else if (resizeDir == RIGHTBOTTOM)
        {
            //resize the right bottom point
            if (event->scenePos().x() > this->x() + rect.left())
                rect.setBottomRight(QPointF(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
            else resizeDir = LEFTTOP;
            setBoundingRect(rect);
        }
        else if (resizeDir == LEFTBOTTOM)
        {
            //resize the left bottom point
            if (event->scenePos().x() < this->x() + rect.right())
                rect.setBottomLeft(QPointF(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
            else resizeDir = RIGHTTOP;
            setBoundingRect(rect);
        }
        else // if (resizeDir == RIGHTTOP)
        {
            // resize the right top point
            if (event->scenePos().x() > this->x() + rect.left())
                rect.setTopRight(QPointF(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
            else resizeDir = LEFTBOTTOM;
            setBoundingRect(rect);
        }
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void MyItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    if (hasFocus())
    {
        qreal mouseX, mouseY, left, right, top, bottom;
        //configure the coordinates of mouse
        mouseX = event->scenePos().x();
        mouseY = event->scenePos().y();

        //set left, right, top, bottom position
        left = this->x() + boundingRect().left();
        right = this->x() + boundingRect().right();
        top = this->y() + boundingRect().top();
        bottom = this->y() + boundingRect().bottom();

        //change cursor type and resize mode
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

/////////////////////////

void MyRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRect(boundingRect());

    drawBoarder(painter);
}

void MyEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(boundingRect());

    drawBoarder(painter);
}

void MyRoundRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                            QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawRoundRect(boundingRect());

    drawBoarder(painter);
}


void MyLineItem::setLine(QPointF startP, QPointF endP)
{
    start.setX((startP.x() - boundingRect().left()) / boundingRect().width());
    start.setY((startP.y() - boundingRect().top()) / boundingRect().height());
    end.setX((endP.x() - boundingRect().left()) / boundingRect().width());
    end.setY((endP.y() - boundingRect().top()) / boundingRect().height());
}


void MyLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                       QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawLine(QPointF(start.x() * boundingRect().width() + boundingRect().left(),
                              start.y() * boundingRect().height() + boundingRect().top()),
                      QPointF(end.x() * boundingRect().width()+ boundingRect().left(),
                              end.y() * boundingRect().height() + boundingRect().top()));
    drawBoarder(painter);
}

QRectF MyPencilItem::boundingRect() const
{
    return path.boundingRect().normalized();
}

void MyPencilItem::setStart(QPointF point)
{
    path.moveTo(point);
}

void MyPencilItem::addPoint(QPointF point)
{
    path.lineTo(point);
    update(boundingRect());
}

void MyPencilItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                         QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QBrush newBrush = brush;
    QColor newColor = brush.color();
    newColor.setAlpha(0);
    newBrush.setColor(newColor);

    painter->setPen(pen);
    painter->setBrush(newBrush);
    painter->drawPath(path);

    drawBoarder(painter);
}

QRectF MyPolygonItem::boundingRect() const
{
    return polygon.boundingRect().normalized();
}

void MyPolygonItem::addPoint(QPointF point)
{
    polygon << point;
    update(boundingRect());
}

void MyPolygonItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                          QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawPolygon(polygon);

    drawBoarder(painter);
}

MyTextItem::MyTextItem(QFont font, QColor textColor)
{
    setFont(font);
    setDefaultTextColor(textColor);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setTextInteractionFlags(Qt::TextEditorInteraction);
    this->setFocus();
}

void MyTextItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}

void MyTextItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    QGraphicsTextItem::mousePressEvent(event);
}

void MyTextItem::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);
    setTextInteractionFlags(Qt::NoTextInteraction);
}

void MyTextItem::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        if (textInteractionFlags() == Qt::TextEditorInteraction)
        {
            setTextInteractionFlags(Qt::NoTextInteraction);
            clearFocus();
            break;
        }
        else
        {
            this->~MyTextItem();
            return;
        }
    case Qt::Key_Up:  if (textInteractionFlags() == Qt::NoTextInteraction)this->moveBy(0, -2);break;
    case Qt::Key_Down: if (textInteractionFlags() == Qt::NoTextInteraction) this->moveBy(0, 2);break;
    case Qt::Key_Left: if (textInteractionFlags() == Qt::NoTextInteraction) this->moveBy(-2, 0);break;
    case Qt::Key_Right: if (textInteractionFlags() == Qt::NoTextInteraction) this->moveBy(2, 0);break;
    }
    QGraphicsTextItem::keyPressEvent(event);
}
