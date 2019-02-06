#include "Shelter.h"
#include "sqlite3.h"
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

void Shelter::load(){

      sqlite3 *db;
      sqlite3_stmt* stmt = 0;
      int rc;

      rc = sqlite3_open("cuACSDb", &db);
        if(rc != SQLITE_OK){
            printf("%d\n", rc );
            printf("DATABASE ERROR \n");
        }else{
              loadAnimals(db,stmt,rc);
              loadUsers(db,stmt,rc);
          }
          sqlite3_finalize(stmt);
          sqlite3_close(db);
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

void Shelter::loadAnimals(sqlite3* db, sqlite3_stmt* stmt, int rc){
  string statement = "SELECT * FROM Animals";
  rc = sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, 0);

  for (int bindIndex = 0; bindIndex < 1; bindIndex++){
    rc = sqlite3_bind_int( stmt, 1, 1);

   while( sqlite3_step( stmt) == SQLITE_ROW ) {
     string type = "";
     string name = "";
     string colour = "";
     string breed = "";
     int age = 0;
     char sex = '\0';
    for (int colIndex=0; colIndex < sqlite3_column_count( stmt ); colIndex++ ){
        if (colIndex == 0){
          type  = (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }else if (colIndex == 1){
          name = (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }else if (colIndex == 2){
          age = sqlite3_column_int( stmt, colIndex );
        }else if (colIndex == 3){
          colour = (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }else if (colIndex == 4){
          sex =  (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))))[0];
        }
    }
              if (type == "Dog"){
                cout << "Dog"<<endl;
                Dog* newDog = new Dog(name,colour,age,sex,breed);
                animals.insert(animals.end(), newDog);
              }else if (type =="Cat"){
                cout << "Cat"<<endl;
                Cat* newCat = new Cat(name,colour,age,sex,breed);
                animals.insert(animals.end(), newCat);
              }


              //delete newAnimal;

    }
  }
}

void Shelter::loadUsers(sqlite3* db, sqlite3_stmt* stmt, int rc){
  string statement = "SELECT * FROM Users";
  rc = sqlite3_prepare_v2(db, statement.c_str(), -1, &stmt, 0);

  for (int bindIndex = 0; bindIndex < 1; bindIndex++){
    rc = sqlite3_bind_int( stmt, 1, 1);

   while( sqlite3_step( stmt) == SQLITE_ROW ) {
     string type = "";
     string fname = "";
     string lname = "";
     string add = "";
     string pnum = "";
     string email = "";

    for (int colIndex=0; colIndex < sqlite3_column_count( stmt ); colIndex++ ){
        if (colIndex == 0){
          type  = (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }else if (colIndex == 1){
          fname = (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }else if (colIndex == 2){
          lname = (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }else if (colIndex == 3){
          add = (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }else if (colIndex == 4){
          pnum =  (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }else if (colIndex == 5){
          email = (string(reinterpret_cast<const char*>(sqlite3_column_text( stmt, colIndex ))));
        }
    }
              if (type == "Client"){
                cout << "Client"<<endl;
                Client* newClient = new Client(fname,lname,add,pnum,email);
                clients.insert(clients.end(), newClient);
              }else if (type =="Staff"){
                cout << "Staff"<<endl;
                Staff* newStaff = new Staff(fname,lname,add,pnum,email);
                staff.insert(staff.end(),  newStaff);
              }


              //delete newAnimal;

    }
  }
}
//return vector of animals
vector<Animal*>& Shelter::getAnimals() {return animals; }

//return vector of staff
vector<Staff*>& Shelter::getStaff()  { return staff; }
