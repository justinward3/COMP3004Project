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

addAnimal::~addAnimal()
{
    delete ui;
}

void addAnimal::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

void addAnimal::on_backButton_clicked()
{
    this->hide();
    viewAnimals animalView;
    animalView.setShelter(sh);
    animalView.setModal(true);
    animalView.exec();
}

void addAnimal::on_addButton_clicked()
{
    QString name = ui->animalName->text();
    QString type = ui->animalType->currentText();
    QString ageStr = ui->animalAge->text();
    int age = ui->animalAge->text().toInt();
    QString sex = ui->animalSex->currentText();
    QString colour = ui->animalColour->text();
    QString detail = ui->animalDetail->text();
    if (name!="" && ageStr!="" && colour!="" && sex!="" && colour!="" && detail!="") {
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
        sh->operator +=(animal);
    }
    else {
        QMessageBox::critical(0, "Add Animal","Invalid Info", QMessageBox::Ok);
    }

}
