#ifndef USER_H
#define USER_H
#include <string>
#include <QString>

using namespace std;

class User {

    public:
        User(QString, QString, QString, QString, QString);
        User(QString, QString, QString, QString);
        QString getFname() const;
        QString getLname() const;
        QString getAddress() const;
        QString getPhoneNumber() const;
        QString getEmail() const;

    protected:
        QString firstName;
        QString lastName;
        QString address;
        QString phoneNumber;
        QString emailAddress;
};

#endif
