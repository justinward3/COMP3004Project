#include "addanimal.h"
#include "ui_addanimal.h"
#include "viewanimals.h"
#include "mainwindow.h"
#include "QMessageBox"

addAnimal::addAnimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAnimal)
{
    ui->setupUi(this);
}

//Deconstructor
addAnimal::~addAnimal()
{
    delete ui;
}

//set shelter pointer
void addAnimal::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

//command handler for back button
void addAnimal::on_backButton_clicked()
{
    this->hide();
    viewAnimals animalView;
    animalView.setShelter(sh);
    animalView.setModal(true);
    animalView.exec();
}

//command handler for add button
void addAnimal::on_addButton_clicked()
{
    //local vars for instantiation of new Animal
    QString name = ui->animalName->text();
    QString type = ui->animalType->currentText();
    QString ageStr = ui->animalAge->text();
    int age = ui->animalAge->text().toInt();
    QString sex = ui->animalSex->currentText();
    QString colour = ui->animalColour->text();
    QString detail = ui->animalDetail->text();
    //Check fields have value
    if (name!="" && ageStr!="" && colour!="" && sex!="" && colour!="" && detail!="") {
        //Create animal based on type
        if(type == "Dog"){
            animal = new Dog(name,colour,age,sex[0],detail);
        }
        else if(type == "Cat"){
            animal = new Cat(name,colour,age,sex[0],detail);
        }
        else if(type == "Bird"){
            animal = new Bird(name,colour,age,sex[0],detail);
        }
        else if(type == "Small Animal"){
            animal = new SmallAnimal(name,colour,age,sex[0],detail);
        }
        //If successfully added to Shelter, pop a success message and go back
        if(sh->operator +=(animal)){
            QMessageBox::critical(0, "DB Status",animal->getName()+" added to DATABASE", QMessageBox::Ok);
            this->on_backButton_clicked();
        }
        else{
            //pop a failed message
            QMessageBox::critical(0, "DB Status","DATABASE FAILURE, please contact system admin", QMessageBox::Ok);
        }
    }
    else {
        //pop a message informing of invalid info
        QMessageBox::critical(0, "Add Animal","Invalid Info", QMessageBox::Ok);
    }

}
