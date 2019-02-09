#include "Animal.h"

Animal::Animal(QString na, QString col, int a, QChar s, QString d) {
    name = na;
    age = a;
    colour = col;
    sex = s;
    detail = d;
}
Animal::~Animal(){ cout<< "animal deconstructor"<<endl;}

QString  Animal::getName() const     { return name; }
int  Animal::getAge() const    { return age; }
QString  Animal::getColour() const   { return colour; }
QChar Animal::getSex() const        {return sex; }
QString Animal::getDetail() const     {return detail; }


