#include "addStaffControl.h"
#include "ui_addStaffView.h"
#include "animalListView.h"
#include "mainWindow.h"
#include "QMessageBox"

addStaffControl::addStaffControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addStaffView)
{
    ui->setupUi(this);
}

//Deconstructor
addStaffControl::~addStaffControl()
{
    delete ui;
}

//set shelter pointer
void addStaffControl::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

//set mw pointer
void addStaffControl::setMainWindow(MainWindow *main)
{
    mw = main;
}



//command handler for back button
void addStaffControl::on_backButton_clicked()
{
    this->hide();
    //this->deleteLater();
    staffWindow* windowStaff = new staffWindow();
    windowStaff->setShelter(sh);
    windowStaff->setMainWindow(mw);
    windowStaff->setModal(true);
    windowStaff->exec();
    //delete this;
}

//command handler for add button
void addStaffControl::on_addButton_clicked()
{
    cout<< "addStaffControl" << endl;
    //local vars for instantiation of new Animal
    QString Fname = ui->staffFName->text();
    QString Lname = ui->staffLName->text();
    QString Add = ui->staffAdd->text();
    QString PNum = ui->staffPNum->text();
    QString email = ui->staffEmail->text();
    //Check fields have value
    if (Fname!="" && Lname!="" && Add!="" && PNum!="" && email!="") {
        //Create staff
         staff = UserFactory::createStaff(Fname,Lname,Add,PNum,email);
        //If successfully added to Shelter, pop a success message and go back
        if(sh->operator +=(staff)){
            QMessageBox::information(0, "DB Status",staff->getFname()+" added to DATABASE", QMessageBox::Ok);
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
