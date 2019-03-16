#ifndef SMALLANIMAL_H
#define SMALLANIMAL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class SmallAnimal : public Animal{
    public:
        SmallAnimal(QString, QString, int, QChar, QString, QMap<QString,int>,int);
        ~SmallAnimal();


};

#endif
