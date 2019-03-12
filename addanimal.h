#ifndef ADDANIMAL_H
#define ADDANIMAL_H

#include <QDialog>
#include "Shelter.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "SmallAnimal.h"
#include "mainwindow.h"

namespace Ui {
class addAnimal;
}

class addAnimal : public QDialog
{
    Q_OBJECT

public:
    explicit addAnimal(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setMainWindow(QMainWindow*);
    void edit(Animal*, int);
    void addAnimalFields(bool);
    ~addAnimal();

private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_saveButton_clicked();

private:
    Ui::addAnimal *ui;
    Shelter* sh;
    Animal* animal;
    QMainWindow* mw;
    int pos;

};

#endif // ADDANIMAL_H
