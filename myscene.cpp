#include "myscene.h"

MyScene::MyScene()
{
    clearFocus();

}

void MyScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    pressing = true;
    if(event->button() != Qt::LeftButton)
    {
        event->ignore();  //如果不是鼠标左键按下，则忽略该事件
        return;
    }

    if (mouseMode == RECTANGLE)
    {
        graph = new MyRectItem();
        this->addItem(graph);
    }
    else if (mouseMode == ELLIPSE)
    {
        graph = new MyEllipseItem();
        this->addItem(graph);
    }
    else if (mouseMode == DRAG) QGraphicsScene::mousePressEvent(event);    //传递事件给Item！
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (pressing)
    {
        if (mouseMode != DRAG)
        {
            QRectF newRect(event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->buttonDownScenePos(Qt::LeftButton).y(),
                           event->scenePos().x() - event->buttonDownScenePos(Qt::LeftButton).x(),
                           event->scenePos().y() - event->buttonDownScenePos(Qt::LeftButton).y());
            newRect = newRect.normalized();       //解决长宽为负的问题
            graph->setRect(newRect);
        }
    }
    if (mouseMode == DRAG) QGraphicsScene::mouseMoveEvent(event);    //传递事件给Item！
}

void MyScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressing = false;
    if (mouseMode == DRAG) QGraphicsScene::mouseReleaseEvent(event);    //传递事件给Item！
}


void MyScene::changeMouseMode(MOUSEMODE newMouseMode)
{
    mouseMode = newMouseMode;
}

