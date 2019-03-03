#include "addanimal.h"
#include "ui_addanimal.h"
#include "viewanimals.h"
#include "mainwindow.h"
#include "QMessageBox"
#include <QPushButton>
#include <QButtonGroup>
#include <QString>

addAnimal::addAnimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAnimal)
{
    ui->setupUi(this);
    ui->saveButton->setVisible(false);
}

//Deconstructor
addAnimal::~addAnimal()
{
    delete ui;
}

//set view
void addAnimal::setView(int view, Animal *animal)
{
    //view = 1, then this view will be used for edit
    if (view == 1) {
        //Populate all fields for view/edit
        ui->label->setText("Edit Animal");
        ui->addButton->setVisible(false);
        ui->saveButton->setVisible(true);
        ui->animalName->setText(animal->getName());
        ui->animalSex->setCurrentText(animal->getSex());
        QString s = QString::number(animal->getAge());
        ui->animalAge->setText(s);
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
        cout << "CAT: " << animal->getTraits()["intwithcat"] << endl;
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
    QString sex = ui->animalSex->currentText();
    QString colour = ui->animalColour->text();
    QString detail = ui->animalDetail->text();
    QMap<QString,int> attr;
    QString ageStr = ui->animalAge->text();
    int age = ui->animalAge->text().toInt();
    int lifespan = ui->animalLifespan->text().toInt();
    int cost = ui->animalCost->text().toInt();
    float time = ui->animalTime->text().toFloat();
    QString costStr = ui->animalCost->text();
    QString timeStr = ui->animalTime->text();
    QString lifespanStr = ui->animalLifespan->text();
    int intwithdog = 1;
    if (ui->dogCheckBox->isChecked()){
      intwithdog = 0;
    }
    int intwithcat = 1;
    if (ui->catCheckBox->isChecked()){
      intwithcat = 0;
    }
    int intwithchild = 1;
    if (ui->childCheckBox->isChecked()){
      intwithchild = 0;
    }
    /*
    QString space = ui->animalSpace->currentText();
    QString loudness = ui->animalLoudness->currentText();
    QString activeness = ui->animalActiveness->currentText();
    QString obedience = ui->animalObedience->currentText();
    QString shedding = ui->animalShedding->currentText();
    QString difficulty = ui->animalDifficulty->currentText();
    QString affection = ui->animalAffection->currentText();
    */

    //Check fields have value
    if (name!="" && ageStr!="" && colour!="" && sex!="" && colour!="" && detail!=""
            && lifespanStr!="" && costStr!="" && timeStr!="") {

        //Populate Matching parameter dictionary
        attr.insert("doc", (ui->animalDifficulty->currentIndex()+1));
        attr.insert("affection", (ui->animalAffection->currentIndex()+1));
        attr.insert("cost", cost);
        attr.insert("time", time);
        attr.insert("space", (ui->animalSpace->currentIndex()+1));
        attr.insert("loudness", (ui->animalLoudness->currentIndex()+1));
        attr.insert("activeness", (ui->animalActiveness->currentIndex()+1));
        attr.insert("obedience", (ui->animalObedience->currentIndex()+1));
        attr.insert("shedding", (ui->animalShedding->currentIndex()+1));
        attr.insert("lifespan", lifespan);
        attr.insert("intwithdog", intwithdog);
        attr.insert("intwithcat", intwithcat);
        attr.insert("intwithchild", intwithchild);

        qDebug() << "DoC: " << attr["doc"] << "\nAffection: " << attr["affection"] << "\nACost: " << attr["cost"]
            << "\nTime: " << attr["time"] << "\nSpace: " << attr["space"] << "\nLoudness: " << attr["loudness"]
            << "\nActiveness: " << attr["activeness"] << "\nObedience: " << attr["obedience"]
            << "\nShedding: " << attr["shedding"] << "\nLifespan: " << attr["lifespan"] << endl;

        //Create animal based on type
        if(type == "Dog"){
            animal = new Dog(name,colour,age,sex[0],detail,attr);
        }
        else if(type == "Cat"){
            animal = new Cat(name,colour,age,sex[0],detail,attr);
        }
        else if(type == "Bird"){
            animal = new Bird(name,colour,age,sex[0],detail,attr);
        }
        else if(type == "Small Animal"){
            animal = new SmallAnimal(name,colour,age,sex[0],detail,attr);
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
