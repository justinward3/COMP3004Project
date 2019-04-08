#include "matchDetailControl.h"
#include <QStandardItemModel>

matchDetailControl::matchDetailControl(QWidget *parent):
    QDialog(parent),
    ui(new Ui::matchDetailView)
{
    ui->setupUi(this);
}

matchDetailControl::~matchDetailControl()
{
    delete ui;
}
//set shelter pointer
void matchDetailControl::setShelter(Shelter* shelter_ptr){
    sh = shelter_ptr;
}

void matchDetailControl::setAnimal(Animal* animal){
    ui->animalName->setText(animal->getName());
    ui->animalSex->setText(animal->getSex());
    ui->animalAge->setText(QString::number(animal->getAge()));
    ui->animalColour->setText(animal->getColour());
    ui->animalDetail->setText(animal->getDetail());
    ui->animalCost->setText(QString::number((animal->getTraits())["cost"]));
    ui->animalTime->setText(QString::number((animal->getTraits())["time"]));
}

void matchDetailControl::setClient(Client* client){
    ui->clientName->setText(client->getFname() + " " + client->getLname());
}

//set mw pointer
void matchDetailControl::setMainWindow(MainWindow *main)
{
    mw = main;
}

//command handler for back button
void matchDetailControl::on_backButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(sh);
    staffWindow.setMainWindow(mw);
    staffWindow.setModal(true);
    staffWindow.exec();
}

void matchDetailControl::setMatch(Animal* a ,Client* c){
        setAnimal(a);
        setClient(c);

        QString t;
        QString wantedStr;

        int wanted = c->getMatchingPrefs()["type"];
        //Check subclass of animal and set type bind value
        if ( dynamic_cast<Dog*>( a ) )
           t = "Dog";

        else if ( dynamic_cast<Cat*>( a ) )
           t = "Cat";

        else if ( dynamic_cast<Bird*>( a ) )
           t = "Bird";

        else if ( dynamic_cast<SmallAnimal*>( a ) )
           t = "Small Animal";

        if (wanted == 1 )
           wantedStr =  "Dog";

        else if (wanted == 2)
           wantedStr =  "Cat";

        else if (wanted == 3)
           wantedStr =  "Bird";

        else if (wanted == 4)
           wantedStr = "Small Animal";

        ui->animalType->setText(wantedStr);
        ui->aType->setText(wantedStr);
}
