#include "staffwindow.h"
#include "animalListControl.h"
#include "clientListControl.h"
#include "addStaffControl.h"
#include "mainWindow.h"

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
void staffWindow::setMainWindow(MainWindow *main){
    mw = main;
}

//command handler for viewAnimals button
void staffWindow::on_viewAnimalsButton_clicked()
{
    this->hide();
    animalListControl* animalView = new animalListControl();
    animalView->setShelter(sh);
    animalView->setMainWindow(mw);
    animalView->setModal(true);
    animalView->deleteLater();
    animalView->exec();
}

void staffWindow::on_viewClientsButton_clicked()
{
    this->hide();
    clientListControl* clientsView = new clientListControl();
    clientsView->setShelter(sh);
    clientsView->setMainWindow(mw);
    clientsView->setModal(true);
    clientsView->exec();
}


void staffWindow::on_addStaffButton_clicked()
{
    this->hide();
    addStaffControl* staffAdd = new addStaffControl();
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

void staffWindow::on_acmButton_clicked()
{
    qDebug()<<"It's Showtime!";
    ACMAlgorithm acm;
    QMap<Animal*,Client*> matches = acm.runACM(sh->getClients(),sh->getAnimals());
    QList<Animal*> akeys = matches.keys();
    for(int i=0; i<akeys.size();i++){
        akeys[i]->getName();
        matches[akeys[i]]->getFname();
    }

    qDebug()<<"Done?";

}
