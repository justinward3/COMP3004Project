#include <iostream>
using namespace std;
#include "UserFactory.h"

Staff* UserFactory::createStaff(QString fname, QString lname, QString add, QString pnum, QString email){
  Staff* user = new Staff(fname,lname,add,pnum,email);
  return user;
}

Client* UserFactory::createClient(QString fname, QString lname, QString add, QString pnum, QString email){
    Client* user = new Client(fname,lname,add,pnum,email);
    return user;
}
