#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

using namespace std;

class AbstractFactory {

  public:
    virtual Animal createAnimal() = 0;
    virtual User createUser() = 0;

};

#endif
