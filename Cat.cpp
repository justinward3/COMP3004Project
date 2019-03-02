using namespace std;
#include <string>
#include "Cat.h"

Cat::Cat(QString na, QString col, int a, QChar s, QString t, QMap<QString,int> dict) :
            Animal(na,col,a,s,t,dict){}

Cat::~Cat(){}
