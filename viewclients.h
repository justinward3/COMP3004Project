#ifndef VIEWCLIENTS_H
#define VIEWCLIENTS_H

#include <QDialog>
#include "Shelter.h"
#include <QStandardItemModel>
#include "Client.h"
#include "staffwindow.h"
#include "animalAddEditControl.h"
#include "mainwindow.h"
#include "addclient.h"


namespace Ui {
class viewClients;
}

class viewClients : public QDialog
{
    Q_OBJECT

public:
    explicit viewClients(QWidget *parent = 0);
    ~viewClients();
    void setShelter(Shelter*);
    void setMainWindow(QMainWindow*);
    void setUserView();


private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_detailButton_clicked();

private:
    Ui::viewClients *ui;
    Shelter* sh;
    QStandardItemModel* model;
    vector<Client*>  clients;
    QMainWindow* mw;

};

#endif // VIEWCLIENTS_H
