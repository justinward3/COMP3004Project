#ifndef SHELTER_H
#define SHELTER_H

#include "Staff.h"
#include "Client.h"
#include <vector>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "SmallAnimal.h"
#include <QtSql>
#include <QSqlDatabase>

class Shelter{

    public:
        Shelter();
        ~Shelter();
        bool connect();
        bool operator+=(Client*);
        Client* getClient(QString);
        Staff* getOneStaff(QString);
        vector<Client*>& getClients();
        bool operator+=(Staff*);
        bool operator+=(Animal*) ;
        vector<Animal*>& getAnimals();
        vector<Staff*>& getStaff();
        bool update(Animal*,QString, QString,QString,int,QChar,QString, QMap<QString,int>, int pos);
        int getLastId();

    private:
        QSqlDatabase db;
        vector<Client*> clients;
        vector<Staff*> staff;
        vector<Animal*> animals;
        QSqlQuery* qry;
        QSqlQueryModel* model;
        bool loadAnimals();
        bool loadUsers();
        bool loadClientData();
        int lastId = 0;
};

#endif
