#include <iostream>
using namespace std;
#include "Client.h"

Client::Client(QString fname, QString lname, QString add, QString pnum, QString email) :
        User(fname,lname,add,pnum,email) {
    prefs = QMap<QString,int>();
}

Client::Client(QString fname, QString lname, QString add, QString pnum, QString email, QMap<QString,int> p) :
        User(fname,lname,add,pnum,email) {
    prefs = p;
}

QMap<QString,int> Client::getMatchingPrefs(){
    return prefs;
}

void Client::setPrefs(QMap<QString,int> p){
    prefs = p;
}



