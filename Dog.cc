using namespace std;
#include <string>
#include <QString>
#include "Dog.h"

Dog::Dog(QString na, QString col, int a, QChar s, QString t) :
            Animal(na,col,a,s,t){}

//QString  Dog::getBreed() const     { return breed; }

QString Dog::toString() const
{
//    ostringstream output;
//    output << "Dog    :\t" <<endl;
//    output << "Name   :\t" << name <<endl;
//    output << "Sex    :\t" << sex <<endl;
//    output << "Colour :\t" <<  colour <<endl;
//    output << "Age    :\t " << age <<endl;

//    return output.str();
}
