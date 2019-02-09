#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "User.h"
#include <string>
#include <QString>

using namespace std;

class Client : public User {

    friend ostream& operator<<(ostream&, Client&);

    public:

        Client(QString="", QString="", QString="", QString="" ,QString="");

        //bool operator<(Client&);
        //bool operator>(Client&);


};

#endif
