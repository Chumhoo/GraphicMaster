#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QMessageBox>
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

    void bringToFront();
    void sendToBack();

    ~MainWindow();

private slots:
    void on_DragBtn_clicked();
    void on_SquareBtn_clicked();
    void on_EllipseButton_clicked();
    void keyPressEvent(QKeyEvent *event);
    void on_lineButton_clicked();
    void on_roundSquareButton_clicked();
    void on_polygonButton_clicked();
    void on_textButton_clicked();
    void on_pencilButton_clicked();
    void on_scaleButton_clicked();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void on_BrushColorButton_2_clicked();

    void on_PenColorButton_clicked();

    void on_penStyle_activated(int index);

    void on_comboBox_activated(int index);

    void on_penThickness_sliderMoved(int position);

    void on_brushAlpha_sliderMoved(int position);

    void on_penAlpha_sliderMoved(int position);

    void on_textColor_clicked();

    void on_font_currentFontChanged(const QFont &f);

    void on_textSize_sliderMoved(int position);

    void on_clearButton_clicked();

    void on_moveToTop_clicked();

    void on_moveToBottom_clicked();

private:
    void updateBrushPreview();
    void updatePenPreview();
    QBrush brush = QBrush(QColor(100, 100, 255), Qt::SolidPattern);
    QPen pen = QPen(QColor(0, 0, 0), 1, Qt::SolidLine);
    QColor textColor = QColor(0, 0, 0);
    QFont font;
    int fontSize = 10;
    Ui::MainWindow *ui;
    MyScene *scene, *brushPreScene, *penPreScene;
    MyView *view;
    qreal scaleX = 1.0, scaleY = 1.0;

    void changeMouseMode(MOUSEMODE newMouseMode);
};


#endif // MAINWINDOW_H
