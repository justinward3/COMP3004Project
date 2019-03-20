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
    staffwindow.cpp \
    Animal.cpp \
    Bird.cpp \
    Cat.cpp \
    Client.cpp \
    Dog.cpp \
    Shelter.cpp \
    SmallAnimal.cpp \
    Staff.cpp \
    User.cpp \
    clientwindow.cpp \
    animalAddEditControl.cpp \
    animalViewControl.cpp \
    clientAddViewControl.cpp \
    clientEditControl.cpp \
    AnimalFactory.cpp \
    UserFactory.cpp \
    addStaffControl.cpp \
    clientListControl.cpp \
    animalListControl.cpp \
    mainWindow.cpp

HEADERS += \
    staffwindow.h \
    Animal.h \
    Cat.h \
    Client.h \
    Dog.h \
    Shelter.h \
    Staff.h \
    User.h \
    Bird.h \
    SmallAnimal.h \
    clientwindow.h \
    animalAddEditControl.h \
    animalViewControl.h \
    animalListView.h \
    clientAddViewControl.h \
    clientEditControl.h \
    AbstractFactory.h \
    AnimalFactory.h \
    UserFactory.h \
    addStaffControl.h \
    clientListControl.h \
    mainWindow.h

FORMS += \
    menu.ui \
    animalDetailView.ui \
    animalListView.ui \
    clientDetailView.ui \
    addStaffView.ui \
    clientListView.ui \
    mainWindow.ui
