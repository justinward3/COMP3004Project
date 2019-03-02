#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class Dog : public Animal{
    public:
        Dog(QString, QString, int, QChar, QString, QDict);
        ~Dog();


};

#endif
