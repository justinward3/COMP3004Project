#include "animalViewControl.h"
#include "animalListControl.h"
#include "mainWindow.h"
#include "QMessageBox"
#include <QPushButton>
#include <QButtonGroup>
#include <QString>
#include "animalAddEditControl.h"

animalViewControl::animalViewControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animalDetailView)
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
    clientView = false;
}

//Deconstructor
animalViewControl::~animalViewControl()
{
    delete ui;
}

//set shelter pointer
void animalViewControl::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

//Set main window pointer
void animalViewControl::setMainWindow(MainWindow* main){
    mw = main;
}

//set view
void animalViewControl::setAnimal(Animal *a, int i)
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

        //Check subclass of animal and set type
        if ( dynamic_cast<Dog*>( a ) )
           ui->animalType->setCurrentIndex(0);

        else if ( dynamic_cast<Cat*>( a ) )
           ui->animalType->setCurrentIndex(1);

        else if ( dynamic_cast<Bird*>( a ) )
           ui->animalType->setCurrentIndex(2);

        else if ( dynamic_cast<SmallAnimal*>( a ) )
           ui->animalType->setCurrentIndex(3);

        //Integration Checkboxes
        if (animal->getTraits()["intwithdog"] == 1){
          ui->dogCheckBox->setChecked(1);
        }else{
          ui->dogCheckBox->setChecked(0);
        }
        if (animal->getTraits()["intwithcat"] == 1){
          ui->catCheckBox->setChecked(1);
        }else{
          ui->catCheckBox->setChecked(0);
        }
        if (animal->getTraits()["intwithchild"] == 1){
          ui->childCheckBox->setChecked(1);
        }else{
          ui->childCheckBox->setChecked(0);
        }

}

//command handler for back button
void animalViewControl::on_backButton_clicked()
{
    this->hide();
    animalListControl animalView;
    animalView.setShelter(sh);
    animalView.setMainWindow(mw);
    if(clientView){
        animalView.setUserView();
    }
    animalView.setModal(true);
    animalView.exec();
}

void animalViewControl::on_editButton_clicked()
{
    this->hide();
    animalAddEditControl animalAdd;
    animalAdd.setShelter(sh);
    animalAdd.edit(animal,pos);
    animalAdd.setMainWindow(mw);
    animalAdd.setModal(true);
    animalAdd.exec();
}

void animalViewControl::on_saveButton_clicked()
{
//do nothing
}

void animalViewControl::setUserView(){
    ui->editButton->setVisible(false);
    ui->saveButton->setVisible(false);
    clientView = true;
}
