#ifndef ADDANIMAL_H
#define ADDANIMAL_H

#include <QDialog>
#include "Shelter.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "SmallAnimal.h"

namespace Ui {
class addAnimal;
}

class addAnimal : public QDialog
{
    Q_OBJECT

public:
    explicit addAnimal(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setView(int);
    ~addAnimal();

private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();

private:
    Ui::addAnimal *ui;
    Shelter* sh;
    Animal* animal;

};

#endif // ADDANIMAL_H
