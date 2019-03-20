#ifndef ANIMALFACTORY_H
#define ANIMALFACTORY_H

#include "AbstractFactory.h"

using namespace std;

class AnimalFactory : public AbstractFactory {

  public:
    static Dog* createDog(QString, QString, int, QChar, QString, QMap<QString,int>,int);
    static Cat* createCat(QString, QString, int, QChar, QString, QMap<QString,int>,int);
    static Bird* createBird(QString, QString, int, QChar, QString, QMap<QString,int>,int);
    static SmallAnimal* createSmallAnimal(QString, QString, int, QChar, QString, QMap<QString,int>,int);


};

#endif
