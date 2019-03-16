#include "staffwindow.h"
#include "viewanimals.h"
#include "viewclients.h"
#include "addstaff.h"
#include "mainwindow.h"

staffWindow::staffWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
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

//set main pointer
void staffWindow::setMainWindow(QMainWindow *main){
    mw = main;
}

//command handler for viewAnimals button
void staffWindow::on_viewAnimalsButton_clicked()
{
    this->hide();
    viewAnimals* animalView = new viewAnimals();
    animalView->setShelter(sh);
    animalView->setMainWindow(mw);
    animalView->setModal(true);
    animalView->deleteLater();
    animalView->exec();
}

void staffWindow::on_viewClientsButton_clicked()
{
    this->hide();
    viewClients* clientsView = new viewClients();
    clientsView->setShelter(sh);
    clientsView->setMainWindow(mw);
    clientsView->setModal(true);
    clientsView->exec();
}


void staffWindow::on_addStaffButton_clicked()
{
    this->hide();
    addStaff* staffAdd = new addStaff();
    staffAdd->setShelter(sh);
    staffAdd->setMainWindow(mw);
    staffAdd->setModal(true);
    staffAdd->exec();
}

void staffWindow::on_logOut_clicked()
{
    this->hide();
    mw->show();
}
