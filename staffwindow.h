#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include <QDialog>
#include "Shelter.h"
#include "mainWindow.h"
#include "ui_menu.h"

namespace Ui {
class staffWindow;
}

class staffWindow : public QDialog
{
    Q_OBJECT

public:
    staffWindow(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setMainWindow(MainWindow*);
    ~staffWindow();


private slots:
    void on_viewAnimalsButton_clicked();

    void on_viewClientsButton_clicked();

    void on_addStaffButton_clicked();

    void on_logOut_clicked();

private:
    Ui::menu *ui;
    Shelter* sh;
    MainWindow* mw;
};

#endif // STAFFWINDOW_H
