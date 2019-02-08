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
    QStringList headers;
    headers<<"Type"<<"Detail"<<"Name"<<"Age"<<"Colour"<<"Sex";
    //QStringListModel *model = new QStringListModel();
    model = new QStandardItemModel();
    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(headers);
    ui->animalList->setModel(model);
    ui->animalList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->animalList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //sh = shelter;

    //cout << QApplication::topLevelWidgets() <<endl;
            //MainWindow conn;
    //Shelter shelter;
    /*
    conn.db.open();

    if (!conn.db.open()) {
        printf("DATABASE ERROR\n");
    }
    else {
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery(conn.shelter->loadAnimals(conn.db));
        ui->animalList->setModel(model);
    }
    */
    //This is ideally how the UI should call the shelter to display the animals
    //ui->animalList->setModel(QList<Animal>::fromVector(sh->getAnimals());
    //QApplication.
}

viewAnimals::~viewAnimals()
{
    delete model;
    delete ui;
}
void viewAnimals::setShelter(Shelter* shelter_ptr){
    cout << "SetShelter"<<endl;
    sh = shelter_ptr;
    vector<Animal*> animals = sh->getAnimals();
    for(int i=0; i< animals.size();i++){
        QList<QStandardItem*> newRow;
        QStandardItem* type;
        if ( dynamic_cast<Dog*>( animals[i] ) )
           type = new QStandardItem(QString("Dog"));

        else if ( dynamic_cast<Cat*>( animals[i] ) )
           type = new QStandardItem(QString("Cat"));

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
        model->appendRow(newRow);
    }

    ui->animalList->setModel(model);
}
void viewAnimals::on_backButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(sh);
    staffWindow.setModal(true);
    staffWindow.exec();
}

void viewAnimals::on_addButton_clicked()
{
    /*this->hide();
    addAnimal addAnimal;
    addAnimal.setShelter(sh);
    addAnimal.setModal(true);
    addAnimal.exec();
    */
    this->hide();
    addAnimal* animalAdd = new addAnimal();
    animalAdd->setShelter(sh);
    animalAdd->setModal(true);
    animalAdd->deleteLater();
    animalAdd->exec();
}

