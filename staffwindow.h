#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include <QDialog>
#include "Shelter.h"
#include "mainwindow.h"
namespace Ui {
class staffWindow;
}

class staffWindow : public QDialog
{
    Q_OBJECT

public:
    staffWindow(QWidget *parent = 0);\
    void setShelter(Shelter*);
    ~staffWindow();


private slots:
    void on_viewAnimalsButton_clicked();

    void on_viewClientsButton_clicked();

private:
    Ui::staffWindow *ui;
    Shelter* sh;
};

#endif // STAFFWINDOW_H
