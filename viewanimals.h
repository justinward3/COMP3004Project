#ifndef VIEWANIMALS_H
#define VIEWANIMALS_H

#include <QDialog>
#include "Shelter.h"
#include <QStandardItemModel>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "SmallAnimal.h"
#include "mainwindow.h"

namespace Ui {
class viewAnimals;
}

class viewAnimals : public QDialog
{
    Q_OBJECT

public:
    explicit viewAnimals(QWidget *parent = 0);
    ~viewAnimals();
    void setShelter(Shelter*);
    void setMainWindow(QMainWindow*);


private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_detailButton_clicked();

private:
    Ui::viewAnimals *ui;
    Shelter* sh;
    QStandardItemModel* model;
    vector<Animal*>  animals;
    QMainWindow* mw;

};

#endif // VIEWANIMALS_H
