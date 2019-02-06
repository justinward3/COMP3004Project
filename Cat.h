#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "Animal.h"

using namespace std;

class Cat : public Animal{

    friend ostream& operator<<(ostream&, Cat&);

    private:
        virtual string toString() const;
        string breed;
    public:
        Cat(string, string, int, char,string);
        string getBreed() const;


};

#endif
