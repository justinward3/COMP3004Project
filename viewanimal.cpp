#include "viewanimal.h"
#include "ui_addanimal.h"
#include "viewanimals.h"
#include "mainwindow.h"
#include "QMessageBox"
#include <QPushButton>
#include <QButtonGroup>
#include <QString>
#include "addanimal.h"

viewAnimal::viewAnimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAnimal)
{
    ui->setupUi(this);
    //disable buttons and fields
    ui->editButton->setVisible(false);
    ui->saveButton->setEnabled(false);
    ui->animalName->setEnabled(false);
    ui->animalSex->setEnabled(false);
    ui->animalAge->setEnabled(false);
    ui->animalColour->setEnabled(false);
    ui->animalDetail->setEnabled(false);
    ui->animalDifficulty->setEnabled(false);
    ui->animalAffection->setEnabled(false);
    ui->animalCost->setEnabled(false);
    ui->animalTime->setEnabled(false);
    ui->animalSpace->setEnabled(false);
    ui->animalLoudness->setEnabled(false);
    ui->animalActiveness->setEnabled(false);
    ui->animalObedience->setEnabled(false);
    ui->animalShedding->setEnabled(false);
    ui->animalLifespan->setEnabled(false);
    ui->animalType->setEnabled(false);
    ui->dogCheckBox->setEnabled(false);
    ui->catCheckBox->setEnabled(false);
    ui->childCheckBox->setEnabled(false);
}

//Deconstructor
viewAnimal::~viewAnimal()
{
    delete ui;
}

//set shelter pointer
void viewAnimal::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

//Set main window pointer
void viewAnimal::setMainWindow(QMainWindow* main){
    mw = main;
}

//set view
void viewAnimal::setAnimal(Animal *a, int i)
{
        animal = a;
        pos = i;
        //Populate all fields for view/edit
        ui->label->setText("View Animal");
        ui->addButton->setVisible(false);
        ui->editButton->setVisible(true);
        ui->animalName->setText(animal->getName());
        ui->animalSex->setCurrentText(animal->getSex());
        ui->animalAge->setText(QString::number(animal->getAge()));
        ui->animalColour->setText(animal->getColour());
        ui->animalDetail->setText(animal->getDetail());
        ui->animalDifficulty->setCurrentIndex((animal->getTraits())["DoC"]-1);
        ui->animalAffection->setCurrentIndex((animal->getTraits())["affection"]-1);
        ui->animalCost->setText(QString::number((animal->getTraits())["cost"]));
        ui->animalTime->setText(QString::number((animal->getTraits())["time"]));
        ui->animalSpace->setCurrentIndex((animal->getTraits())["space"]-1);
        ui->animalLoudness->setCurrentIndex((animal->getTraits())["loudness"]-1);
        ui->animalActiveness->setCurrentIndex((animal->getTraits())["activeness"]-1);
        ui->animalObedience->setCurrentIndex((animal->getTraits())["obedience"]-1);
        ui->animalShedding->setCurrentIndex((animal->getTraits())["shedding"]-1);
        ui->animalLifespan->setText(QString::number((animal->getTraits())["lifespan"]));

        if (animal->getTraits()["intwithdog"] == 0){
          ui->dogCheckBox->setChecked(1);
        }else{
          ui->dogCheckBox->setChecked(0);
        }
        if (animal->getTraits()["intwithcat"] == 0){
          ui->catCheckBox->setChecked(1);
        }else{
          ui->catCheckBox->setChecked(0);
        }
        if (animal->getTraits()["intwithchild"] == 0){
          ui->childCheckBox->setChecked(1);
        }else{
          ui->childCheckBox->setChecked(0);
        }

}

//command handler for back button
void viewAnimal::on_backButton_clicked()
{
    this->hide();
    viewAnimals animalView;
    animalView.setShelter(sh);
    animalView.setMainWindow(mw);
    animalView.setModal(true);
    animalView.exec();
}

void viewAnimal::on_editButton_clicked()
{
    this->hide();
    addAnimal animalAdd;
    animalAdd.setShelter(sh);
    animalAdd.edit(animal,pos);
    animalAdd.setMainWindow(mw);
    animalAdd.setModal(true);
    animalAdd.exec();
}


void viewAnimal::on_saveButton_clicked()
{
//do nothing
}
