#ifndef USER_H
#define USER_H
#include <string>

using namespace std;

class User {

    public:
        User(string, string, string, string, string);
        User(string, string, string, string);
        string getFname() const;
        string getLname() const;
        string getAddress() const;
        string getPhoneNumber() const;
        string getEmail() const;

    protected:
        string firstName;
        string lastName;
        string address;
        string phoneNumber;
        string emailAddress;
};

#endif
