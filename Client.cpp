#include <iostream>
using namespace std;
#include "Client.h"


Client::Client(QString fname, QString lname, QString add, QString pnum, QString email) :
        User(fname,lname,add,pnum,email) { }

/*
bool Client::operator<(Client& c)
{
    return lastName < c.lastName;
}

bool Client::operator>(Client& c)
{
    return lastName > c.lastName;
}
*/

