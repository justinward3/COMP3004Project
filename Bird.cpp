using namespace std;
#include <string>
#include "Bird.h"

Bird::Bird(QString na, QString col, int a, QChar s, QString t) :
    Animal(na,col,a,s,t){}

Bird::~Bird(){}
