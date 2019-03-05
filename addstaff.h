#ifndef ADDSTAFF_H
#define ADDSTAFF_H

#include <QDialog>
#include "Shelter.h"
#include "Staff.h"
#include "viewclients.h"


namespace Ui {
class addStaff;
}

class addStaff : public QDialog
{
    Q_OBJECT

public:
    explicit addStaff(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setMainWindow(QMainWindow*);
    ~addStaff();

private slots:
    void on_backButton_clicked();

    void on_addButton_clicked();

private:
    Ui::addStaff *ui;
    Shelter* sh;
    Staff* staff;
    QMainWindow* mw;

};

#endif // ADDSTAFF_H
