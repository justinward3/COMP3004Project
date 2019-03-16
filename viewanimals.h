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
    void setUserView();


private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_detailButton_clicked();

private:
    Ui::viewAnimals *ui;
    Shelter* sh;
    QStandardItemModel* model;
    QMainWindow* mw;
    bool userView;

};

#endif // VIEWANIMALS_H
