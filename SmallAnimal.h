#ifndef SMALLANIMAL_H
#define SMALLANIMAL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class SmallAnimal : public Animal{

    friend ostream& operator<<(ostream&, SmallAnimal&);

    private:
        virtual QString toString() const;
        //QString breed;
    public:
        SmallAnimal(QString, QString, int, QChar, QString);
        //QString getBreed() const;


};

#endif
