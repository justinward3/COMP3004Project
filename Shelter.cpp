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
#include "qmap.h"

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
    DbPath.append("/cuACSDb2");
    cout<<DbPath.toUtf8().constData()<<endl;
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(DbPath);
    if(db.open()){
        return this->loadAnimals() && this->loadUsers();
    }
    return false;
}

//add Client function (operator overload)
bool Shelter::operator+=(Client* c) {
    //Set up query
    bool unique = true;
    for (size_t i = 0; i < clients.size(); i++) {
        if(clients[i]->getEmail()==c->getEmail()){
            unique = false;
        }
    }
    if(unique){
        qry=new QSqlQuery(db);
        QString s = "INSERT INTO `Users`(`Type`,`FirstName`,`LastName`,`Address`,`PhoneNumber`,`EmailAddress`) VALUES (:type,:fname,:lname,:add,:phone,:email);";
        qry->prepare(s);
        qry->bindValue(":fname", c->getFname());
        qry->bindValue(":lname", c->getLname());
        qry->bindValue(":type", "Client");
        qry->bindValue(":add", c->getAddress());
        qry->bindValue(":phone", c->getPhoneNumber());
        qry->bindValue(":email", c->getEmail());
        //if added to Db then add to vector
        cout <<"try to exec"<<endl;
        if(qry->exec()){
                    cout <<"try to exec2"<<endl;

            clients.insert(clients.end(),c);
            delete qry;
            return true;
        }
    }
     qDebug()<< qry->lastError().databaseText();
    delete qry;
    return false;


}

//add Staff function (operator overload)
bool Shelter::operator+=(Staff* s) {
    cout<<"staffop"<<endl;
    //Set up query
    bool unique = true;
    for (size_t i = 0; i < staff.size(); i++) {
        if(staff[i]->getEmail()==s->getEmail()){
            unique = false;
        }
    }
    if(unique){
        qry=new QSqlQuery(db);
        QString sqry = "INSERT INTO `Users`(`Type`,`FirstName`,`LastName`,`Address`,`PhoneNumber`,`EmailAddress`) VALUES (:type,:fname,:lname,:add,:phone,:email);";
        qry->prepare(sqry);
        qry->bindValue(":fname", s->getFname());
        qry->bindValue(":lname", s->getLname());
        qry->bindValue(":type", "Staff");
        qry->bindValue(":add", s->getAddress());
        qry->bindValue(":phone", s->getPhoneNumber());
        qry->bindValue(":email", s->getEmail());
        //if added to Db then add to vector
        cout <<"try to exec"<<endl;
        if(qry->exec()){
                    cout <<"try to exec2"<<endl;

            staff.insert(staff.end(),s);
            delete qry;
            return true;
        }
    }
    qDebug()<< qry->lastError().databaseText();
    delete qry;
    return false;
}

//get Specific client from their emailAddress
Client* Shelter::getClient(QString email)  {
    for (size_t i = 0; i < clients.size(); i++)  {
        if (clients.at(i)->getEmail() == email)
            return clients.at(i);
    }
    return 0;
}

//get Specific staff from their emailAddress
Staff* Shelter::getOneStaff(QString email)  {
    for (size_t i = 0; i < staff.size(); i++)  {
        if (staff.at(i)->getEmail() == email)
            return staff.at(i);
    }
    return 0;
}

//return vector of clients
vector<Client*>& Shelter::getClients() { return clients; }

//add Animal function (operator overload)
bool Shelter::operator+=(Animal* a) {
    //Set up query
    qry=new QSqlQuery(db);
    QString s = "INSERT INTO `Animals`(`Type`,`Name`,`Age`,`Colour`,`Sex`,`Detail`,`DoC`,`Affection`,`Cost`,`Time`,`LifeSpan`,`Space`,`Loudness`,`Activeness`,`Obedience`,`Shedding`,`IntWithDog`,`IntWithCat`,`IntWithChild`) VALUES (:type,:name,:age,:colour,:sex,:detail,:doc,:affection,:cost,:time,:lifespan,:space,:loudness,:activeness,:obedience,:shedding,:intwithdog,:intwithcat,:intwithchild);";
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
    qry->bindValue(":doc", a->getTraits()["doc"]);
    qry->bindValue(":affection", a->getTraits()["affection"]);
    qry->bindValue(":cost", a->getTraits()["cost"]);
    qry->bindValue(":time", a->getTraits()["time"]);
    qry->bindValue(":lifespan", a->getTraits()["lifespan"]);
    qry->bindValue(":space", a->getTraits()["space"]);
    qry->bindValue(":loudness", a->getTraits()["loudness"]);
    qry->bindValue(":activeness", a->getTraits()["activeness"]);
    qry->bindValue(":obedience", a->getTraits()["obedience"]);
    qry->bindValue(":shedding", a->getTraits()["shedding"]);
    qry->bindValue(":intwithdog", a->getTraits()["intwithdog"]);
    qry->bindValue(":intwithcat", a->getTraits()["intwithcat"]);
    qry->bindValue(":intwithchild", a->getTraits()["intwithchild"]);

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

//add Animal function (operator overload)
bool Shelter::update(Animal* a, QString type, QString name,QString colour,int age, QChar sex, QString detail, QMap<QString,int> attr, int pos){
    Animal *newAnimal;
    qry=new QSqlQuery(db);
    QString s = "UPDATE `Animals` SET `Type`=:type,`Name`=:name,`Age`=:age,`Colour`=:colour,`Sex`=:sex,`Detail`=:detail,`DoC`=:doc,`Affection`=:affection,`Cost`=:cost,`Time`=:time,`LifeSpan`=:lifespan,`Space`=:space,`Loudness`=:loudness,`Activeness`=:activeness,`Obedience`=:obedience,`Shedding`=:shedding,`IntWithDog`=:intwithdog,`IntWithCat`=:intwithcat,`IntWithChild`=:intwithchild WHERE `Type`=:type2 AND `Name`=:name2 AND `Age`=:age2 AND `Colour`=:colour2 AND `Sex`=:sex2 AND `Detail`=:detail2 AND `DoC`=:doc2 AND `Affection`=:affection2 AND `Cost`=:cost2 AND `Time`=:time2 AND `LifeSpan`=:lifespan2 AND `Space`=:space2 AND `Loudness`=:loudness2 AND `Activeness`=:activeness2 AND `Obedience`=:obedience2 AND `Shedding`=:shedding2 AND `IntWithDog`=:intwithdog2 AND `IntWithCat`=:intwithcat2 AND `IntWithChild`=:intwithchild2";

                 //" VALUES (:type,:name,:age,:colour,:sex,:detail,:doc,:affection,:cost,:time,:lifespan,:space,:loudness,:activeness,:obedience,:shedding,:intwithdog,:intwithcat,:intwithchild) ;";
    //"WHERE (`Type`,`Name`,`Age`,`Colour`,`Sex`,`Detail`,`DoC`,`Affection`,`Cost`,`Time`,`LifeSpan`,`Space`,`Loudness`,`Activeness`,`Obedience`,`Shedding`,`IntWithDog`,`IntWithCat`,`IntWithChild`) VALUES (:type1,:name1,:age1,:colour1,:sex1,:detail1,:doc1,:affection1,:cost1,:time1,:lifespan1,:space1,:loudness1,:activeness1,:obedience1,:shedding1,:intwithdog1,:intwithcat1,:intwithchild1);";
    qry->prepare(s);

    //SET BIND VALUES FOR VALUES TO BE UPDATED

    qry->bindValue(":type", type);
    qry->bindValue(":name", name);
    qry->bindValue(":sex", sex);
    qry->bindValue(":age", age);
    qry->bindValue(":colour", colour);
    qry->bindValue(":detail", detail);
    qry->bindValue(":doc", attr["doc"]);
    qry->bindValue(":affection", attr["affection"]);
    qry->bindValue(":cost", attr["cost"]);
    qry->bindValue(":time", attr["time"]);
    qry->bindValue(":lifespan", attr["lifespan"]);
    qry->bindValue(":space", attr["space"]);
    qry->bindValue(":loudness", attr["loudness"]);
    qry->bindValue(":activeness", attr["activeness"]);
    qry->bindValue(":obedience", attr["obedience"]);
    qry->bindValue(":shedding", attr["shedding"]);
    qry->bindValue(":intwithdog", attr["intwithdog"]);
    qry->bindValue(":intwithcat", attr["intwithcat"]);
    qry->bindValue(":intwithchild", attr["intwithchild"]);


    //SET BIND VALUES OF ANIMAL THAT WILL BE UPDATED
    //Check subclass of animal and set type bind value
    if ( dynamic_cast<Dog*>( a ) ){
       qDebug()<<"DOG";
       qry->bindValue(":type2", "Dog");
    }
    else if ( dynamic_cast<Cat*>( a ) ){
       qDebug()<<"CAT";
       qry->bindValue(":type2", "Cat");
       }
    else if ( dynamic_cast<Bird*>( a ) ){
       qDebug()<<"B";
       qry->bindValue(":type2", "Bird");
       }
    else if ( dynamic_cast<SmallAnimal*>( a ) ){
       qDebug()<<"SA";
       qry->bindValue(":type2", "Small Animal");
       }


    qry->bindValue(":name2", a->getName());
    qry->bindValue(":sex2", a->getSex());
    qry->bindValue(":age2", a->getAge());
    qry->bindValue(":colour2", a->getColour());
    qry->bindValue(":detail2", a->getDetail());
    qry->bindValue(":doc2", a->getTraits()["doc"]);
    qry->bindValue(":affection2", a->getTraits()["affection"]);
    qry->bindValue(":cost2", a->getTraits()["cost"]);
    qry->bindValue(":time2", a->getTraits()["time"]);
    qry->bindValue(":lifespan2", a->getTraits()["lifespan"]);
    qry->bindValue(":space2", a->getTraits()["space"]);
    qry->bindValue(":loudness2", a->getTraits()["loudness"]);
    qry->bindValue(":activeness2", a->getTraits()["activeness"]);
    qry->bindValue(":obedience2", a->getTraits()["obedience"]);
    qry->bindValue(":shedding2", a->getTraits()["shedding"]);
    qry->bindValue(":intwithdog2", a->getTraits()["intwithdog"]);
    qry->bindValue(":intwithcat2", a->getTraits()["intwithcat"]);
    qry->bindValue(":intwithchild2", a->getTraits()["intwithchild"]);

    qDebug() << a->getName();
    qDebug() << a->getSex();
    qDebug() << a->getAge();
    qDebug() << a->getColour();
    qDebug() << a->getDetail();
    qDebug() << a->getTraits();

    //if updated in Db then update in vector
    if(qry->exec()){
        //qry->finish();
        //qDebug()<<qry->value(1).toString();
        delete a;
        if(type == "Dog"){
            newAnimal = new Dog(name,colour,age,sex,detail,attr);
        }
        else if(type == "Cat"){
            newAnimal = new Cat(name,colour,age,sex,detail,attr);
        }
        else if(type == "Bird"){
            newAnimal = new Bird(name,colour,age,sex,detail,attr);
        }
        else if(type == "Small Animal"){
            newAnimal = new SmallAnimal(name,colour,age,sex,detail,attr);
        }
        animals[pos] = newAnimal;
        delete qry;
        return true;
    }
    else{
        //delete qry;
        qDebug()<<qry->lastQuery();
        qDebug()<<qry->lastError().nativeErrorCode();
        qDebug()<<qry->lastError().driverText();
        qDebug()<<qry->lastError().text();
        return false;
    }
}

bool Shelter::loadAnimals(){
    bool status;
    //prepare Sql Query to load animals
    qry=new QSqlQuery(db);
    qry->prepare("SELECT name, type, sex, age, colour, detail, DoC, Affection, Cost, Time, LifeSpan, Space, Loudness, Activeness, Obedience, Shedding, IntWithDog, IntWithCat, IntWithChild  FROM Animals");

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

            //Matching parameter/traits/non physical attr.
            int DoC = qry->value(6).toInt();
            int affection = qry->value(7).toInt();
            int cost = qry->value(8).toInt();
            int Time = qry->value(9).toInt();
            int lifespan = qry->value(10).toInt();
            int space = qry->value(11).toInt();
            int loudness = qry->value(12).toInt();
            int activeness = qry->value(13).toInt();
            int obedience = qry->value(14).toInt();
            int shedding = qry->value(15).toInt();
            int IntWithDog = qry->value(16).toInt();
            int IntWithCat = qry->value(17).toInt();
            int IntWithChild = qry->value(18).toInt();

            //Create QMAP for non phys. traits
            QMap<QString,int> attr;
            attr.insert("DoC",DoC);
            attr.insert("affection", affection);
            attr.insert("cost", cost);
            attr.insert("time", Time);
            attr.insert("lifespan", lifespan);
            attr.insert("space", space);
            attr.insert("loudness", loudness);
            attr.insert("activeness", activeness);
            attr.insert("obedience", obedience);
            attr.insert("shedding", shedding);
            attr.insert("intwithdog", IntWithDog);
            attr.insert("intwithcat", IntWithCat);
            attr.insert("intwithchild", IntWithChild);


            //Create instances of Animals and add to Vector of Animals
            if (type == "Dog") {
                Dog* newDog = new Dog(name, colour, age, sex[0], detail,attr);
                animals.insert(animals.end(), newDog);

            }
            else if (type == "Cat") {
                Cat* newCat = new Cat(name, colour, age, sex[0], detail,attr);
                animals.insert(animals.end(), newCat);

            }
            else if (type == "Bird") {
                Bird* newBird = new Bird(name, colour, age, sex[0], detail,attr);
                animals.insert(animals.end(), newBird);

            }
            else if (type == "Small Animal") {
                SmallAnimal* newSmallAnimal = new SmallAnimal(name, colour, age, sex[0], detail,attr);
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
    qry->prepare("SELECT Type,FirstName,LastName, Address, PhoneNumber, EmailAddress FROM Users");
    bool status;
    if(qry->exec()){
        status=true;
        while (qry->next()) {
            status = true;
            QString type = qry->value(0).toString();
            QString fname = qry->value(1).toString();
            QString lname = qry->value(2).toString();
            QString add = qry->value(3).toString();
            QString pnum = qry->value(4).toString();
            QString email = qry->value(5).toString();
            //qDebug() << type<< qry->value(1).toString()<<qry->value(3).toString()<<qry->value(4).toString()<<qry->value(5).toString()<<qry->value(6).toString();
                  if (type == "Client"){
                    //cout << "Client"<<endl;
                    Client* newClient = new Client(fname,lname,add,pnum,email);
                    clients.insert(clients.end(), newClient);
                  }else if (type =="Staff"){
                    //cout << "Staff"<<endl;
                    Staff* newStaff = new Staff(fname,lname,add,pnum,email);
                    staff.insert(staff.end(), newStaff);
                  }
        }
    }else{
        status = false;
    }
    for(size_t i=0;i<clients.size();i++){
        //qDebug()<<clients[i]->getFname();
    }
    delete qry;
    return status;
}

//return vector of animals
vector<Animal*>& Shelter::getAnimals() {return animals; }

//return vector of staff
vector<Staff*>& Shelter::getStaff()  { return staff; }
