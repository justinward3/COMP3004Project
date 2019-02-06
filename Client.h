#ifndef Client_H
#define Client_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "User.h"

using namespace std;

class Client : public User {

    friend ostream& operator<<(ostream&, Client&);

    public:

        Client(string="", string="", string="", string="" ,string="");

        bool operator<(Client&);
        bool operator>(Client&);


};

#endif
