#ifndef VIEWCLIENTS_H
#define VIEWCLIENTS_H

#include <QDialog>
#include "Shelter.h"
#include <QStandardItemModel>
#include "Client.h"


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


private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();

private:
    Ui::viewClients *ui;
    Shelter* sh;
    QStandardItemModel* model;

};

#endif // VIEWCLIENTS_H
