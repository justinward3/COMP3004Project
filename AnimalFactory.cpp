#include <iostream>
using namespace std;
#include "AnimalFactory.h"

Dog* AnimalFactory::createDog(QString na, QString col, int a, QChar s, QString d, QMap<QString,int> dict, int i){
     Dog* animal = new Dog(na, col, a, s, d, dict, i);
     return animal;
}

Cat* AnimalFactory::createCat(QString na, QString col, int a, QChar s, QString d, QMap<QString,int> dict, int i){
    Cat* animal = new Cat(na, col, a, s, d, dict, i);
    return animal;
}

Bird* AnimalFactory::createBird(QString na, QString col, int a, QChar s, QString d, QMap<QString,int> dict, int i){
  Bird* animal = new Bird(na, col, a, s, d, dict, i);
  return animal;
}

SmallAnimal* AnimalFactory::createSmallAnimal(QString na, QString col, int a, QChar s, QString d, QMap<QString,int> dict, int i){
  SmallAnimal* animal = new SmallAnimal(na, col, a, s, d, dict, i);
  return animal;
}
