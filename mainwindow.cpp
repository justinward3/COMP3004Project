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
    ui->setupUi(this);

    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/student/Documents/3004/cuACS/cuACSDb");
    db.open();

    if (!db.open()) {
        printf("DATABASE ERROR\n");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_staffButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setModal(true);
    staffWindow.exec();
}
