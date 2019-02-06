#include <string>
using namespace std;
#include "User.h"

User::User(string fname, string lname, string add, string pnum, string email) :
        firstName(fname), lastName(lname), address(add), phoneNumber(pnum) ,emailAddress(email){ }

User::User(string fname, string lname, string add, string pnum) :
                firstName(fname), lastName(lname), address(add), phoneNumber(pnum), emailAddress(firstName +"."+lastName+"@gmail.com"){ }

string User::getFname() const        { return firstName; }
string User::getLname() const        { return lastName; }
string User::getAddress() const      { return address; }
string User::getPhoneNumber() const  { return phoneNumber; }
string User::getEmail() const        { return emailAddress;}
