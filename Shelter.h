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
        void load(QSqlDatabase);
        Client* getClient(string);
        vector<Client*>& getClients();
        Shelter& operator+=(Staff*);
        vector<Animal*>& getAnimals();
        vector<Staff*>& getStaff();
        QSqlQuery loadAnimals();
        QSqlQuery loadUsers(QSqlDatabase*);


    private:
        vector<Client*> clients;
        vector<Staff*> staff;
        vector<Animal*> animals;

};

#endif
