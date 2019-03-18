#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

using namespace std;

class AbstractFactory {

  public:
    AnimalFactory* getAnimalFactory();
    UserFactory* getUserFactory();

};

#endif
