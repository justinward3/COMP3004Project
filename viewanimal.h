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

namespace Ui {
class viewAnimal;
}

class viewAnimal : public QDialog
{
    Q_OBJECT

public:
    explicit viewAnimal(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setMainWindow(QMainWindow*);
    ~viewAnimal();

private slots:
    void on_backButton_clicked();

private:
    Ui::viewAnimal *ui;
    Shelter* sh;
    Animal* animal;
    QMainWindow* mw;

};

#endif // VIEWANIMAL_H
