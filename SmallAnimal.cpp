using namespace std;
#include <string>
#include "SmallAnimal.h"

SmallAnimal::SmallAnimal(QString na, QString col, int a, QChar s, QString t) :
    Animal(na,col,a,s,t){}

SmallAnimal::~SmallAnimal(){cout<<"small animal says goodbye"<<endl;}


