#ifndef CLIENTLISTCONTROL_H
#define CLIENTLISTCONTROL_H

#include <QDialog>
#include "Shelter.h"
#include <QStandardItemModel>
#include "Client.h"
#include "staffwindow.h"
#include "animalAddEditControl.h"
#include "mainWindow.h"
#include "clientAddViewControl.h"
#include "ui_clientListView.h"


namespace Ui {
class clientListControl;
}

class clientListControl : public QDialog
{
    Q_OBJECT

public:
    explicit clientListControl(QWidget *parent = 0);
    ~clientListControl();
    void setShelter(Shelter*);
    void setMainWindow(MainWindow*);
    void setUserView();


private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_detailButton_clicked();

private:
    Ui::clientListView *ui;
    Shelter* sh;
    QStandardItemModel* model;
    vector<Client*>  clients;
    MainWindow* mw;

};

#endif // CLIENTLISTCONTROL_H
