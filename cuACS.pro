#-------------------------------------------------
#
# Project created by QtCreator 2019-02-02T15:19:24
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cuACS
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    staffwindow.cpp \
    addanimal.cpp \
    viewanimals.cpp \
    Animal.cc \
    Cat.cc \
    Client.cc \
    Dog.cc \
    Shelter.cc \
    Staff.cc \
    User.cc

HEADERS += \
        mainwindow.h \
    staffwindow.h \
    viewanimals.h \
    addanimal.h \
    Animal.h \
    Cat.h \
    Client.h \
    Dog.h \
    Shelter.h \
    Staff.h \
    User.h

FORMS += \
        mainwindow.ui \
    staffwindow.ui \
    viewanimals.ui \
    addanimal.ui
