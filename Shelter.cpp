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
}

//Deconstructor for Shelter
Shelter::~Shelter() {
      db.close();
      //cout<< "Shelter Deconstructor " <<endl;
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

bool Shelter::connect(){
    QDir dir;
    QString DbPath = dir.currentPath();
    DbPath.append("/cuACSDb");
    cout<<DbPath.toUtf8().constData()<<endl;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DbPath);
    if(db.open()){
        return this->loadAnimals();
    }
    return false;
}

//add Client function (operator overload)
Shelter& Shelter::operator+=(Client* c) {
    clients.insert(clients.end(), c);
    return *this;
}

//get Specific client from their emailAddress
Client* Shelter::getClient(QString email)  {
    for (size_t i = 0; i < clients.size(); i++)  {
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
bool Shelter::operator+=(Animal* a) {
    //Set up query
    qry=new QSqlQuery(db);
    QString s = "INSERT INTO `Animals`(`Type`,`Name`,`Age`,`Colour`,`Sex`,`Detail`) VALUES (:type,:name,:age,:colour,:sex,:detail);";
    qry->prepare(s);
    qry->bindValue(":name", a->getName());

    //Check subclass of animal and set type bind value
    if ( dynamic_cast<Dog*>( a ) )
       qry->bindValue(":type", "Dog");

    else if ( dynamic_cast<Cat*>( a ) )
       qry->bindValue(":type", "Cat");

    else if ( dynamic_cast<Bird*>( a ) )
       qry->bindValue(":type", "Bird");

    else if ( dynamic_cast<SmallAnimal*>( a ) )
       qry->bindValue(":type", "Small Animal");

    //convert char to str
    QString temp;
    temp.append(a->getSex());

    //set bind values
    qry->bindValue(":sex", temp);
    qry->bindValue(":age", a->getAge());
    qry->bindValue(":colour", a->getColour());
    qry->bindValue(":detail", a->getDetail());

    //if added to Db then add to vector
    if(qry->exec()){
        animals.insert(animals.end(),a);
        delete qry;
        return true;
    }
    else{
        delete qry;
        return false;
    }
}

bool Shelter::loadAnimals(){
    bool status;
    //prepare Sql Query to load animals
    qry=new QSqlQuery(db);
    qry->prepare("SELECT name, type, sex, age, colour, detail FROM Animals");

    //if succesfully connected to dB
    if(qry->exec()){
        status = true;
        while (qry->next()) {
            //local var for info from Db
            QString name = qry->value(0).toString();
            QString type = qry->value(1).toString();
            QString sex = qry->value(2).toString();
            int age = qry->value(3).toInt();
            QString detail = qry->value(5).toString();
            QString colour = qry->value(4).toString();

            //Create instances of Animals and add to Vector of Animals
            if (type == "Dog") {
                Dog* newDog = new Dog(name, colour, age, sex[0], detail);
                animals.insert(animals.end(), newDog);

            }
            else if (type == "Cat") {
                Cat* newCat = new Cat(name, colour, age, sex[0], detail);
                animals.insert(animals.end(), newCat);

            }
            else if (type == "Bird") {
                Bird* newBird = new Bird(name, colour, age, sex[0], detail);
                animals.insert(animals.end(), newBird);

            }
            else if (type == "Small Animal") {
                SmallAnimal* newSmallAnimal = new SmallAnimal(name, colour, age, sex[0], detail);
                animals.insert(animals.end(), newSmallAnimal);

            }
        }
    }
    else {
        status = false;
    }
    delete qry;
    return status;
}

//to be implemented
bool Shelter::loadUsers(){
    //prepare Sql Query to load Users
    qry=new QSqlQuery(db);
    qry->prepare("SELECT FirstName,LastName, Type, Address, PhoneNumber, EmailAddress FROM Users");
    bool status;
    if(qry->exec()){
        status=true;
        while (qry->next()) {
            status = true;
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
    }else{
        status = false;
    }
    delete qry;
    return status;
}

//return vector of animals
vector<Animal*>& Shelter::getAnimals() {return animals; }

//return vector of staff
vector<Staff*>& Shelter::getStaff()  { return staff; }
