#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new MyScene;//场景
    scene->setSceneRect(-200, -150, 400, 300);

    for(int i = 0; i < 5; ++i) {
        MyRectItem *item = new MyRectItem;
        item->setRect(i*100, 0, 50, 50);
        scene->addItem(item);
    }

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
    scene->changeMouseMode(DRAG);
    ui->SquareBtn->setChecked(false);
    ui->DragBtn->setChecked(false);
    ui->EllipseButton->setChecked(false);

    ui->DragBtn->setChecked(true);

}

void MainWindow::on_SquareBtn_clicked()
{
    scene->changeMouseMode(RECTANGLE);
    ui->SquareBtn->setChecked(false);
    ui->DragBtn->setChecked(false);
    ui->EllipseButton->setChecked(false);

    ui->SquareBtn->setChecked(true);
}

void MainWindow::on_EllipseButton_clicked()
{
    scene->changeMouseMode(ELLIPSE);
    ui->SquareBtn->setChecked(false);
    ui->DragBtn->setChecked(false);
    ui->EllipseButton->setChecked(false);

    ui->EllipseButton->setChecked(true);

}
