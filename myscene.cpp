#include "myscene.h"

MyScene::MyScene()
{
    clearFocus();
}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    clearFocus();
    pressing = true;
    if(event->button() == Qt::LeftButton)
    {
        if (mouseMode == RECTANGLE)
        {
            fixedGraph = new MyRectItem(brush, pen);
            this->addItem(fixedGraph);
        }
        else if (mouseMode == ROUNDRECT)
        {
            fixedGraph = new MyRoundRectItem(brush, pen);
            this->addItem(fixedGraph);
        }
        else if (mouseMode == ELLIPSE)
        {
            fixedGraph = new MyEllipseItem(brush, pen);
            this->addItem(fixedGraph);
        }
        else if (mouseMode == LINE)
        {
            line = new MyLineItem(brush, pen);
            this->addItem(line);
        }
        else if (mouseMode == PENCIL)
        {
            pencil = new MyPencilItem(brush, pen);
            pencil->setStart(event->scenePos());
            this->addItem(pencil);
        }

        else if (mouseMode == POLYGON)
        {
            if ((polygon == NULL) ||
                    (polygon->drawing != true))
            {
                polygon = new MyPolygonItem(brush, pen);
                polygon->drawing = true;
                polygon->addPoint(event->scenePos());
                this->addItem(polygon);
            }
            else
            {
                polygon->addPoint(event->scenePos());
            }
        }
        else if (mouseMode == TEXT)
        {
            textItem = new MyTextItem(font, textColor);
            // textItem->setFont(myFont);
            textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
            textItem->setZValue(1000.0);
            this->addItem(textItem);
            //            textItem->setDefaultTextColor(myTextColor);
            textItem->setPos(event->scenePos());
            //            emit textInserted(textItem);
        }
        else if (mouseMode == DRAG)
        {
            QGraphicsScene::mousePressEvent(event);    //传递事件给Item
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        if (mouseMode == POLYGON && polygon != NULL)
        {
            polygon->drawing = false;
        }
        else if (mouseMode == DRAG)
        {
            if (selectedItems().isEmpty())
            {
                selectArea = new QGraphicsRectItem();
                this->addItem(selectArea);
                changeMouseMode(SELECT);
            }
        }
    }
    QGraphicsScene::mousePressEvent(event);
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (pressing)
    {
        if (mouseMode == SELECT)
        {
            QRectF newRect(event->buttonDownScenePos(Qt::RightButton).x(),
                           event->buttonDownScenePos(Qt::RightButton).y(),
                           event->scenePos().x() - event->buttonDownScenePos(Qt::RightButton).x(),
                           event->scenePos().y() - event->buttonDownScenePos(Qt::RightButton).y());
            newRect = newRect.normalized();       //解决长宽为负的问题

            selectArea->setPen(QPen(QColor(0,0,255), 1));
            selectArea->setBrush(QBrush(QColor(0, 0, 255, 20)));
            selectArea->setRect(newRect);
        }
        else if (mouseMode == PENCIL)
        {
            pencil->addPoint(event->scenePos());
        }
        else if (mouseMode == POLYGON && polygon != NULL && polygon->drawing == true)
        {
            polygon->addPoint(event->scenePos());
        }
        else if (mouseMode == RECTANGLE || mouseMode == ELLIPSE || mouseMode == ROUNDRECT)
        {
            QRectF newRect(event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->buttonDownScenePos(Qt::LeftButton).y(),
                           event->scenePos().x() - event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->scenePos().y() - event->buttonDownScenePos(Qt::LeftButton).y());
            newRect = newRect.normalized();       //解决长宽为负的问题
            fixedGraph->setBoundingRect(newRect);
        }
        else if(mouseMode == LINE)
        {
            QRectF newRect(event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->buttonDownScenePos(Qt::LeftButton).y(),
                           event->scenePos().x() - event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->scenePos().y() - event->buttonDownScenePos(Qt::LeftButton).y());
            newRect = newRect.normalized();       //解决长宽为负的问题
            line->setBoundingRect(newRect);
            line->setLine(QPoint(event->buttonDownScenePos(Qt::LeftButton).x(), event->buttonDownScenePos(Qt::LeftButton).y()),
                          QPoint(event->scenePos().x(), event->scenePos().y()));
        }
    }
    if (mouseMode == DRAG) QGraphicsScene::mouseMoveEvent(event);    //传递事件给Item！
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressing = false;

    if (mouseMode == DRAG) QGraphicsScene::mouseReleaseEvent(event);    //传递事件给Item！
    else if (mouseMode == SELECT)
    {
        QPainterPath selectPath;
        selectPath.addRect(selectArea->rect());
        setSelectionArea(selectPath);
        delete selectArea;
        changeMouseMode(DRAG);
    }
}

void MyScene::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Escape:
        if (mouseMode == DRAG)
        {
            if (!selectedItems().isEmpty())
            {
                foreach (QGraphicsItem *item, selectedItems())
                    item->~QGraphicsItem();
            }
        }
        break;
    case Qt::Key_Up:
        if (!selectedItems().isEmpty())
        {
            foreach (QGraphicsItem *item, selectedItems())
                item->moveBy(0, -2);        }
        break;
    case Qt::Key_Down:
        if (!selectedItems().isEmpty())
        {
            foreach (QGraphicsItem *item, selectedItems())
                item->moveBy(0, 2);        }
        break;
    case Qt::Key_Left:
        if (!selectedItems().isEmpty())
        {
            foreach (QGraphicsItem *item, selectedItems())
                item->moveBy(-2, 0);        }
        break;
    case Qt::Key_Right:
        if (!selectedItems().isEmpty())
        {
            foreach (QGraphicsItem *item, selectedItems())
                item->moveBy(2, 0);        }
        break;
    }
    QGraphicsScene::keyPressEvent(event);
}

void MyScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    if (focusItem() == NULL) return;
    QMenu menu;
    QAction *deleteAction = menu.addAction("删除");
    QAction *moveUpAction = menu.addAction("上移");
    QAction *moveDownAction = menu.addAction("下移");
    QAction *selectedAction = menu.exec(event->screenPos());

    if(selectedAction == moveUpAction) {
        QGraphicsItem *selectedItem = focusItem();
        QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();
        qreal zValue = 0;
        foreach (QGraphicsItem *item, overlapItems) {
            if (item->zValue() >= zValue)
                zValue = item->zValue() + 0.1;
        }
        selectedItem->setZValue(zValue);
    }
    else if(selectedAction == moveDownAction) {
        QGraphicsItem *selectedItem = focusItem();
        QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();
        qreal zValue = 0;
        foreach (QGraphicsItem *item, overlapItems) {
            if (item->zValue() <= zValue)
                zValue = item->zValue() - 0.1;
        }
        selectedItem->setZValue(zValue);
    }
    else if(selectedAction == deleteAction) {
        delete focusItem();
    }
    pressing = false;
}

void MyScene::changeMouseMode(MOUSEMODE newMouseMode)
{
    mouseMode = newMouseMode;
    if (polygon != NULL) polygon->drawing = false;
}

