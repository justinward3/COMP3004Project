#include <string>
using namespace std;
#include "User.h"

User::User(QString fname, QString lname, QString add, QString pnum, QString email) :
        firstName(fname), lastName(lname), address(add), phoneNumber(pnum) ,emailAddress(email){ }

QString User::getFname() const        { return firstName; }
QString User::getLname() const        { return lastName; }
QString User::getAddress() const      { return address; }
QString User::getPhoneNumber() const  { return phoneNumber; }
QString User::getEmail() const        { return emailAddress;}
