#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class Dog : public Animal{

    friend ostream& operator<<(ostream&, Dog&);

    private:
        virtual string toString() const;
        string breed;
    public:
        Dog(string, string, int, char,string);
        string getBreed() const;


};

#endif
