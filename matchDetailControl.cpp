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
        ui->animalName->setText(a->getName());
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
}
