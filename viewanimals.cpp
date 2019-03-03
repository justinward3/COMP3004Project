#include "viewanimals.h"
#include "ui_viewanimals.h"
#include "staffwindow.h"
#include "addanimal.h"
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
}

viewAnimals::~viewAnimals()
{
    delete model;
    delete ui;
}
//set shelter pointer
void viewAnimals::setShelter(Shelter* shelter_ptr){
    //cout << "SetShelter"<<endl;
    sh = shelter_ptr;
    animals = sh->getAnimals();

    //Add animals to table
    for(size_t i=0; i< animals.size();i++){
        QList<QStandardItem*> newRow;
        QStandardItem* type;
        //get animal type and corresponding string
        if ( dynamic_cast<Dog*>( animals[i] ) )
           type = new QStandardItem(QString("Dog"));

        else if ( dynamic_cast<Cat*>( animals[i] ) )
           type = new QStandardItem(QString("Cat"));

        else if ( dynamic_cast<Bird*>( animals[i] ) )
           type = new QStandardItem(QString("Bird"));

        else if ( dynamic_cast<SmallAnimal*>( animals[i] ) )
           type = new QStandardItem(QString("Small Animal"));

        QStandardItem* name = new QStandardItem(QString(animals[i]->getName()));
        QStandardItem* age = new QStandardItem(QString(QString::number(animals[i]->getAge())));
        QStandardItem* colour = new QStandardItem(QString(animals[i]->getColour()));
        QStandardItem* sex = new QStandardItem(QString(QChar::fromLatin1(animals[i]->getSex().toLatin1())));
        QStandardItem* detail = new QStandardItem(QString(animals[i]->getDetail()));

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

//command handler for back button
void viewAnimals::on_backButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(sh);
    staffWindow.setModal(true);
    staffWindow.exec();
}

//command handler for add button
void viewAnimals::on_addButton_clicked()
{
    this->hide();
    addAnimal animalAdd;
    animalAdd.setShelter(sh);
    animalAdd.setModal(true);
    animalAdd.exec();
}



void viewAnimals::on_detailButton_clicked()
{
    QItemSelectionModel *select = ui->animalList->selectionModel();
    if(select->hasSelection()){
        cout<<"hasselection"<<endl;
        qDebug() << animals[select->currentIndex().row()]->getName();
        this->hide();
        addAnimal animalAdd;
        animalAdd.setView(1, animals[select->currentIndex().row()]);
        animalAdd.setShelter(sh);
        animalAdd.setModal(true);
        animalAdd.exec();
  }
}
