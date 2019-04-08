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
    ui->animalLifespan->setText(QString::number(animal->getTraits()["lifespan"]));
    ui->animalColour->setText(animal->getColour());
    ui->animalDetail->setText(animal->getDetail());
    ui->animalCost->setText(QString::number((animal->getTraits())["cost"]));
    ui->animalTime->setText((QString::number((animal->getTraits())["time"])) + " hrs.");

    // difficulty
    QStringList docList = {"Easy", "Intermediate", "Difficult"};
    // loudness, activeness, shedding
    QStringList nlmlList= {"None","Little","Moderate","Lots"};
    // space, affection
    QStringList lmlList= {"Little", "Moderate", "Lots"};
    // obedience
    QStringList obedience = {"Untrained", "Somewhat trained", "Trained"};

    ui->animalDifficulty->setText(docList[animal->getTraits()["DoC"]-1]);
    ui->animalLoudness->setText(nlmlList[animal->getTraits()["loudness"]-1]);
    ui->animalActiveness->setText(nlmlList[animal->getTraits()["activeness"]-1]);
    ui->animalShedding->setText(nlmlList[animal->getTraits()["shedding"]-1]);
    ui->animalSpace->setText((lmlList[animal->getTraits()["space"]-1]) + " space");
    ui->animalAffection->setText(lmlList[animal->getTraits()["affection"]-1]);
    ui->animalObedience->setText(docList[animal->getTraits()["obedience"]-1]);
}

void matchDetailControl::setClient(Client* client){
    ui->clientName->setText(client->getFname() + " " + client->getLname());
    //ui->aAge->setText(QString::number(client->getMatchingPrefs()["age"]));
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

        ui->animalType->setText(t);
        ui->aType->setText(wantedStr);
}
