#include "Shelter.h"
#include <QSqlDatabase>
#include <QSql>
#include <QSqlQuery>
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <vector>
#include <string.h>
#include "QMessageBox"

using namespace std;


//Constructor for Shelter
Shelter::Shelter() {
      cout<< "Shelter Constructor " <<endl;
      QDir dir;
      QString DbPath = dir.currentPath();
      DbPath.append("/cuACSDb");
      cout<<DbPath.toUtf8().constData()<<endl;
      db=QSqlDatabase::addDatabase("QSQLITE");
      db.setDatabaseName(DbPath);
      db.open();

      if (!db.open()) {
          printf("DATABASE ERROR\n");
      }

      this->loadAnimals();
      this->loadUsers();


}

//Deconstructor for Shelter
Shelter::~Shelter() {
      db.close();
      cout<< "Shelter Deconstructor " <<endl;
      for (vector<Animal*>::iterator it = animals.begin() ; it != animals.end(); ++it)
      {
        delete (*it);
      }
      animals.clear();
      for (vector<Client*>::iterator it = clients.begin() ; it != clients.end(); ++it)
      {
        delete (*it);
      }
      clients.clear();
      for (vector<Staff*>::iterator it = staff.begin() ; it != staff.end(); ++it)
      {
        delete (*it);
      }
      staff.clear();

}

//add Client function (operator overload)
Shelter& Shelter::operator+=(Client* c) {
    clients.insert(clients.end(), c);
    return *this;
}

//get Specific client from their emailAddress
Client* Shelter::getClient(QString email)  {
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

//add Animal function (operator overload)
Shelter& Shelter::operator+=(Animal* a) {
    qry=new QSqlQuery(db);
    QString s = "INSERT INTO `Animals`(`Type`,`Name`,`Age`,`Colour`,`Sex`,`Detail`) VALUES (:type,:name,:age,:colour,:sex,:detail);";
    qry->prepare(s);
    qry->bindValue(":name", a->getName());

    if ( dynamic_cast<Dog*>( a ) )
       qry->bindValue(":type", "Dog");

    else if ( dynamic_cast<Cat*>( a ) )
       qry->bindValue(":type", "Cat");
    QString temp;
    temp.append(a->getSex());
    qry->bindValue(":sex", temp);
    qry->bindValue(":age", a->getAge());
    qry->bindValue(":colour", a->getColour());
    qry->bindValue(":detail", a->getDetail());

    if(qry->exec())
        animals.insert(animals.end(),a);
        QMessageBox::critical(0, "DB Status","DATABASE UPDATED", QMessageBox::Ok);
    else
        QMessageBox::critical(0, "DB Status","DATABASE NOT UPDATED", QMessageBox::Ok);
    delete qry;
    return *this;
}

void Shelter::loadAnimals(){
    //prepare Sql Query to load animals
    qry=new QSqlQuery(db);
    qry->prepare("SELECT name, type, sex, age, colour, detail FROM Animals");
    qry->exec();

    while (qry->next()) {
        QString name = qry->value(0).toString();
        QString type = qry->value(1).toString();
        QString sex = qry->value(2).toString();
        int age = qry->value(3).toInt();
        QString detail = qry->value(5).toString();
        QString colour = qry->value(4).toString();

        //qDebug() << name << type << sex << age << breed << colour;
      
        //Create instances of Animals and add to Vector of Animals
        if (type == "Dog") {
            Dog* newDog = new Dog(name, colour, age, sex[0], detail);
            animals.insert(animals.end(), newDog);
            //cout << "Dog" <<endl;
        }
        else if (type == "Cat") {
            Cat* newCat = new Cat(name, colour, age, sex[0], detail);
            animals.insert(animals.end(), newCat);
            //cout << "Cat" <<endl;
        }
        else if (type == "Bird") {
            //Cat* newCat = new Cat(name, colour, age, sex[0], detail);
            //animals.insert(animals.end(), newCat);
            //cout << "Cat" <<endl;
        }
        else if (type == "SmallAnimal") {
            //Cat* newCat = new Cat(name, colour, age, sex[0], detail);
            //animals.insert(animals.end(), newCat);
            //cout << "Cat" <<endl;
        }  
    }
    delete qry;
}

void Shelter::loadUsers(){
    //prepare Sql Query to load Users
    qry=new QSqlQuery(db);
    qry->prepare("SELECT FirstName,LastName, Type, Address, PhoneNumber, EmailAddress FROM Users");
    qry->exec();

    while (qry->next()) {
        QString type = qry->value(0).toString();
        qDebug() << type<< qry->value(1).toString()<<qry->value(2).toString()<<qry->value(3).toString()<<qry->value(4).toString()<<qry->value(5).toString();
              if (type == "Client"){
                cout << "Client"<<endl;
                Client* newClient = new Client(qry->value(1).toString(),qry->value(2).toString(),qry->value(3).toString(),qry->value(4).toString(),qry->value(5).toString());
                clients.insert(clients.end(), newClient);
              }else if (type =="Staff"){
                cout << "Staff"<<endl;
                Staff* newStaff = new Staff(qry->value(1).toString(),qry->value(2).toString(),qry->value(3).toString(),qry->value(4).toString(),qry->value(5).toString());
                staff.insert(staff.end(), newStaff);
              }
    }
    delete qry;
}

//return vector of animals
vector<Animal*>& Shelter::getAnimals() {
    return animals;
}

//return vector of staff
vector<Staff*>& Shelter::getStaff()  { return staff; }
