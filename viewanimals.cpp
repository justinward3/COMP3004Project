#include "viewanimals.h"
#include "ui_viewanimals.h"
#include "staffwindow.h"
#include "addanimal.h"
#include "viewanimal.h"
#include "mainwindow.h"
#include "Shelter.h"
#include <QStandardItemModel>

viewAnimals::viewAnimals(QWidget *parent):
    QDialog(parent),
    ui(new Ui::viewAnimals)
{
    ui->setupUi(this);
    //Set up table and ui
    QStringList headers;
    headers<<"Type"<<"Detail"<<"Name"<<"Age"<<"Colour"<<"Sex";
    //QStringListModel *model = new QStringListModel();
    model = new QStandardItemModel();
    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(headers);

    //Setup table
    ui->animalList->setModel(model);
    ui->animalList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->animalList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->animalList->setSelectionMode( QAbstractItemView::SingleSelection );
    ui->animalList->setSelectionBehavior(QAbstractItemView::SelectRows);
    userView = false;
}

viewAnimals::~viewAnimals()
{
    delete model;
    delete ui;
}
//set shelter pointer
void viewAnimals::setShelter(Shelter* shelter_ptr){
    sh = shelter_ptr;

    //Add sh->getAnimals() to table
    for(size_t i=0; i< (sh->getAnimals()).size();i++){
        QList<QStandardItem*> newRow;
        QStandardItem* type;
        //get animal type and corresponding string
        if ( dynamic_cast<Dog*>( sh->getAnimals()[i] ) )
           type = new QStandardItem(QString("Dog"));

        else if ( dynamic_cast<Cat*>( sh->getAnimals()[i] ) )
           type = new QStandardItem(QString("Cat"));

        else if ( dynamic_cast<Bird*>( sh->getAnimals()[i] ) )
           type = new QStandardItem(QString("Bird"));

        else if ( dynamic_cast<SmallAnimal*>( sh->getAnimals()[i] ) )
           type = new QStandardItem(QString("Small Animal"));

        QStandardItem* name = new QStandardItem(QString(sh->getAnimals()[i]->getName()));
        QStandardItem* age = new QStandardItem(QString(QString::number(sh->getAnimals()[i]->getAge())));
        QStandardItem* colour = new QStandardItem(QString(sh->getAnimals()[i]->getColour()));
        QStandardItem* sex = new QStandardItem(QString(QChar::fromLatin1(sh->getAnimals()[i]->getSex().toLatin1())));
        QStandardItem* detail = new QStandardItem(QString(sh->getAnimals()[i]->getDetail()));

        //Order matters here
        newRow.append(type);
        newRow.append(detail);
        newRow.append(name);
        newRow.append(age);
        newRow.append(colour);
        newRow.append(sex);
        //append to table
        model->appendRow(newRow);
    }

    ui->animalList->setModel(model);
}

//set mw pointer
void viewAnimals::setMainWindow(QMainWindow *main)
{
    mw = main;
}

//command handler for back button
void viewAnimals::on_backButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(sh);
    staffWindow.setMainWindow(mw);
    staffWindow.setModal(true);
    staffWindow.exec();
}

//command handler for add button
void viewAnimals::on_addButton_clicked()
{
    this->hide();
    addAnimal animalAdd;
    animalAdd.setShelter(sh);
    animalAdd.setMainWindow(mw);
    animalAdd.setModal(true);
    animalAdd.exec();
}

void viewAnimals::on_detailButton_clicked()
{
    QItemSelectionModel *select = ui->animalList->selectionModel();
    if(select->hasSelection()){
        this->hide();
        viewAnimal animalView;
        animalView.setAnimal(sh->getAnimals()[select->currentIndex().row()],select->currentIndex().row());
        animalView.setShelter(sh);
        if(userView){
            animalView.setUserView();
        }
        animalView.setMainWindow(mw);
        animalView.setModal(true);
        animalView.exec();
  }
}

void viewAnimals::setUserView(){
    ui->addButton->setVisible(false);
    userView = true;
}
