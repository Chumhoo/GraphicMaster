#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new MyScene;//场景
    scene->setSceneRect(-200, -150, 400, 300);


//    view = new MyView;
//    view->setScene(scene);
//    view->show();

    ui->graphicsView->setScene(scene);
    ui->SquareBtn->setCheckable(true);
    ui->DragBtn->setCheckable(true);
    ui->DragBtn->setChecked(true);
    ui->EllipseButton->setCheckable(true);

    ui->SquareBtn->setIcon(QIcon(":/icons/rect.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        changeMouseMode(DRAG);
    }
}

void MainWindow::changeMouseMode(MOUSEMODE newMouseMode)
{
    if (newMouseMode == DRAG)
    {
        scene->changeMouseMode(DRAG);
        ui->SquareBtn->setChecked(false);
        ui->DragBtn->setChecked(false);
        ui->EllipseButton->setChecked(false);
        ui->DragBtn->setChecked(true);
    }
    else if (newMouseMode == RECTANGLE)
    {
        scene->changeMouseMode(RECTANGLE);
        ui->SquareBtn->setChecked(false);
        ui->DragBtn->setChecked(false);
        ui->EllipseButton->setChecked(false);
        ui->SquareBtn->setChecked(true);
    }
    else if (newMouseMode == ELLIPSE)
    {
        scene->changeMouseMode(ELLIPSE);
        ui->SquareBtn->setChecked(false);
        ui->DragBtn->setChecked(false);
        ui->EllipseButton->setChecked(false);
        ui->EllipseButton->setChecked(true);
    }
}
