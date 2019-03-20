#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "AbstractFactory.h"
#include "User.h"
#include "Staff.h"
#include "Client.h"

using namespace std;

class UserFactory: public AbstractFactory{

  public:
    static Staff* createStaff(QString, QString, QString, QString, QString);
    static Client* createClient(QString, QString, QString, QString, QString);

};

#endif
