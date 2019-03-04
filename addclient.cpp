#include "addclient.h"
#include "ui_addclient.h"
#include "viewanimals.h"
#include "mainwindow.h"
#include "QMessageBox"

addClient::addClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addClient)
{
    ui->setupUi(this);
    ui->editButton->setVisible(false);
}

//Deconstructor
addClient::~addClient()
{
    delete ui;
}

//set view
void addClient::setView(int view, Client *client)
{
    //view = 1, then this view will be used for view/edit
    if (view == 1) {
        ui->label->setText("View Client");
        ui->addButton->setVisible(false);
        ui->editButton->setVisible(true);
        ui->label_6->setVisible(false);

        addClientFields(false);

        ui->clientFName->setText(client->getFname());
        ui->clientLName->setText(client->getLname());
        ui->clientEmail->setText(client->getEmail());
        ui->clientPNum->setText(client->getPhoneNumber());
        ui->clientAdd->setText(client->getAddress());
    }
}

// enable/disable fields
void addClient::addClientFields(bool flag) {
    ui->clientFName->setEnabled(flag);
    ui->clientLName->setEnabled(flag);
    ui->clientEmail->setEnabled(flag);
    ui->clientPNum->setEnabled(flag);
    ui->clientAdd->setEnabled(flag);
}

//set shelter pointer
void addClient::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

//command handler for back button
void addClient::on_backButton_clicked()
{
    this->hide();
    viewClients viewClients;
    viewClients.setShelter(sh);
    viewClients.setModal(true);
    viewClients.exec();
}

//command handler for add button
void addClient::on_addButton_clicked()
{
    //local vars for instantiation of new Animal
    QString Fname = ui->clientFName->text();
    QString Lname = ui->clientLName->text();
    QString Add = ui->clientAdd->text();
    QString PNum = ui->clientPNum->text();
    QString email = ui->clientEmail->text();
    //Check fields have value
    if (Fname!="" && Lname!="" && Add!="" && PNum!="" && email!="") {
        //Create client
         client = new Client(Fname,Lname,Add,PNum,email);
        //If successfully added to Shelter, pop a success message and go back
        if(sh->operator +=(client)){
            QMessageBox::critical(0, "DB Status",client->getFname()+" added to DATABASE", QMessageBox::Ok);
            this->on_backButton_clicked();
        }
        else{
            //pop a failed message
            QMessageBox::critical(0, "DB Status","DATABASE FAILURE, please contact system admin", QMessageBox::Ok);
        }
    }
    else {
        //pop a message informing of invalid info
        QMessageBox::critical(0, "Add Client","Invalid Info", QMessageBox::Ok);
    }

}
