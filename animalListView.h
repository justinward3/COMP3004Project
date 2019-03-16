#ifndef ANIMALLISTVIEW_H
#define ANIMALLISTVIEW_H

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
class animalListView;
}

class animalListView : public QDialog
{
    Q_OBJECT

public:
    explicit animalListView(QWidget *parent = 0);
    ~animalListView();
    void setShelter(Shelter*);
    void setMainWindow(QMainWindow*);
    void setUserView();


private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_detailButton_clicked();

private:
    Ui::animalListView *ui;
    Shelter* sh;
    QStandardItemModel* model;
    QMainWindow* mw;
    bool userView;

};

#endif // ANIMALLISTVIEW_H
