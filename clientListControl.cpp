#include "clientListControl.h"
#include <QStandardItemModel>

clientListControl::clientListControl(QWidget *parent):
    QDialog(parent),
    ui(new Ui::clientListView)
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

clientListControl::~clientListControl()
{
    delete model;
    delete ui;
}
//set shelter pointer
void clientListControl::setShelter(Shelter* shelter_ptr){
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
void clientListControl::setMainWindow(MainWindow *main)
{
    mw = main;
}

//command handler for back button
void clientListControl::on_backButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(sh);
    staffWindow.setMainWindow(mw);
    staffWindow.setModal(true);
    staffWindow.exec();
}

//command handler for add button
void clientListControl::on_addButton_clicked()
{
    this->hide();
    clientAddViewControl clientAdd;
    clientAdd.setShelter(sh);
    clientAdd.setMainWindow(mw);
    clientAdd.setModal(true);
    clientAdd.exec();
}


void clientListControl::on_detailButton_clicked()
{
    QItemSelectionModel *select = ui->clientList->selectionModel();
    if(select->hasSelection()){
        this->hide();
        clientAddViewControl clientAdd;
        clientAdd.setView(1, clients[select->currentIndex().row()]);
        clientAdd.setShelter(sh);
        clientAdd.setMainWindow(mw);
        clientAdd.setModal(true);
        clientAdd.exec();
  }
}
