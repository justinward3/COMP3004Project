#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>
#include "Shelter.h"
#include "Client.h"
#include "viewclients.h"

namespace Ui {
class addClient;
}

class addClient : public QDialog
{
    Q_OBJECT

public:
    explicit addClient(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setView(int, Client*);
    ~addClient();

private slots:
    void on_backButton_clicked();

    void on_addButton_clicked();

private:
    Ui::addClient *ui;
    Shelter* sh;
    Client* client;

};

#endif // ADDCLIENT_H
