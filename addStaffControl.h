#ifndef ADDSTAFFCONTROL_H
#define ADDSTAFFCONTROL_H

#include <QDialog>
#include "Shelter.h"
#include "Staff.h"
#include "UserFactory.h"
#include "clientListControl.h"
#include "ui_addStaffView.h"


namespace Ui {
class addStaffControl;
}

class addStaffControl : public QDialog
{
    Q_OBJECT

public:
    explicit addStaffControl(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setMainWindow(MainWindow*);
    ~addStaffControl();

private slots:
    void on_backButton_clicked();

    void on_addButton_clicked();

private:
    Ui::addStaffView *ui;
    Shelter* sh;
    Staff* staff;
    MainWindow* mw;

};

#endif // ADDSTAFFCONTROL_H
