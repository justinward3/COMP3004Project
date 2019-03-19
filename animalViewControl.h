#ifndef ANIMALVIEWCONTROL_H
#define ANIMALVIEWCONTROL_H

#include <QDialog>
#include "Shelter.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "SmallAnimal.h"
#include "mainwindow.h"
#include "ui_animalDetailView.h"

namespace Ui {
class animalViewControl;
}

class animalViewControl : public QDialog
{
    Q_OBJECT

public:
    explicit animalViewControl(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setAnimal(Animal*,int);
    void setMainWindow(MainWindow*);
    void setUserView();
    ~animalViewControl();

private slots:
    void on_backButton_clicked();
    void on_editButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::animalDetailView *ui;
    Shelter* sh;
    Animal* animal;
    MainWindow* mw;
    int pos;
    bool clientView;

};

#endif // ANIMALVIEWCONTROL_H
