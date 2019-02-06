#include "addanimal.h"
#include "ui_addanimal.h"
#include "viewanimals.h"
#include "mainwindow.h"
#include "Animal.h"

addAnimal::addAnimal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addAnimal)
{
    ui->setupUi(this);

    MainWindow conn;
    conn.db.open();

    if (!conn.db.open()) {
        printf("DATABASE ERROR\n");
    }
}

addAnimal::~addAnimal()
{
    delete ui;
}

void addAnimal::on_backButton_clicked()
{
    this->hide();
    viewAnimals viewAnimals;
    viewAnimals.setModal(true);
    viewAnimals.exec();
}

void addAnimal::on_addButton_clicked()
{
    MainWindow conn;
    QString name = ui->animalName->text();
    QString type = ui->animalType->currentText();
    QString age = ui->animalAge->text();
    QString sex = ui->animalSex->currentText();
    QString colour = ui->animalColour->text();


    if (name!="" && age!="" && colour!="") {
        QSqlQuery qry;
        qry.prepare("INSERT into Animals (name, type, age, sex, colour) VALUES "
                    "('"+name+"','"+type+"','"+age+"','"+sex+"','"+colour+"')");
        qry.exec();

        conn.db.close();
        conn.db.removeDatabase(QSqlDatabase::defaultConnection);
        on_backButton_clicked();
    }

    else {
        ui->status->setText("MISSING DATA");
    }
}
