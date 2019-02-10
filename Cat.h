#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class Cat : public Animal{

    private:
        QString breed;
    public:
        Cat(QString, QString, int, QChar, QString);
        ~Cat();


};

#endif
