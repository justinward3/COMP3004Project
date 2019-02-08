#ifndef SHELTER_H
#define SHELTER_H

#include "Staff.h"
#include "Client.h"
#include <vector>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include <QtSql>
#include <QSqlDatabase>

class Shelter{

    public:
        Shelter();
        ~Shelter();
        QSqlDatabase db;
        Shelter& operator+=(Client*);
        Client* getClient(QString);
        vector<Client*>& getClients();
        Shelter& operator+=(Staff*);
        Shelter& operator+=(Animal*) ;
        vector<Animal*>& getAnimals();
        vector<Staff*>& getStaff();
        void loadAnimals();
        void loadUsers();


    private:
        vector<Client*> clients;
        vector<Staff*> staff;
        vector<Animal*> animals;
        QSqlQuery* qry;
        QSqlQueryModel* model;

};

#endif
