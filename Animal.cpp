#include "Animal.h"

Animal::Animal(QString na, QString col, int a, QChar s, QString d, QMap<QString,int> dict) {
    name = na;
    age = a;
    colour = col;
    sex = s;
    detail = d;
    //matching parameter/traits dictionary
    traits = dict;
}
Animal::~Animal(){}

QString  Animal::getName() const     { return name; }
int  Animal::getAge() const    { return age; }
QString  Animal::getColour() const   { return colour; }
QChar Animal::getSex() const        {return sex; }
QMap<QString,int> Animal::getTraits() const    {return traits; }
QString Animal::getDetail() const     {return detail; }

