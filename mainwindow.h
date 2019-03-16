#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "staffwindow.h"
#include <QtSql>
#include "Shelter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Shelter* shelter;

private slots:
    void on_staffButton_clicked();

    void on_clientButton_clicked();

private:
    Ui::MainWindow *ui;
    bool connected;
};

#endif // MAINWINDOW_H
