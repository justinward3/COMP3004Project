#ifndef VIEWANIMALS_H
#define VIEWANIMALS_H

#include <QDialog>

namespace Ui {
class viewAnimals;
}

class viewAnimals : public QDialog
{
    Q_OBJECT

public:
    explicit viewAnimals(QWidget *parent = 0);
    ~viewAnimals();

private slots:
    void on_backButton_clicked();

    void on_addButton_clicked();

private:
    Ui::viewAnimals *ui;
};

#endif // VIEWANIMALS_H
