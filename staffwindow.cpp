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
void staffWindow::setShelter(Shelter *shelter_ptr){
    sh = shelter_ptr;
}
void staffWindow::on_viewAnimalsButton_clicked()
{

    this->hide();
    viewAnimals* animalView = new viewAnimals();
    animalView->setShelter(sh);
    animalView->setModal(true);
    animalView->deleteLater();
    animalView->exec();
}
