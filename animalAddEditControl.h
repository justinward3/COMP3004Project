#ifndef ANIMALADDEDITCONTROL_H
#define ANIMALADDEDITCONTROL_H

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
class animalAddEditControl;
}

class animalAddEditControl : public QDialog
{
    Q_OBJECT

public:
    explicit animalAddEditControl(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setMainWindow(QMainWindow*);
    void edit(Animal*, int);
    void animalAddEditControlFields(bool);
    ~animalAddEditControl();

private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::animalDetailView *ui;
    Shelter* sh;
    Animal* animal;
    QMainWindow* mw;
    int pos;

};

#endif // ANIMALADDEDITCONTROL_H
