#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class Cat : public Animal{

    friend ostream& operator<<(ostream&, Cat&);

    private:
        virtual QString toString() const;
        QString breed;
    public:
        Cat(QString, QString, int, QChar, QString);
        QString getBreed() const;


};

#endif
