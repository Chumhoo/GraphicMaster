#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myitem.h"
#include "myscene.h"
#include "myview.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_DragBtn_clicked();
    void on_SquareBtn_clicked();
    void on_EllipseButton_clicked();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    MyScene *scene;
    MyView *view;

    void changeMouseMode(MOUSEMODE newMouseMode);
};


#endif // MAINWINDOW_H
