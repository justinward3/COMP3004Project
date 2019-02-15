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
    ui->clientList->setModel(model);
    ui->clientList->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->clientList->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

viewClients::~viewClients()
{
    delete model;
    delete ui;
}
//set shelter pointer
void viewClients::setShelter(Shelter* shelter_ptr){
    cout << "SetShelter"<<endl;
    sh = shelter_ptr;
    vector<Client*> clients = sh->getClients();

    //Add clients to table
    for(size_t i=0; i< clients.size();i++){
        qDebug() << clients[i]->getFname()<<endl;
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

//command handler for back button
void viewClients::on_backButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(sh);
    staffWindow.setModal(true);
    staffWindow.exec();
}

//command handler for add button
void viewClients::on_addButton_clicked()
{
    this->hide();
    addClient clientAdd;
    clientAdd.setShelter(sh);
    clientAdd.setModal(true);
    clientAdd.exec();
}

