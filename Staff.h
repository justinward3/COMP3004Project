#ifndef MECHANIC_H
#define MECHANIC_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include "User.h"

using namespace std;

class Staff : public User {

    friend ostream& operator<<(ostream&, Staff&);

    public:

        Staff(string="", string="", string="", string="", string="");
        bool operator<(Staff&);
        bool operator>(Staff&);

};

#endif
