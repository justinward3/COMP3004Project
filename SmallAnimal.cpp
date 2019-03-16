using namespace std;
#include <string>
#include "SmallAnimal.h"

SmallAnimal::SmallAnimal(QString na, QString col, int a, QChar s, QString t, QMap<QString,int> dict, int i) :
    Animal(i,na,col,a,s,t,dict){}

SmallAnimal::~SmallAnimal(){}
