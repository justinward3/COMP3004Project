using namespace std;
#include <string>
#include "Cat.h"

Cat::Cat(QString na, QString col, int a, QChar s, QString t) :
            Animal(na,col,a,s,t){}

Cat::~Cat(){cout<<"Cat says goodbye"<<endl;}
