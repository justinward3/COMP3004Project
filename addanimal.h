#ifndef ADDANIMAL_H
#define ADDANIMAL_H

#include <QDialog>

namespace Ui {
class addAnimal;
}

class addAnimal : public QDialog
{
    Q_OBJECT

public:
    explicit addAnimal(QWidget *parent = 0);
    ~addAnimal();

private slots:
    void on_backButton_clicked();

    void on_addButton_clicked();

private:
    Ui::addAnimal *ui;

};

#endif // ADDANIMAL_H
