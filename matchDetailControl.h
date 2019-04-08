#ifndef MATCHDETAILCONTROL_H
#define MATCHDETAILCONTROL_H

#include <QDialog>
#include "Shelter.h"
#include <QStandardItemModel>
#include "Client.h"
#include "staffwindow.h"
#include "mainWindow.h"
#include "ui_matchDetailView.h"


namespace Ui {
class matchDetailControl;
}

class matchDetailControl : public QDialog
{
    Q_OBJECT

public:
    explicit matchDetailControl(QWidget *parent = 0);
    ~matchDetailControl();
    void setShelter(Shelter*);
    void setAnimal(Animal*);
    void setClient(Client*);
    void setMainWindow(MainWindow*);
    void setMatch(Animal*,Client*);


private slots:
    void on_backButton_clicked();

private:
    Ui::matchDetailView *ui;
    Shelter* sh;
    MainWindow* mw;

};

#endif // MATCHDETAILCONTROL_H
