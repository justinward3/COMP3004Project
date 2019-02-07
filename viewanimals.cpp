#include "viewanimals.h"
#include "ui_viewanimals.h"
#include "staffwindow.h"
#include "addanimal.h"
#include "mainwindow.h"
#include "Shelter.h"

viewAnimals::viewAnimals(QWidget *parent):
    QDialog(parent),
    ui(new Ui::viewAnimals)
{
    ui->setupUi(this);
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
    delete ui;
}
void viewAnimals::setShelter(Shelter* shelter_ptr){
    cout << "SetShelter"<<endl;
    sh = shelter_ptr;
    //ui->animalList->setModel(QList<Animal>::fromVector(sh->getAnimals());
    //cout << sh->getAnimals() <<endl;
    vector<Animal*> animals = sh->getAnimals();
    //QList<QString> temp = new QList<QString>();
    for(int i=0; i< animals.size();i++){
        cout<<"loop"<<endl;
        cout<<animals[i]->getName().toUtf8().constData()<<endl;
        //temp.append(animals[i]->getName());
    }
    //QStringListModel *model = new QStringListModel();
    //model->setStringList(temp);
    //ui->animalList->setModel(model);
}
void viewAnimals::on_backButton_clicked()
{
    MainWindow conn;
    conn.db.close();
    conn.db.removeDatabase(QSqlDatabase::defaultConnection);
    this->hide();
    staffWindow staffWindow;
    staffWindow.setModal(true);
    staffWindow.exec();
}

void viewAnimals::on_addButton_clicked()
{
    MainWindow conn;
    conn.db.close();
    conn.db.removeDatabase(QSqlDatabase::defaultConnection);
    this->hide();
    addAnimal addAnimal;
    addAnimal.setModal(true);
    addAnimal.exec();
}

