#ifndef CLIENTEDITCONTROL_H
#define CLIENTEDITCONTROL_H

#include <QDialog>
#include "Shelter.h"
#include "Client.h"
#include "viewclients.h"
#include "clientwindow.h"
#include "ui_clientDetailView.h"

namespace Ui {
class clientEditControl;
}

class clientEditControl : public QDialog
{
    Q_OBJECT

public:
    explicit clientEditControl(QWidget *parent = 0);
    void setShelter(Shelter*);
    void setMainWindow(MainWindow*);
    void edit(Client*);
    ~clientEditControl();

private slots:
    void on_backButton_clicked();
    void on_saveButton_clicked();
private:
    Ui::clientDetailView *ui;
    Shelter* sh;
    Client* client;
    MainWindow* mw;
    bool clientView;
};

#endif // CLIENTEDITCONTROL_H
