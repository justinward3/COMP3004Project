#include "clientEditControl.h"
#include "ui_clientDetailView.h"
#include "animalListControl.h"
#include "mainWindow.h"
#include "QMessageBox"

clientEditControl::clientEditControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::clientDetailView)
{
    ui->setupUi(this);
    ui->editButton->setVisible(false);
    ui->clientMatchingInfo->setVisible(false);
    clientView = true;
    ui->label->setText("Edit Profile");
    ui->clientMatchingInfo->setVisible(true);
    ui->addButton->setVisible(false);
    ui->editButton->setVisible(false);
    ui->saveButton->setEnabled(true);
    //ui->label_6->setVisible(false);
    this->setWindowTitle("Edit Profile");
}

//Deconstructor
clientEditControl::~clientEditControl()
{
    delete ui;
}

//set shelter pointer
void clientEditControl::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

void clientEditControl::edit(Client *c){
    client = c;
    ui->clientFName->setText(client->getFname());
    ui->clientLName->setText(client->getLname());
    ui->clientEmail->setText(client->getEmail());
    ui->clientPNum->setText(client->getPhoneNumber());
    ui->clientAdd->setText(client->getAddress());
    if(client->getMatchingPrefs().isEmpty()){
        qDebug()<<"No MP";
    }
    else{
        QStringList keys = {"type","active","affection","age","cats","catsfuture","children","childrenfuture","colour","cost","dogs","dogsfuture","experience","home","lifespan","noise","obedient","older","sex","shedding","size","space","time"};
        //prepare Sql Query to load Client Data
        //populate matching prefs also
        qDebug()<<client->getMatchingPrefs();
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

void clientEditControl::on_saveButton_clicked()
{
        QStringList keys = {"type","active","affection","age","cats","catsfuture","children","childrenfuture","colour","cost","dogs","dogsfuture","experience","home","lifespan","noise","obedient","older","sex","shedding","size","space","time"};
        qDebug()<<"We in trouble now boys!";
        QString newname = ui->clientFName->text();
        QString newLname = ui->clientLName->text();
        QString newEmail = ui->clientEmail->text();
        QString newPNum = ui->clientPNum->text();
        QString newAdd = ui->clientAdd->text();
        QMap<QString,int> temp;
        temp.insert(keys[0],ui->aType->currentIndex()+1);
        temp.insert(keys[1],ui->aActive->currentIndex()+1);
        temp.insert(keys[2],ui->aAffection->currentIndex()+1);
        temp.insert(keys[3],ui->aAge->currentIndex()+1);
        temp.insert(keys[4],ui->aCats->currentIndex()+1);
        temp.insert(keys[5],ui->aCatsFuture->currentIndex()+1);
        temp.insert(keys[6],ui->aChildren->currentIndex()+1);
        temp.insert(keys[7],ui->aChildrenFuture->currentIndex()+1);
        temp.insert(keys[8],ui->aColour->currentIndex()+1);
        temp.insert(keys[9],ui->aCost->currentIndex()+1);
        temp.insert(keys[10],ui->aDogs->currentIndex()+1);
        temp.insert(keys[11],ui->aDogsFuture->currentIndex()+1);
        temp.insert(keys[12],ui->aExperience->currentIndex()+1);
        temp.insert(keys[13],ui->aHome->currentIndex()+1);
        temp.insert(keys[14],ui->aLifespan->currentIndex()+1);
        temp.insert(keys[15],ui->aNoise->currentIndex()+1);
        temp.insert(keys[16],ui->aObedient->currentIndex()+1);
        temp.insert(keys[17],ui->aOlder->currentIndex()+1);
        temp.insert(keys[18],ui->aSex->currentIndex()+1);
        temp.insert(keys[19],ui->aShedding->currentIndex()+1);
        temp.insert(keys[20],ui->aSize->currentIndex()+1);
        temp.insert(keys[21],ui->aSpace->currentIndex()+1);
        temp.insert(keys[22],ui->aTime->currentIndex()+1);
        qDebug()<<temp;
        int retstatus;
        retstatus = sh->update(client,new Client(newname,newLname,newAdd,newPNum,newEmail,temp));
        if(retstatus == 1){
            mw->updateCurrUserName(newEmail);
            QMessageBox::information(0, "DB Status","Profile updated in DATABASE", QMessageBox::Ok);
            this->on_backButton_clicked();
        }
        else if(retstatus == 0){
            //pop a failed message
            QMessageBox::critical(0, "DB Status","DATABASE FAILURE, please exit and contact system admin", QMessageBox::Ok);
        }
        else if(retstatus == -1){
            //pop a failed message
            QMessageBox::critical(0, "Profile Error","Email in use, please try again!", QMessageBox::Ok);
        }
}

//set mainwindow pointer
void clientEditControl::setMainWindow(MainWindow *main){
    mw = main;
}

//command handler for back button
void clientEditControl::on_backButton_clicked()
{
    this->hide();
        clientWindow clientWindow;
        clientWindow.setShelter(sh);
        clientWindow.setMainWindow(mw);
        clientWindow.setModal(true);
        clientWindow.exec();
}
