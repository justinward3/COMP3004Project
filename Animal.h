#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <QString>

using namespace std;

class Animal {

    //friend ostream& operator<<(ostream&, Animal&);

  protected:
      QString name;
      QString colour;
      int age;
      QChar sex;
      QString detail;
      //virtual QString toString() const=0;


    public:
        Animal(QString, QString, int, QChar, QString);
        //Animal(string, string, int);
        virtual ~Animal() = 0;
        QString getName() const;
        QString getColour() const;
        int getAge() const;
        QChar getSex() const;
        QString getDetail() const;
        //bool operator<(Animal&);
        //bool operator>(Animal&);


};

#endif
