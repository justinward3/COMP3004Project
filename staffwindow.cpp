#include "staffwindow.h"
#include "ui_staffwindow.h"
#include "viewanimals.h"

staffWindow::staffWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staffWindow)
{
    ui->setupUi(this);
}

staffWindow::~staffWindow()
{
    delete ui;
}

void staffWindow::on_viewAnimalsButton_clicked()
{
    this->hide();
    viewAnimals viewAnimals;
    viewAnimals.setModal(true);
    viewAnimals.exec();
}
