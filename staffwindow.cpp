#include "staffwindow.h"
#include "ui_staffwindow.h"
#include "viewanimals.h"
#include "viewclients.h"

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

//set shelter pointer
void staffWindow::setShelter(Shelter *shelter_ptr){
    sh = shelter_ptr;
}

//command handler for viewAnimals button
void staffWindow::on_viewAnimalsButton_clicked()
{
    this->hide();
    viewAnimals* animalView = new viewAnimals();
    animalView->setShelter(sh);
    animalView->setModal(true);
    animalView->deleteLater();
    animalView->exec();
}

void staffWindow::on_viewClientsButton_clicked()
{
    this->hide();
    viewClients viewClients;
    viewClients.setShelter(sh);
    viewClients.setModal(true);
    viewClients.exec();
}

