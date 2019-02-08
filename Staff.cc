#include <iostream>
using namespace std;
#include "Staff.h"

Staff::Staff(QString fname, QString lname, QString add, QString pnum, QString email) :
        User(fname,lname,add,pnum,email) { }

ostream& operator<<(ostream& output, Staff& m)
{
    /*
    ostringstream name;
    name << m.firstName << " " << m.lastName;

    output << "Employee " << endl << endl
           << "    Name: " << setw(40) << name.str() << endl
           << "    Address: " << setw(37) << m.address << endl
           << "    Phone Number: " << setw(32) << m.phoneNumber << endl
           << "    Email: " << setw(38) << m.emailAddress << endl;
    return output;
    */
}



bool Staff::operator<(Staff& c) { return true; }

bool Staff::operator>(Staff& c) { return false; }
