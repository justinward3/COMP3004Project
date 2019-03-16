#include "clientwindow.h"
#include "ui_menu.h"
#include "animalListView.h"
#include "viewclients.h"
#include "addclient.h"
#include "mainwindow.h"

clientWindow::clientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    ui->label->setText("cuACS Client Portal");
    ui->addStaffButton->setVisible(false);
    ui->viewClientsButton->setVisible(false);
    ui->acmButton->setVisible(false);
}

clientWindow::~clientWindow()
{
    delete ui;
}

//set shelter pointer
void clientWindow::setShelter(Shelter *shelter_ptr){
    sh = shelter_ptr;
}

//set main pointer
void clientWindow::setMainWindow(QMainWindow *main){
    mw = main;
}

//command handler for viewAnimals button
void clientWindow::on_viewAnimalsButton_clicked()
{
    this->hide();
    animalListView* animalView = new animalListView();
    animalView->setShelter(sh);
    animalView->setMainWindow(mw);
    animalView->setUserView();
    animalView->setModal(true);
    animalView->deleteLater();
    animalView->exec();
}

void clientWindow::on_logOut_clicked()
{
    this->hide();
    mw->show();
}
