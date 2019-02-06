#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <QString>
#include "Animal.h"

using namespace std;

class Dog : public Animal{

    friend ostream& operator<<(ostream&, Dog&);

    private:
        virtual QString toString() const;
        QString breed;
    public:
        Dog(QString, QString, int, QChar, QString);
        QString getBreed() const;


};

#endif
