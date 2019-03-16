#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <QString>
#include <QMap>

using namespace std;

class Animal {

  protected:
      QString name;
      QString colour;
      int age;
      QChar sex;
      QString detail;
      QMap<QString,int> traits;
      int id = -1;

    public:
        Animal(int,QString, QString, int, QChar, QString, QMap<QString,int>);
        virtual ~Animal() = 0;
        QString getName() const;
        QString getColour() const;
        int getAge() const;
        int getId() const;
        QChar getSex() const;
        QMap<QString,int> getTraits() const;
        QString getDetail() const;


};

#endif
