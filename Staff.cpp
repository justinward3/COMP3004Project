#include <iostream>
using namespace std;
#include "Staff.h"

Staff::Staff(QString fname, QString lname, QString add, QString pnum, QString email) :
        User(fname,lname,add,pnum,email) { }




/*
bool Staff::operator<(Staff& c) { return true; }

bool Staff::operator>(Staff& c) { return false; }
*/
