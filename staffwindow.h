#ifndef STAFFWINDOW_H
#define STAFFWINDOW_H

#include <QDialog>

namespace Ui {
class staffWindow;
}

class staffWindow : public QDialog
{
    Q_OBJECT

public:
    explicit staffWindow(QWidget *parent = 0);
    ~staffWindow();

private slots:
    void on_viewAnimalsButton_clicked();

private:
    Ui::staffWindow *ui;
};

#endif // STAFFWINDOW_H
