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
        //create a new rectangle
        if (mouseMode == RECTANGLE)
        {
            fixedGraph = new MyRectItem(brush, pen);
            this->addItem(fixedGraph);
        }
        //create a new rounded rectangle
        else if (mouseMode == ROUNDRECT)
        {
            fixedGraph = new MyRoundRectItem(brush, pen);
            this->addItem(fixedGraph);
        }
        //create a new ellipse
        else if (mouseMode == ELLIPSE)
        {
            fixedGraph = new MyEllipseItem(brush, pen);
            this->addItem(fixedGraph);
        }
        // create a new line
        else if (mouseMode == LINE)
        {
            line = new MyLineItem(brush, pen);
            this->addItem(line);
        }
        //create a new pencil item
        else if (mouseMode == PENCIL)
        {
            pencil = new MyPencilItem(brush, pen);
            pencil->setStart(event->scenePos());
            this->addItem(pencil);
        }   
        else if (mouseMode == POLYGON)
        {
            // if there're no polygons being drawing
            if ((polygon == NULL) || (polygon->drawing != true))
            {
                polygon = new MyPolygonItem(brush, pen);
                polygon->drawing = true;
                polygon->addPoint(event->scenePos());
                this->addItem(polygon);
            }
            else
            {
                //add point to the polyogn
                polygon->addPoint(event->scenePos());
            }
        }
        //create a new text item
        else if (mouseMode == TEXT)
        {
            textItem = new MyTextItem(font, textColor);
            //active the text editor
            textItem->setTextInteractionFlags(Qt::TextEditorInteraction);
            textItem->setZValue(1000.0);
            this->addItem(textItem);
            textItem->setPos(event->scenePos());
        }
        else if (mouseMode == DRAG)
        {
            //pass the event to item
            QGraphicsScene::mousePressEvent(event);
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        if (mouseMode == POLYGON && polygon != NULL)
        {
            //stop drawing the polygon
            polygon->drawing = false;
        }
        else if (mouseMode == DRAG)
        {
            //create a new select rectangle
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
            //change the size of the select rectangle
            QRectF newRect(event->buttonDownScenePos(Qt::RightButton).x(),
                           event->buttonDownScenePos(Qt::RightButton).y(),
                           event->scenePos().x() - event->buttonDownScenePos(Qt::RightButton).x(),
                           event->scenePos().y() - event->buttonDownScenePos(Qt::RightButton).y());
            newRect = newRect.normalized();       //解决长宽为负的问题

            //set pen and brush
            selectArea->setPen(QPen(QColor(0,0,255), 1));
            selectArea->setBrush(QBrush(QColor(0, 0, 255, 20)));
            selectArea->setRect(newRect);
        }
        else if (mouseMode == PENCIL)
        {
            //add point to pencil
            pencil->addPoint(event->scenePos());
        }
        else if (mouseMode == POLYGON && polygon != NULL && polygon->drawing == true)
        {
           //add point to polygon
            polygon->addPoint(event->scenePos());
        }
        else if (mouseMode == RECTANGLE || mouseMode == ELLIPSE || mouseMode == ROUNDRECT)
        {
            //change the size of the graphic
            QRectF newRect(event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->buttonDownScenePos(Qt::LeftButton).y(),
                           event->scenePos().x() - event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->scenePos().y() - event->buttonDownScenePos(Qt::LeftButton).y());
            newRect = newRect.normalized();       //解决长宽为负的问题
            fixedGraph->setBoundingRect(newRect);
        }
        else if(mouseMode == LINE)
        {
            //change the size of line
            QRectF newRect(event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->buttonDownScenePos(Qt::LeftButton).y(),
                           event->scenePos().x() - event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->scenePos().y() - event->buttonDownScenePos(Qt::LeftButton).y());
            //change the lefttop point and rightbottom point if necessary
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
        //set selection area
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
                //delete the item
                foreach (QGraphicsItem *item, selectedItems())
                    delete item;
            }
        }
        break;
    case Qt::Key_Up:
        if (!selectedItems().isEmpty())
        {
            //move up
            foreach (QGraphicsItem *item, selectedItems())
                item->moveBy(0, -2);
        }
        break;
    case Qt::Key_Down:
        if (!selectedItems().isEmpty())
        {
            //move down
            foreach (QGraphicsItem *item, selectedItems())
                item->moveBy(0, 2);
        }
        break;
    case Qt::Key_Left:
        if (!selectedItems().isEmpty())
        {
            //move left
            foreach (QGraphicsItem *item, selectedItems())
                item->moveBy(-2, 0);
        }
        break;
    case Qt::Key_Right:
        if (!selectedItems().isEmpty())
        {
            //move right
            foreach (QGraphicsItem *item, selectedItems())
                item->moveBy(2, 0);
        }
        break;
    }
    QGraphicsScene::keyPressEvent(event);
}

void MyScene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    //if no items are selected, return directly
    if (focusItem() == NULL) return;
    //add menu items
    QMenu menu;
    QAction *deleteAction = menu.addAction("删除");
    QAction *moveUpAction = menu.addAction("上移");
    QAction *moveDownAction = menu.addAction("下移");
    QAction *selectedAction = menu.exec(event->screenPos());

    if(selectedAction == moveUpAction)
    {
        QGraphicsItem *selectedItem = focusItem();
        QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();
        qreal zValue = 0;
        foreach (QGraphicsItem *item, overlapItems)
        {
            //traverse all the overlapped items and lift this item up
            if (item->zValue() >= zValue)
                zValue = item->zValue() + 0.1;
        }
        selectedItem->setZValue(zValue);
    }
    else if(selectedAction == moveDownAction)
    {
        QGraphicsItem *selectedItem = focusItem();
        QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();
        qreal zValue = 0;
        foreach (QGraphicsItem *item, overlapItems)
        {
            //traverse all the overlapped items and put this item below
            if (item->zValue() <= zValue)
                zValue = item->zValue() - 0.1;
        }
        selectedItem->setZValue(zValue);
    }
    else if(selectedAction == deleteAction)
    {
        delete focusItem();
    }
    pressing = false;
}

void MyScene::changeMouseMode(MOUSEMODE newMouseMode)
{
    //change the mouse mode
    mouseMode = newMouseMode;
    if (polygon != NULL) polygon->drawing = false;
}

