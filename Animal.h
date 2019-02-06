#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Animal {

    friend ostream& operator<<(ostream&, Animal&);

  protected:
      string name;
      string colour;
      int age;
      char sex;
      string type;
      virtual string toString() const=0;


    public:
        Animal(string, string, int, char);
        //Animal(string, string, int);
        //~Animal();
        string getName() const;
        string getColour() const;
        int getAge() const;
        char getSex() const;
        //bool operator<(Animal&);
        //bool operator>(Animal&);


};

#endif
