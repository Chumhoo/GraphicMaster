#include "myitem.h"
#include <QVariant>

MyItem::MyItem(QBrush newBrush, QPen newPen) : brush(newBrush), pen(newPen)
{
    clearFocus();
    setAcceptDrops(true);  //设置接收拖放!!!

    setFlag(QGraphicsItem::ItemIsSelectable);  //添加本性质则可同时选择多项
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setAcceptHoverEvents(true);

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
    //通知场景scene即将发生的变化，这样场景可以刷新item的位置下标。否则，场景将不会察觉到item的变化，结果也未知
    prepareGeometryChange();
    update(boundingRect());
}

void MyItem::setBrush(const QBrush newBrush)
{
    brush = newBrush;
}

void MyItem::setPen(const QPen newPen)
{
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
    if(hasFocus() || isSelected()) {
        //        QPixmap pix;
        //        pix.load(":/icons/boarder.png");
        //        painter->drawPixmap(boundingRect().left(), boundingRect().top(), boundingRect().width(), boundingRect().height(), pix);
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
    QGraphicsItem::mousePressEvent(event);
}


void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
        if (resizeDir == EMPTY)
        {
            setFlag(ItemIsMovable, true);
        }
        else
        {
            setFlag(ItemIsMovable, false);
            if (resizeDir == LEFT)
            {
                if (event->scenePos().x() < this->x() + rect.right()) rect.setLeft(event->scenePos().x() - this->x());
                else resizeDir = RIGHT;
                setBoundingRect(rect);
            }
            else if (resizeDir == RIGHT)
            {
                if (event->scenePos().x() > this->x() + rect.left()) rect.setRight(event->scenePos().x() - this->x());
                else resizeDir = LEFT;
                setBoundingRect(rect);
            }
            else if (resizeDir == UP)
            {
                if (event->scenePos().y() < this->y() + rect.bottom()) rect.setTop(event->scenePos().y() - this->y());
                else resizeDir = DOWN;
                setBoundingRect(rect);
            }
            else if (resizeDir == DOWN)
            {
                if (event->scenePos().y() > this->y() + rect.top()) rect.setBottom(event->scenePos().y() - this->y());
                else resizeDir = UP;
                setBoundingRect(rect);
            }
            else if (resizeDir == LEFTTOP)
            {
                if (event->scenePos().x() < this->x() + rect.right())
                    rect.setTopLeft(QPointF(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
                else resizeDir = RIGHTBOTTOM;
                setBoundingRect(rect);
            }
            else if (resizeDir == RIGHTBOTTOM)
            {
                if (event->scenePos().x() > this->x() + rect.left())
                    rect.setBottomRight(QPointF(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
                else resizeDir = LEFTTOP;
                setBoundingRect(rect);
            }
            else if (resizeDir == LEFTBOTTOM)
            {
                if (event->scenePos().x() < this->x() + rect.right())
                    rect.setBottomLeft(QPointF(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
                else resizeDir = RIGHTTOP;
                setBoundingRect(rect);
            }
            else // if (resizeDir == RIGHTTOP)
            {
                if (event->scenePos().x() > this->x() + rect.left())
                    rect.setTopRight(QPointF(event->scenePos().x() - this->x(), event->scenePos().y() - this->y()));
                else resizeDir = LEFTBOTTOM;
                setBoundingRect(rect);
            }
        }
    QGraphicsItem::mouseMoveEvent(event);
}

void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    Q_UNUSED(event);
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
    setCursor(Qt::ArrowCursor);
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
    if (textInteractionFlags() == Qt::NoTextInteraction)
        setTextInteractionFlags(Qt::TextEditorInteraction);
    QGraphicsTextItem::mouseDoubleClickEvent(event);
}

void MyTextItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setFocus();
    setTextInteractionFlags(Qt::NoTextInteraction);
    QGraphicsTextItem::mousePressEvent(event);
}

void MyTextItem::focusOutEvent(QFocusEvent *event)
{
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
