#include "Animal.h"

Animal::Animal(string na, string col, int a, char s) {
    name = na;
    age = a;
    colour = col;
    sex = s;
}

string  Animal::getName() const     { return name; }
int  Animal::getAge() const    { return age; }
string  Animal::getColour() const   { return colour; }
char Animal::getSex() const        {return sex; }



ostream& operator<<(ostream& output, Animal& a)
{
    return output << a.toString();
}
