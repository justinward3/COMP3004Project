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

void matchDetailControl::setClient(Client* client){
    ui->clientName->setText(client->getFname() + " " + client->getLname());

    // size, space
    QStringList sml = {"Small", "Medium", "Large"};
    // experienxe
    QStringList experience = {"Inexperienced", "Moderately experienced", "Well experienced"};
    // cost
    QStringList cost = {"$200 or less", "$200-$500", "$500-$750", "$750-$1000", "$1000 or more"};
    // time
    QStringList time = {"Less than 1 hour", "1-2 hours", "2-3 hours", "3+ hours"};
    // younger, older
    QStringList yo = {"Older", "Younger"};
    // lifespan
    QStringList lifespan = {"1-2", "3-5", "6-10", "10+"};
    // noise
    QStringList noise = {"Minimal", "N/A"};
    // home
    QStringList home = {"Apartment", "House"};
    // active
    QStringList active = {"Not","Somewhate","Moderately","Heavily"};
    // affection
    QStringList affection = {"Little", "Moderate", "Lots"};
    // obedient
    QStringList obedient = {"Untrained", "Somewhat trained", "Trained"};
    // shedding
    QStringList shedding = {"Little", "Moderate", "Lots"};
    // colour
    QStringList colour = {"Brown", "Black", "Golden", "Orange", "White", "Grey", "Multi"};
    // male, female
    QStringList mf = {"M", "F"};
    // yes, no
    QStringList yn = {"Yes", "No"};

    ui->aSize->setText(sml[client->getMatchingPrefs()["size"]-1]);
    ui->aSpace->setText(sml[client->getMatchingPrefs()["space"]-1]);
    ui->aExperience->setText(experience[client->getMatchingPrefs()["experience"]-1]);
    ui->aCost->setText(cost[client->getMatchingPrefs()["cost"]-1]);
    ui->aTime->setText(time[client->getMatchingPrefs()["time"]-1]);
    ui->aAge->setText(yo[client->getMatchingPrefs()["age"]-1]);
    ui->aOlder->setText(yn[client->getMatchingPrefs()["older"]-1]);
    ui->aLifespan->setText((lifespan[client->getMatchingPrefs()["lifespan"]-1]) + " years");
    ui->aNoise->setText(noise[client->getMatchingPrefs()["noise"]-1]);
    ui->aHome->setText(home[client->getMatchingPrefs()["home"]-1]);
    ui->aActive->setText(active[client->getMatchingPrefs()["active"]-1]);
    ui->aAffection->setText(affection[client->getMatchingPrefs()["affection"]-1]);
    ui->aObedient->setText(obedient[client->getMatchingPrefs()["obedient"]-1]);
    ui->aShedding->setText(shedding[client->getMatchingPrefs()["shedding"]-1]);
    ui->aColour->setText(colour[client->getMatchingPrefs()["colour"]-1]);
    ui->aSex->setText(mf[client->getMatchingPrefs()["sex"]-1]);
    ui->aDogs->setText(yn[client->getMatchingPrefs()["dogs"]-1]);
    ui->aDogsFuture->setText(yn[client->getMatchingPrefs()["dogsfuture"]-1]);
    ui->aCats->setText(yn[client->getMatchingPrefs()["cats"]-1]);
    ui->aCatsFuture->setText(yn[client->getMatchingPrefs()["catsfuture"]-1]);
    ui->aChildren->setText(yn[client->getMatchingPrefs()["children"]-1]);
    ui->aChildrenFuture->setText(yn[client->getMatchingPrefs()["childrenfuture"]-1]);
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

        ACMAlgorithm acm;
        int score = acm.runACMOnPair(a,c);
        ui->score->setText(QString::number(score));

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
