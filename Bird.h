#ifndef BIRD_H
#define BIRD_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class Bird : public Animal{

    private:
    //virtual QString toString() const;
    QString breed;

    public:
        Bird(QString, QString, int, QChar, QString);
        ~Bird();



};

#endif
