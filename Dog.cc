using namespace std;
#include <string>
#include "Dog.h"

Dog::Dog(string na, string col, int a, char s, string b) :
            Animal(na,col,a,s)
{
  breed = b;
}

string  Dog::getBreed() const     { return breed; }

string Dog::toString() const
{
    ostringstream output;
    output << "Dog    :\t" <<endl;
    output << "Name   :\t" << name <<endl;
    output << "Sex    :\t" << sex <<endl;
    output << "Colour :\t" <<  colour <<endl;
    output << "Age    :\t " << age <<endl;

    return output.str();
}

/*
ostream& operator<<(ostream& output, Dog& d)
{
    /*
    ostringstream make_model;
    make_model << v.make << " " << v.model;

    output << "\t" << setw(7) << v.colour << " " << v.year << " " << setw(17);
    output << make_model.str() << " (" << v.mileage << "km)" << endl;

    return output << d.toString();
}
*/
