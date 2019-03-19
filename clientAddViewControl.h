#ifndef CLIENTADDVIEWCONTROL_H
#define CLIENTADDVIEWCONTROL_H

#include <QDialog>
#include "Shelter.h"
#include "Client.h"
#include "viewclients.h"
#include "clientwindow.h"
#include "ui_clientDetailView.h"

namespace Ui {
class clientAddViewControl;
}

class clientAddViewControl : public QDialog
{
    Q_OBJECT

public:
    explicit clientAddViewControl(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setMainWindow(MainWindow*);
    void setView(int, Client*);
    void addClientFields(bool);
    void setUserView();
    ~clientAddViewControl();

private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();

private:
    Ui::clientDetailView *ui;
    Shelter* sh;
    Client* client;
    MainWindow* mw;


};

#endif // CLIENTADDVIEWCONTROL_H
