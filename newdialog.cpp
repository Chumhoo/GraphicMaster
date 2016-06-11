#include "newdialog.h"
#include "ui_newdialog.h"

NewDialog::NewDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDialog)
{
    ui->setupUi(this);
    setWindowTitle("新建图像");
}

NewDialog::~NewDialog()
{
    delete ui;
}
