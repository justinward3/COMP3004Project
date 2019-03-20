#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "SmallAnimal.h"
#include "User.h"
#include "Staff.h"
#include "Client.h"

using namespace std;

class AbstractFactory {

  public:
    virtual Dog* createDog() = 0;
    virtual Cat* createCat() = 0;
    virtual Bird* createBird() = 0;
    virtual SmallAnimal* createSmallAnimal() = 0;
    virtual Staff* createStaff() = 0;
    virtual Client* createClient() = 0;

};

#endif
