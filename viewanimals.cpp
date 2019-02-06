#include "viewanimals.h"
#include "ui_viewanimals.h"
#include "staffwindow.h"
#include "addanimal.h"
#include "mainwindow.h"
#include "Shelter.h"

viewAnimals::viewAnimals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewAnimals)
{
    ui->setupUi(this);

    MainWindow conn;
    Shelter shelter;
    conn.db.open();

    if (!conn.db.open()) {
        printf("DATABASE ERROR\n");
    }
    else {
        QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery(shelter.loadAnimals(conn.db));
        ui->animalList->setModel(model);
    }

}

viewAnimals::~viewAnimals()
{
    delete ui;
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

