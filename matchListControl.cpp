#include "matchListControl.h"
#include <QStandardItemModel>

matchListControl::matchListControl(QWidget *parent):
    QDialog(parent),
    ui(new Ui::matchListView)
{
    ui->setupUi(this);
    //Set up table and ui
    QStringList headers;
    headers<<"Client FirstName"<< "Client LastName" << "Animal Name" << "Score";
    //QStringListModel *model = new QStringListModel();
    model = new QStandardItemModel();
    model->setColumnCount(4);
    model->setHorizontalHeaderLabels(headers);

}

matchListControl::~matchListControl()
{
    delete model;
    delete ui;
}
//set shelter pointer
void matchListControl::setShelter(Shelter* shelter_ptr){
    sh = shelter_ptr;
}

//set mw pointer
void matchListControl::setMainWindow(MainWindow *main)
{
    mw = main;
}

//command handler for back button
void matchListControl::on_backButton_clicked()
{
    this->hide();
    staffWindow staffWindow;
    staffWindow.setShelter(sh);
    staffWindow.setMainWindow(mw);
    staffWindow.setModal(true);
    staffWindow.exec();
}

void matchListControl::on_detailButton_clicked()
{
    QItemSelectionModel *select = ui->matchList->selectionModel();
    if(select->hasSelection()){
        this->hide();

  }
}

void matchListControl::setMatches(QMap<Animal*,Client*> matches){
    for(auto key: matches.keys()){
        QList<QStandardItem*> newRow;
        Client *client = matches[key];
        QStandardItem* fname = new QStandardItem(QString(client->getFname()));
        QStandardItem* lname = new QStandardItem(QString(client->getLname()));
        QStandardItem* name = new QStandardItem(QString(key->getName()));
        ACMAlgorithm acm;
        QString s = QString::number(acm.runACMOnPair(key,client));
        QStandardItem* score = new QStandardItem(QString(s));

        //Order matters here
        newRow.append(fname);
        newRow.append(lname);
        newRow.append(name);
        newRow.append(score);
        //append to table
        model->appendRow(newRow);
    }
    ui->matchList->setModel(model);
    ui->matchList->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->matchList->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->matchList->setSelectionMode( QAbstractItemView::SingleSelection );
    ui->matchList->setSelectionBehavior(QAbstractItemView::SelectRows);
}
