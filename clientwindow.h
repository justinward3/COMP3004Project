#ifndef CLIENTWINDOW_H
#define CLIENTWINDOW_H

#include <QDialog>
#include "Shelter.h"
#include "mainwindow.h"

namespace Ui {
class clientWindow;
}

class clientWindow : public QDialog
{
    Q_OBJECT

public:
    clientWindow(QWidget *parent = 0);\
    void setShelter(Shelter*);
    void setMainWindow(QMainWindow*);
    ~clientWindow();


private slots:
    void on_viewAnimalsButton_clicked();

    void on_logOut_clicked();

private:
    Ui::menu *ui;
    Shelter* sh;
    QMainWindow* mw;
};

#endif // CLIENTWINDOW_H
