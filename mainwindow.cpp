#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "staffwindow.h"

#include <QtSql>
#include <QDebug>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    shelter = new Shelter();
    ui->setupUi(this);
    QString DbPath = QApplication::applicationDirPath() + "/cuACSDb";
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/student/COMP3004-D1/3004/cuACSDb");
    db.open();

    if (!db.open()) {
        printf("DATABASE ERROR\n");
    }

    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(shelter->loadAnimals(db));
    //ui->animalList->setModel(model);
    cout<<shelter->getAnimals().size()<<endl;
}

MainWindow::~MainWindow()
{
    printf("MainWindow says goodbye");
    delete ui;
}

void MainWindow::on_staffButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(shelter);
    staffWindow.setModal(true);
    staffWindow.exec();
}
