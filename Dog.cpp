using namespace std;
#include <string>
#include "Dog.h"

Dog::Dog(QString na, QString col, int a, QChar s, QString t, QDict dict) :
            Animal(na,col,a,s,t,dict){}

Dog::~Dog(){}
