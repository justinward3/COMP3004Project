#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include "Shelter.h"
#include "mainwindow.h"
#include "ui_menu.h"


namespace Ui {
class clientWindow;
}

class clientWindow : public QDialog
{
    Q_OBJECT

public:
    clientWindow(QWidget *parent = 0);\
    void setShelter(Shelter*);
    void setMainWindow(MainWindow*);
    void setClient(Client*);
    ~clientWindow();


private slots:
    void on_viewAnimalsButton_clicked();
    void on_editProfileButton_clicked();
    void on_logOut_clicked();

private:
    Ui::menu *ui;
    Shelter* sh;
    MainWindow* mw;
    Client* client;
};

#endif // CLIENTWINDOW_H
