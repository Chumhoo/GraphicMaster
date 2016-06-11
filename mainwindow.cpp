#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("图形大师 - 未命名");
    scene = new MyScene;//场景
    scene->setSceneRect(-200, -150, 400, 300);
    scene->setBackgroundBrush(QBrush(QColor(255, 255, 255), Qt::SolidPattern));
    brushPreScene = new MyScene;
    brushPreScene->setSceneRect(-40, 0, 80, 10);
    penPreScene = new MyScene;
    penPreScene->setSceneRect(-40, 0, 80, 10);

    ui->graphicsView->setScene(scene);
    ui->penPreview->setScene(penPreScene);
    ui->brushPreview->setScene(brushPreScene);
    ui->SquareBtn->setCheckable(true);
    ui->pencilButton->setCheckable(true);
    ui->DragBtn->setCheckable(true);
    ui->DragBtn->setChecked(true);
    ui->EllipseButton->setCheckable(true);
    ui->roundSquareButton->setCheckable(true);
    ui->lineButton->setCheckable(true);
    ui->polygonButton->setCheckable(true);
    ui->textButton->setCheckable(true);
    ui->scaleButton->setCheckable(true);

    ui->SquareBtn->setIcon(QIcon(":/icons/rect.png"));
    ui->DragBtn->setIcon(QIcon(":/icons/hand.png"));
    ui->EllipseButton->setIcon(QIcon(":/icons/ellipse.png"));
    ui->lineButton->setIcon(QIcon(":/icons/line.png"));
    ui->roundSquareButton->setIcon(QIcon(":/icons/roundSquare.png"));
    ui->polygonButton->setIcon(QIcon(":/icons/polygon.png"));
    ui->textButton->setIcon(QIcon(":/icons/text.png"));
    ui->scaleButton->setIcon(QIcon(":/icons/scaler.png"));
    ui->pencilButton->setIcon(QIcon(":/icons/pencil.png"));

    updateBrushPreview();
    updatePenPreview();
    scene->setPen(pen);
    scene->setBrush(brush);
    font = ui->font->currentFont();
    font.setPointSize(fontSize);
    scene->setTextFormat(font, textColor);

    QString styleSheet = QString("background-color: rgb(%1, %2, %3);").arg(brush.color().red()).arg(brush.color().green()).arg(brush.color().blue());
    ui->BrushColorButton_2->setStyleSheet(styleSheet);
    styleSheet = QString("background-color: rgb(%1, %2, %3);").arg(pen.color().red()).arg(pen.color().green()).arg(pen.color().blue());
    ui->PenColorButton->setStyleSheet(styleSheet);
    styleSheet = QString("background-color: rgb(%1, %2, %3);").arg(textColor.red()).arg(textColor.green()).arg(textColor.blue());
    ui->textColor->setStyleSheet(styleSheet);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateBrushPreview()
{
    brushPreScene->clear();
    brushPreScene->addRect(-40, 0, 80, 10, QPen(Qt::NoPen), brush);
    brushPreScene->update();
}

void MainWindow::updatePenPreview()
{
    penPreScene->clear();
    penPreScene->addLine(-40, 5, 40, 5, pen);
    penPreScene->update();
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        changeMouseMode(DRAG);
    }
    QMainWindow::keyPressEvent(event);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    if(scene->mouseMode == SCALE)
    {
        if (event->delta() > 0) ui->graphicsView->scale(1.1, 1.1);
        else ui->graphicsView->scale(0.9, 0.9);
    }
    QMainWindow::wheelEvent(event);
}

void MainWindow::changeMouseMode(MOUSEMODE newMouseMode)
{
    ui->DragBtn->setChecked(false);
    ui->pencilButton->setChecked(false);
    ui->SquareBtn->setChecked(false);
    ui->EllipseButton->setChecked(false);
    ui->lineButton->setChecked(false);
    ui->roundSquareButton->setChecked(false);
    ui->polygonButton->setChecked(false);
    ui->textButton->setChecked(false);
    ui->scaleButton->setChecked(false);

    scene->changeMouseMode(newMouseMode);
    scene->clearFocus();
    switch(newMouseMode)
    {
    case DRAG:      ui->DragBtn->setChecked(true); break;
    case PENCIL:      ui->pencilButton->setChecked(true); break;
    case RECTANGLE: ui->SquareBtn->setChecked(true); break;
    case ELLIPSE:   ui->EllipseButton->setChecked(true); break;
    case LINE:      ui->lineButton->setChecked(true); break;
    case ROUNDRECT: ui->roundSquareButton->setChecked(true); break;
    case POLYGON:   ui->polygonButton->setChecked(true); break;
    case TEXT:      ui->textButton->setChecked(true); break;
    case SCALE:   ui->scaleButton->setChecked(true); break;
    }
}

void MainWindow::on_DragBtn_clicked()
{
    changeMouseMode(DRAG);
}

void MainWindow::on_SquareBtn_clicked()
{
    changeMouseMode(RECTANGLE);
}

void MainWindow::on_EllipseButton_clicked()
{
    changeMouseMode(ELLIPSE);
}

void MainWindow::on_lineButton_clicked()
{
    changeMouseMode(LINE);
}

void MainWindow::on_roundSquareButton_clicked()
{
    changeMouseMode(ROUNDRECT);
}

void MainWindow::on_polygonButton_clicked()
{
    changeMouseMode(POLYGON);
}

void MainWindow::on_textButton_clicked()
{
    changeMouseMode(TEXT);
}

void MainWindow::on_pencilButton_clicked()
{
    changeMouseMode(PENCIL);
}

void MainWindow::on_scaleButton_clicked()
{
    changeMouseMode(SCALE);
}

void MainWindow::on_BrushColorButton_2_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    brush.setColor(color);
    scene->setBrush(brush);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyItem*>(item)->setBrush(brush);
    }
    updateBrushPreview();
    scene->update();

    QString styleSheet = QString("background-color: rgb(%1, %2, %3);").arg(brush.color().red()).arg(brush.color().green()).arg(brush.color().blue());
    ui->BrushColorButton_2->setStyleSheet(styleSheet);
}

void MainWindow::on_PenColorButton_clicked()
{
    QColor color = QColorDialog::getColor(Qt::white, this);
    pen.setColor(color);
    scene->setPen(pen);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyItem*>(item)->setPen(pen);
    }
    updatePenPreview();
    scene->update();

    QString styleSheet = QString("background-color: rgb(%1, %2, %3);").arg(pen.color().red()).arg(pen.color().green()).arg(pen.color().blue());
    ui->PenColorButton->setStyleSheet(styleSheet);
}

void MainWindow::on_textColor_clicked()
{
    textColor = QColorDialog::getColor(Qt::white, this);

    scene->setTextFormat(font, textColor);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyTextItem*>(item)->setDefaultTextColor(textColor);
    }
    QString styleSheet = QString("background-color: rgb(%1, %2, %3);").arg(textColor.red()).arg(textColor.green()).arg(textColor.blue());
    ui->textColor->setStyleSheet(styleSheet);

    scene->update();
}

void MainWindow::on_penStyle_activated(int index)
{
    Qt::PenStyle style;
    if (index == 0) style = Qt::SolidLine;
    else if (index == 1)  style = Qt::DotLine;
    else if (index == 2)  style = Qt::DashLine;
    else if (index == 3)  style = Qt::DashDotLine;
    else  style = Qt::DashDotDotLine;

    pen.setStyle(style);
    scene->setPen(pen);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyItem*>(item)->setPen(pen);
    }
    updatePenPreview();
    scene->update();
}

void MainWindow::on_comboBox_activated(int index)
{
    Qt::BrushStyle style;
    switch(index)
    {
    case 0: style = Qt::SolidPattern; break;
    case 1: style = Qt::Dense1Pattern; break;
    case 2: style = Qt::Dense2Pattern; break;
    case 3: style = Qt::Dense3Pattern; break;
    case 4: style = Qt::Dense4Pattern; break;
    case 5: style = Qt::Dense5Pattern; break;
    case 6: style = Qt::Dense6Pattern; break;
    case 7: style = Qt::Dense7Pattern; break;
    case 8: style = Qt::HorPattern; break;
    case 9: style = Qt::VerPattern; break;
    case 10: style = Qt::CrossPattern; break;
    case 11: style = Qt::BDiagPattern; break;
    case 12: style = Qt::FDiagPattern; break;
    case 13: style = Qt::DiagCrossPattern; break;
    }
    brush.setStyle(style);
    scene->setBrush(brush);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyItem*>(item)->setBrush(brush);
    }
    updateBrushPreview();
    scene->update();
}

void MainWindow::on_penThickness_sliderMoved(int position)
{
    pen.setWidth(position);
    scene->setPen(pen);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyItem*>(item)->setPen(pen);
    }
    updatePenPreview();
    scene->update();
}

void MainWindow::on_brushAlpha_sliderMoved(int position)
{
    QColor newColor = brush.color();
    newColor.setAlpha(position);
    brush.setColor(newColor);
    scene->setBrush(brush);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyItem*>(item)->setBrush(brush);
    }
    updateBrushPreview();
    scene->update();
}

void MainWindow::on_penAlpha_sliderMoved(int position)
{
    QColor newColor = pen.color();
    newColor.setAlpha(position);
    pen.setColor(newColor);
    scene->setPen(pen);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyItem*>(item)->setPen(pen);
    }
    updatePenPreview();
    scene->update();
}


void MainWindow::on_font_currentFontChanged(const QFont &f)
{
    font = f;
    font.setPointSize(fontSize);
    scene->setTextFormat(font, textColor);

    if (scene->selectedItems().isEmpty()) return;
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyTextItem*>(item)->setFont(font);
    }
    scene->update();
}

void MainWindow::on_textSize_sliderMoved(int position)
{
    fontSize = position;
    font.setPointSize(fontSize);
    scene->setTextFormat(font, textColor);
    foreach (QGraphicsItem *item, scene->selectedItems())
    {
        static_cast<MyTextItem*>(item)->setFont(font);
    }
    scene->update();
}

void MainWindow::on_clearButton_clicked()
{
    scene->clear();
    scene->update();
}

void MainWindow::on_moveToTop_clicked()
{
    if (scene->selectedItems().isEmpty()) return;

    QGraphicsItem *selectedItem = scene->selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() >= zValue)
            zValue = item->zValue() + 0.1;
    }
    selectedItem->setZValue(zValue);
}

void MainWindow::on_moveToBottom_clicked()
{
    if (scene->selectedItems().isEmpty())
        return;

    QGraphicsItem *selectedItem = scene->selectedItems().first();
    QList<QGraphicsItem *> overlapItems = selectedItem->collidingItems();

    qreal zValue = 0;
    foreach (QGraphicsItem *item, overlapItems) {
        if (item->zValue() <= zValue)
            zValue = item->zValue() - 0.1;
    }
    selectedItem->setZValue(zValue);
}


void MainWindow::on_actionNew_triggered()
{
    scene->clear();
    setWindowTitle("图形大师 - 未命名");
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about( this, "About",
            "Authors List：李致昊 金鹏 阿文鑫\n\n"
            "Copyright 2016-2099.\n"
            "Any problems, please contact 515646122@qq.com\n" );
}

void MainWindow::on_actionInput_triggered()
{
    QPixmap image;
    QGraphicsPixmapItem *pixItem;
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开文件"));
    if (fileName.isEmpty()) return;
    else
    {
        if(image.load(fileName))
        {
            QMessageBox::information(this, "提示", fileName+"\n载入成功!", "确定");
            pixItem = scene->addPixmap(image);
            pixItem->setFlag(QGraphicsItem::ItemIsSelectable);  //添加本性质则可同时选择多项
            pixItem->setFlag(QGraphicsItem::ItemIsFocusable);
            pixItem->setFlag(QGraphicsItem::ItemIsMovable);
        }
    }
}

void MainWindow::on_actionPng_triggered()
{
    QImage image(QSize(1280,960), QImage::Format_RGB32);
    QPainter painter(&image);

    scene->clearFocus();
    scene->clearSelection();
    scene->render(&painter);   //关键函数

    QString fileName = QFileDialog::getSaveFileName(this, tr("导出为图片"), ".png");
    if (fileName.isEmpty())
        return;
    else
    {
        if(image.save(fileName))
            QMessageBox::information(this, "提示", fileName+"\n保存成功!", "确定");
        else
            QMessageBox::critical(this, "错误", "缺失后缀名!", "确定");
        setWindowTitle("图形大师 - " + fileName);
    }
}

void MainWindow::on_actionJpg_triggered()
{
    QImage image(QSize(1280,960), QImage::Format_RGB32);
    QPainter painter(&image);

    scene->clearFocus();
    scene->clearSelection();
    scene->render(&painter);   //关键函数

    QString fileName = QFileDialog::getSaveFileName(this, tr("导出为图片"), ".jpg");
    if (fileName.isEmpty())
        return;
    else
    {
        if(image.save(fileName))
            QMessageBox::information(this, "提示", fileName+"\n保存成功!", "确定");
        else
            QMessageBox::critical(this, "错误", "缺失后缀名!", "确定");
        setWindowTitle("图形大师 - " + fileName);
    }
}

void MainWindow::on_actionHif_triggered()
{
    QImage image(QSize(1280,960), QImage::Format_RGB32);
    QPainter painter(&image);

    scene->clearFocus();
    scene->clearSelection();
    scene->render(&painter);   //关键函数

    QString fileName = QFileDialog::getSaveFileName(this, tr("导出为图片"), ".gif");
    if (fileName.isEmpty())
        return;
    else
    {
        if(image.save(fileName))
            QMessageBox::information(this, "提示", fileName+"\n保存成功!", "确定");
        else
            QMessageBox::critical(this, "错误", "缺失后缀名!", "确定");
        setWindowTitle("图形大师 - " + fileName);
    }
}
