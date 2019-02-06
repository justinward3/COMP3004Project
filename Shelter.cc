#include "Shelter.h"
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QDebug>
#include <vector>
#include <string.h>

using namespace std;


//Constructor for Shelter
Shelter::Shelter() {
      cout<< "Shelter Constructor " <<endl;

}

//Deconstructor for Shelter
Shelter::~Shelter() {
      cout<< "Shelter Deconstructor " <<endl;
      animals.clear();
      clients.clear();
      staff.clear();
}

//add Client function (operator overload)
Shelter& Shelter::operator+=(Client* c) {
    clients.insert(clients.end(), c);
    return *this;
}

void Shelter::load(QSqlDatabase db){

}

//get Specific client from their emailAddress
Client* Shelter::getClient(string email)  {
    for (int i = 0; i < clients.size(); i++)  {
        if (clients.at(i)->getEmail() == email)
            return clients.at(i);
    }
    return 0;
}

//return vector of clients
vector<Client*>& Shelter::getClients() { return clients; }

//add Staff function (operator overload)
Shelter& Shelter::operator+=(Staff* s) {
    staff.insert(staff.end(),s);
    return *this;
}

QSqlQuery Shelter::loadAnimals(QSqlDatabase db){
    QSqlQuery* qry=new QSqlQuery(db);

    qry->prepare("SELECT name, type, sex, age, colour FROM Animals");
    qry->exec();

    while (qry->next()) {
        QString name = qry->value(0).toString();
        QString type = qry->value(1).toString();
        QChar sex = qry->value(2).toChar();
        int age = qry->value(3).toInt();
        //QString breed = qry->value(4).toString();
        QString breed = "Unknown";
        QString colour = qry->value(5).toString();

        qDebug() << name << type << sex << age << breed << colour;

        if (type == "Dog") {
            Dog* newDog = new Dog(name, colour, age, sex, breed);
            animals.insert(animals.end(), newDog);
            cout << "Dog" <<endl;
        }
        else if (type == "Cat") {
            Cat* newCat = new Cat(name, colour, age, sex, breed);
            animals.insert(animals.end(), newCat);
            cout << "Cat" <<endl;
        }

    }

    return *qry;



//    }
//  }
}

QSqlQuery Shelter::loadUsers(QSqlDatabase* db){
//              if (type == "Client"){
//                cout << "Client"<<endl;
//                Client* newClient = new Client(fname,lname,add,pnum,email);
//                clients.insert(clients.end(), newClient);
//              }else if (type =="Staff"){
//                cout << "Staff"<<endl;
//                Staff* newStaff = new Staff(fname,lname,add,pnum,email);
//                staff.insert(staff.end(),  newStaff);
//              }


              //delete newAnimal;

//    }
//  }
}
//return vector of animals
vector<Animal*>& Shelter::getAnimals() {return animals; }

//return vector of staff
vector<Staff*>& Shelter::getStaff()  { return staff; }
