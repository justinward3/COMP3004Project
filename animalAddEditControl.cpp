#include "animalAddEditControl.h"
#include "ui_animalDetailView.h"
#include "animalListControl.h"
#include "mainWindow.h"
#include "QMessageBox"
#include <QPushButton>
#include <QButtonGroup>
#include <QString>

animalAddEditControl::animalAddEditControl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::animalDetailView)
{
    ui->setupUi(this);
    ui->editButton->setVisible(false);
    ui->saveButton->setVisible(false);
}

//Deconstructor
animalAddEditControl::~animalAddEditControl()
{
    delete ui;
}

//set view
void animalAddEditControl::edit(Animal *a, int i)
{
        this->setWindowTitle("Edit Animal");
        animal = a;
        pos = i;
        //Populate all fields for view/edit
        ui->label->setText("Edit Animal");
        ui->addButton->setVisible(false);
        ui->editButton->setVisible(false);
        ui->saveButton->setVisible(true);
        ui->animalName->setText(animal->getName());
        ui->animalSex->setCurrentText(animal->getSex());
        ui->animalAge->setText(QString::number(animal->getAge()));
        ui->animalColour->setText(animal->getColour());
        ui->animalDetail->setText(animal->getDetail());
        ui->animalSize->setCurrentIndex((animal->getTraits())["size"]-1);
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


//set shelter pointer
void animalAddEditControl::setShelter(Shelter *shelter_ptr)
{
    sh = shelter_ptr;
}

//Set main window pointer
void animalAddEditControl::setMainWindow(MainWindow* main){
    mw = main;
}

//command handler for back button
void animalAddEditControl::on_backButton_clicked()
{
    this->hide();
    animalListControl animalView;
    animalView.setShelter(sh);
    animalView.setMainWindow(mw);
    animalView.setModal(true);
    animalView.exec();
}

void animalAddEditControl::on_saveButton_clicked()
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
    qDebug()<<"Lifespan"<<lifespan;
    int cost = ui->animalCost->text().toInt();
    float time = ui->animalTime->text().toFloat();
    QString costStr = ui->animalCost->text();
    QString timeStr = ui->animalTime->text();
    QString lifespanStr = ui->animalLifespan->text();
    int intwithdog = 0;
    if (ui->dogCheckBox->isChecked()){
      intwithdog = 1;
    }
    int intwithcat = 0;
    if (ui->catCheckBox->isChecked()){
      intwithcat = 1;
    }
    int intwithchild = 0;
    if (ui->childCheckBox->isChecked()){
      intwithchild = 1;
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
        attr.insert("DoC", (ui->animalDifficulty->currentIndex()+1));
        attr.insert("affection", (ui->animalAffection->currentIndex()+1));
        attr.insert("cost", cost);
        attr.insert("time", time);
        attr.insert("size",(ui->animalSize->currentIndex()+1));
        attr.insert("space", (ui->animalSpace->currentIndex()+1));
        attr.insert("loudness", (ui->animalLoudness->currentIndex()+1));
        attr.insert("activeness", (ui->animalActiveness->currentIndex()+1));
        attr.insert("obedience", (ui->animalObedience->currentIndex()+1));
        attr.insert("shedding", (ui->animalShedding->currentIndex()+1));
        attr.insert("lifespan", lifespan);
        attr.insert("intwithdog", intwithdog);
        attr.insert("intwithcat", intwithcat);
        attr.insert("intwithchild", intwithchild);
        if(sh->update(animal,type,name,colour,age,sex[0],detail,attr,pos)){

                QMessageBox::information(0, "DB Status","Animal updated in DATABASE", QMessageBox::Ok);
                this->on_backButton_clicked();
            }
            else{
                //pop a failed message
                QMessageBox::critical(0, "DB Status","DATABASE FAILURE, please contact system admin", QMessageBox::Ok);
            }
    }
}

// enable/disable fields on screen
void animalAddEditControl::animalAddEditControlFields(bool flag) {
    ui->animalName->setEnabled(flag);
    ui->animalSex->setEnabled(flag);
    ui->animalSize->setEnabled(flag);
    ui->animalAge->setEnabled(flag);
    ui->animalColour->setEnabled(flag);
    ui->animalDetail->setEnabled(flag);
    ui->animalDifficulty->setEnabled(flag);
    ui->animalAffection->setEnabled(flag);
    ui->animalCost->setEnabled(flag);
    ui->animalTime->setEnabled(flag);
    ui->animalSpace->setEnabled(flag);
    ui->animalLoudness->setEnabled(flag);
    ui->animalActiveness->setEnabled(flag);
    ui->animalObedience->setEnabled(flag);
    ui->animalShedding->setEnabled(flag);
    ui->animalLifespan->setEnabled(flag);
    ui->animalType->setEnabled(flag);
    ui->dogCheckBox->setEnabled(flag);
    ui->catCheckBox->setEnabled(flag);
    ui->childCheckBox->setEnabled(flag);
}

//command handler for add button
void animalAddEditControl::on_addButton_clicked()
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
        attr.insert("DoC", (ui->animalDifficulty->currentIndex()+1));
        attr.insert("affection", (ui->animalAffection->currentIndex()+1));
        attr.insert("cost", cost);
        attr.insert("time", time);
        attr.insert("size", (ui->animalSize->currentIndex()+1));
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

        int newAnimalId = sh->getLastId();
        newAnimalId++;
        //Create animal based on type
        if(type == "Dog"){
            animal = AnimalFactory::createDog(name,colour,age,sex[0],detail,attr,newAnimalId);
        }
        else if(type == "Cat"){
            animal = AnimalFactory::createCat(name,colour,age,sex[0],detail,attr,newAnimalId);
        }
        else if(type == "Bird"){
            animal = AnimalFactory::createBird(name,colour,age,sex[0],detail,attr,newAnimalId);
        }
        else if(type == "Small Animal"){
            animal = AnimalFactory::createSmallAnimal(name,colour,age,sex[0],detail,attr,newAnimalId);
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
