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
    delete shelter;
    delete ui;
}

//command handler for staff button
void MainWindow::on_staffButton_clicked()
{
    //check if connected to Db
    if(connected){
        if(shelter->getOneStaff(ui->username->text())){
            this->hide();
            staffWindow staffWindow;
            staffWindow.setShelter(shelter);
            staffWindow.setMainWindow(this);
            staffWindow.setModal(true);
            staffWindow.exec();
            ui->username->clear();
        }
    }
    else{
        //pop message for Db failure
        QMessageBox::critical(0, "DB Status","DATABASE FAILURE, please contact system admin", QMessageBox::Ok);
    }
}
