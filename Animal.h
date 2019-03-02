#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <QString>

using namespace std;

class Animal {

  protected:
      QString name;
      QString colour;
      int age;
      QChar sex;
      QString detail;
      QDict<int> traits;

    public:
        Animal(QString, QString, int, QChar, QString);
        virtual ~Animal() = 0;
        QString getName() const;
        QString getColour() const;
        int getAge() const;
        QChar getSex() const;
        QDict<int> getTraits() const;
        QString getDetail() const;


};

#endif
