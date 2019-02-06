using namespace std;
#include <string>
#include "Cat.h"

Cat::Cat(string na, string col, int a, char s, string b) :
            Animal(na,col,a,s)
{
  breed = b;
}

string  Cat::getBreed() const     { return breed; }

string Cat::toString() const
{
    ostringstream output;
    output << "Cat    \t" <<endl;
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
