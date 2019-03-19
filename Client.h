#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "User.h"
#include <string>
#include <QString>
#include <QMap>

using namespace std;

class Client : public User {

    public:
        Client(QString="", QString="", QString="", QString="" ,QString="");
        Client(QString, QString, QString, QString ,QString ,QMap<QString,int>);
        QMap<QString,int> getMatchingPrefs();
        void setPrefs(QMap<QString,int>);
    protected:
        QMap<QString,int> prefs;

};

#endif
