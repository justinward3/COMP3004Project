#include <iostream>
using namespace std;
#include "Client.h"


Client::Client(QString fname, QString lname, QString add, QString pnum, QString email) :
        User(fname,lname,add,pnum,email) { }


bool Client::operator<(Client& c)
{
    return lastName < c.lastName;
}

bool Client::operator>(Client& c)
{
    return lastName > c.lastName;
}

ostream& operator<<(ostream& output, Client& c)
{
    /*
    ostringstream name;
    name << c.firstName << " " << c.lastName;

    output << "Client " << endl << endl
           << "    Name: " << setw(40) << name.str() << endl
           << "    Address: " << setw(37) << c.address << endl
           << "    Phone Number: " << setw(32) << c.phoneNumber << endl
           << "    Email: " << setw(32) << c.emailAddress << endl;
           */
}
