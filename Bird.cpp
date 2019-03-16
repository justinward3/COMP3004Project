using namespace std;
#include <string>
#include "Bird.h"

Bird::Bird(QString na, QString col, int a, QChar s, QString t, QMap<QString,int> dict, int i) :
    Animal(i,na,col,a,s,t,dict){}

Bird::~Bird(){}
