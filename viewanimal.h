#ifndef VIEWANIMAL_H
#define VIEWANIMAL_H

#include <QDialog>
#include "Shelter.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "SmallAnimal.h"
#include "mainwindow.h"
#include "ui_addanimal.h"

namespace Ui {
class viewAnimal;
}

class viewAnimal : public QDialog
{
    Q_OBJECT

public:
    explicit viewAnimal(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setAnimal(Animal*,int);
    void setMainWindow(QMainWindow*);
    void setUserView();
    ~viewAnimal();

private slots:
    void on_backButton_clicked();
    void on_editButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::addAnimal *ui;
    Shelter* sh;
    Animal* animal;
    QMainWindow* mw;
    int pos;

};

#endif // VIEWANIMAL_H
