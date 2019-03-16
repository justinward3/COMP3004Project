using namespace std;
#include <string>
#include "Dog.h"

Dog::Dog(QString na, QString col, int a, QChar s, QString t, QMap<QString,int> dict, int i) :
            Animal(i,na,col,a,s,t,dict){}

Dog::~Dog(){}
