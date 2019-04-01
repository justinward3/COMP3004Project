#include "clientAddViewControl.h"
#include "animalListControl.h"
#include "mainWindow.h"
#include "QMessageBox"

clientAddViewControl::clientAddViewControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientDetailView)
{
    ui->setupUi(this);
    ui->editButton->setVisible(false);
}

//Deconstructor
clientAddViewControl::~clientAddViewControl()
{
    delete ui;
}

//set view
void clientAddViewControl::setView(int view, Client *client)
{
    //view = 1, then this view will be used for view
    if (view == 1) {
        ui->label->setText("View Client");
        ui->addButton->setVisible(false);
        this->setWindowTitle("View Client");
        ui->label_6->setVisible(false);
        ui->saveButton->setVisible(false);
        addClientFields(false);
        ui->clientFName->setText(client->getFname());
        ui->clientLName->setText(client->getLname());
        ui->clientEmail->setText(client->getEmail());
        ui->clientPNum->setText(client->getPhoneNumber());
        ui->clientAdd->setText(client->getAddress());
        if(client->getMatchingPrefs().isEmpty()){
            qDebug()<<"No MP";
            ui->clientMatchingInfo->setVisible(false);
        }
        else{
            ui->clientMatchingInfo->setVisible(true);
            QStringList keys = {"type","active","affection","age","cats","catsfuture","children","childrenfuture","colour","cost","dogs","dogsfuture","experience","home","lifespan","noise","obedient","older","sex","shedding","size","space","time"};
            //populate matching prefs
            QMap<QString,int> temp = client->getMatchingPrefs();
            ui->aType->setCurrentIndex(temp[keys[0]]-1);
            ui->aActive->setCurrentIndex(temp[keys[1]]-1);
            ui->aAffection->setCurrentIndex(temp[keys[2]]-1);
            ui->aAge->setCurrentIndex(temp[keys[3]]-1);
            ui->aCats->setCurrentIndex(temp[keys[4]]-1);
            ui->aCatsFuture->setCurrentIndex(temp[keys[5]]-1);
            ui->aChildren->setCurrentIndex(temp[keys[6]]-1);
            ui->aChildrenFuture->setCurrentIndex(temp[keys[7]]-1);
            ui->aColour->setCurrentIndex(temp[keys[8]]-1);
            ui->aCost->setCurrentIndex(temp[keys[9]]-1);
            ui->aDogs->setCurrentIndex(temp[keys[10]]-1);
            ui->aDogsFuture->setCurrentIndex(temp[keys[11]]-1);
            ui->aExperience->setCurrentIndex(temp[keys[12]]-1);
            ui->aHome->setCurrentIndex(temp[keys[13]]-1);
            ui->aLifespan->setCurrentIndex(temp[keys[13]]-1);
            ui->aNoise->setCurrentIndex(temp[keys[14]]-1);
            ui->aObedient->setCurrentIndex(temp[keys[14]]-1);
            ui->aOlder->setCurrentIndex(temp[keys[15]]-1);
            ui->aSex->setCurrentIndex(temp[keys[16]]-1);
            ui->aShedding->setCurrentIndex(temp[keys[17]]-1);
            ui->aSize->setCurrentIndex(temp[keys[18]]-1);
            ui->aSpace->setCurrentIndex(temp[keys[19]]-1);
            ui->aTime->setCurrentIndex(temp[keys[20]]-1);
        }
    }
}


// enable/disable fields
void clientAddViewControl::addClientFields(bool flag) {
    ui->clientFName->setEnabled(flag);
    ui->clientLName->setEnabled(flag);
    ui->clientEmail->setEnabled(flag);
    ui->clientPNum->setEnabled(flag);
    ui->clientAdd->setEnabled(flag);
    ui->clientMatchingInfo->setEnabled(flag);
}

//set shelter pointer
void clientAddViewControl::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

//set mainwindow pointer
void clientAddViewControl::setMainWindow(MainWindow *main){
    mw = main;
}

//command handler for back button
void clientAddViewControl::on_backButton_clicked()
{
    this->hide();
    clientListControl clientListControl;
    clientListControl.setShelter(sh);
    clientListControl.setMainWindow(mw);
    clientListControl.setModal(true);
    clientListControl.exec();

}

//command handler for add button
void clientAddViewControl::on_addButton_clicked()
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
         client = UserFactory::createClient(Fname,Lname,Add,PNum,email);
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
