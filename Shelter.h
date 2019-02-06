#ifndef SHELTER_H
#define SHELTER_H

#include "Staff.h"
#include "Client.h"
#include <vector>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "sqlite3.h"

class Shelter{

    public:
        Shelter();
        ~Shelter();
        Shelter& operator+=(Client*);
		    void load();
        Client* getClient(string);
        vector<Client*>& getClients();
        Shelter& operator+=(Staff*);
        vector<Animal*>& getAnimals();
        vector<Staff*>& getStaff();

    private:
        vector<Client*> clients;
        vector<Staff*> staff;
        vector<Animal*> animals;

        void loadUsers(sqlite3*,sqlite3_stmt*, int);
        void loadAnimals(sqlite3*,sqlite3_stmt*, int);

};

#endif
