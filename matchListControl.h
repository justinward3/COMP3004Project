#ifndef MATCHLISTCONTROL_H
#define MATCHLISTCONTROL_H

#include <QDialog>
#include "Shelter.h"
#include <QStandardItemModel>
#include "Client.h"
#include "staffwindow.h"
#include "mainWindow.h"
#include "ui_matchListView.h"
#include "matchDetailControl.h"


namespace Ui {
class matchListControl;
}

class matchListControl : public QDialog
{
    Q_OBJECT

public:
    explicit matchListControl(QWidget *parent = 0);
    ~matchListControl();
    void setShelter(Shelter*);
    void setMainWindow(MainWindow*);
    void setMatches(QMap<Animal*,Client*>);


private slots:
    void on_backButton_clicked();
    void on_detailButton_clicked();

private:
    Ui::matchListView *ui;
    Shelter* sh;
    QStandardItemModel* model;
    MainWindow* mw;
    QMap<Animal*,Client*> matches;

};

#endif // MATCHLISTCONTROL_H
