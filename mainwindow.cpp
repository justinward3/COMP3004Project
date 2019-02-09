#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "staffwindow.h"
#include "QMessageBox"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui= new Ui::MainWindow();
    shelter = new Shelter();
    connected = shelter->connect();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    printf("MainWindow says goodbye");\
    delete shelter;
    delete ui;
}

void MainWindow::on_staffButton_clicked()
{
    if(connected){
        this->hide();
        staffWindow staffWindow;
        staffWindow.setShelter(shelter);
        staffWindow.setModal(true);
        staffWindow.exec();
    }
    else{
        QMessageBox::critical(0, "DB Status","DATABASE FAILURE, please contact system admin", QMessageBox::Ok);
    }
}
