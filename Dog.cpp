using namespace std;
#include <string>
#include <QString>
#include "Dog.h"

Dog::Dog(QString na, QString col, int a, QChar s, QString t) :
            Animal(na,col,a,s,t){}

Dog::~Dog(){cout<<"dog says goodbye"<<endl;}
