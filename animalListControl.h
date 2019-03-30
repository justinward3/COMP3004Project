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
#include "mainWindow.h"
#include "ui_animalListView.h"

namespace Ui {
class animalListControl;
}

class animalListControl : public QDialog
{
    Q_OBJECT

public:
    explicit animalListControl(QWidget *parent = 0);
    ~animalListControl();
    void setShelter(Shelter*);
    void setMainWindow(MainWindow*);
    void setUserView();


private slots:
    void on_backButton_clicked();
    void on_addButton_clicked();
    void on_detailButton_clicked();

private:
    Ui::animalListView *ui;
    Shelter* sh;
    QStandardItemModel* model;
    MainWindow* mw;
    bool clientView;

};

#endif // ANIMALLISTVIEW_H
