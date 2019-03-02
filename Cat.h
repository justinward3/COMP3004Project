#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class Cat : public Animal{

    public:
        Cat(QString, QString, int, QChar, QString, QMap<QString,int>);
        ~Cat();


};

#endif
