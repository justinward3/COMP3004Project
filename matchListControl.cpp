#include "matchListControl.h"
#include "matchDetailControl.h"
#include <QStandardItemModel>

matchListControl::matchListControl(QWidget *parent):
    QDialog(parent),
    ui(new Ui::matchListView)
{
    ui->setupUi(this);
    //Set up table and ui
    QStringList headers;
    headers<<"Client" << "Desired a" << "Animal Name" << "Animal Type" << "Score";
    //QStringListModel *model = new QStringListModel();
    model = new QStandardItemModel();
    model->setColumnCount(5);
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
        int row = select->currentIndex().row();
        qDebug() << matches.keys()[row]->getName();
        matchDetailControl matchDetail;
        matchDetail.setShelter(sh);
        matchDetail.setMainWindow(mw);
        matchDetail.setMatch(matches.keys()[row],matches[matches.keys()[row]]);
        matchDetail.setModal(true);
        matchDetail.exec();
  }
}

void matchListControl::setMatches(QMap<Animal*,Client*> m){
    ACMAlgorithm acm;
    matches = m;
    for(auto key: matches.keys()){
        QList<QStandardItem*> newRow;
        Client *client = matches[key];
        QStandardItem* Cname = new QStandardItem(QString(client->getFname() +" "+ client->getLname()));
        QStandardItem* name = new QStandardItem(QString(key->getName()));
        QString s = QString::number(acm.runACMOnPair(key,client));
        QStandardItem* score = new QStandardItem(QString(s));
        QString t;
        QString wantedStr;
        int wanted = client->getMatchingPrefs()["type"];
        //Check subclass of animal and set type bind value
        if ( dynamic_cast<Dog*>( key ) )
           t = "Dog";

        else if ( dynamic_cast<Cat*>( key ) )
           t = "Cat";

        else if ( dynamic_cast<Bird*>( key ) )
           t = "Bird";

        else if ( dynamic_cast<SmallAnimal*>( key ) )
           t = "Small Animal";

        if (wanted == 1 )
           wantedStr =  "Dog";

        else if (wanted == 2)
           wantedStr =  "Cat";

        else if (wanted == 3)
           wantedStr =  "Bird";

        else if (wanted == 4)
           wantedStr = "Small Animal";

        QStandardItem* type = new QStandardItem(QString(t));
        QStandardItem* wantedItem = new QStandardItem(QString(wantedStr));
        //Order matters here
        newRow.append(Cname);
        newRow.append(wantedItem);
        newRow.append(name);
        newRow.append(type);
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
