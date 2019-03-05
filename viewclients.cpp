#include "viewclients.h"
#include "ui_viewclients.h"
#include <QStandardItemModel>

viewClients::viewClients(QWidget *parent):
    QDialog(parent),
    ui(new Ui::viewClients)
{
    ui->setupUi(this);
    //Set up table and ui
    QStringList headers;
    headers<<"FirstName"<<"LastName"<<"Address"<<"Phone Number"<<"Email";
    //QStringListModel *model = new QStringListModel();
    model = new QStandardItemModel();
    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(headers);

    //setup table
    ui->clientList->setModel(model);
    ui->clientList->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->clientList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->clientList->setSelectionMode( QAbstractItemView::SingleSelection );
    ui->clientList->setSelectionBehavior(QAbstractItemView::SelectRows);

}

viewClients::~viewClients()
{
    delete model;
    delete ui;
}
//set shelter pointer
void viewClients::setShelter(Shelter* shelter_ptr){
    sh = shelter_ptr;
    clients = sh->getClients();

    //Add clients to table
    for(size_t i=0; i< clients.size();i++){
        QList<QStandardItem*> newRow;
        QStandardItem* fname = new QStandardItem(QString(clients[i]->getFname()));
        QStandardItem* lname = new QStandardItem(QString(clients[i]->getLname()));
        QStandardItem* address = new QStandardItem(QString(clients[i]->getAddress()));
        QStandardItem* phone = new QStandardItem(QString(clients[i]->getPhoneNumber()));
        QStandardItem* email = new QStandardItem(QString(clients[i]->getEmail()));

        //Order matters here
        newRow.append(fname);
        newRow.append(lname);
        newRow.append(address);
        newRow.append(phone);
        newRow.append(email);
        //append to table
        model->appendRow(newRow);
    }

    ui->clientList->setModel(model);
}

//set mw pointer
void viewClients::setMainWindow(QMainWindow *main)
{
    mw = main;
}

//command handler for back button
void viewClients::on_backButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(sh);
    staffWindow.setMainWindow(mw);
    staffWindow.setModal(true);
    staffWindow.exec();
}

//command handler for add button
void viewClients::on_addButton_clicked()
{
    this->hide();
    addClient clientAdd;
    clientAdd.setShelter(sh);
    clientAdd.setMainWindow(mw);
    clientAdd.setModal(true);
    clientAdd.exec();
}


void viewClients::on_detailButton_clicked()
{
    QItemSelectionModel *select = ui->clientList->selectionModel();
    if(select->hasSelection()){
        this->hide();
        addClient clientAdd;
        clientAdd.setView(1, clients[select->currentIndex().row()]);
        clientAdd.setShelter(sh);
        clientAdd.setMainWindow(mw);
        clientAdd.setModal(true);
        clientAdd.exec();
  }
}
