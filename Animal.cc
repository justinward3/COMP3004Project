#include "Animal.h"

Animal::Animal(QString na, QString col, int a, QChar s) {
    name = na;
    age = a;
    colour = col;
    sex = s;
}

QString  Animal::getName() const     { return name; }
int  Animal::getAge() const    { return age; }
QString  Animal::getColour() const   { return colour; }
QChar Animal::getSex() const        {return sex; }



ostream& operator<<(ostream& output, Animal& a)
{
    //return output << a.toString();
}
