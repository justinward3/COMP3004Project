/********************************************************************************
** Form generated from reading UI file 'viewanimal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWANIMAL_H
#define UI_VIEWANIMAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addAnimal
{
public:
    QGroupBox *groupBox;
    QPushButton *backButton;
    QPushButton *editButton;
    QLabel *label;
    QWidget *fieldsWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QLineEdit *animalName;
    QLabel *label_3;
    QComboBox *animalType;
    QLabel *label_7;
    QLineEdit *animalDetail;
    QLabel *label_4;
    QComboBox *animalSex;
    QLineEdit *animalAge;
    QLabel *label_5;
    QLineEdit *animalColour;
    QLabel *label_6;
    QLabel *label_8;
    QLineEdit *animalLifespan;
    QComboBox *animalDifficulty;
    QLabel *label_9;
    QComboBox *animalAffection;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *animalCost;
    QLineEdit *animalTime;
    QLabel *label_12;
    QLabel *label_13;
    QComboBox *animalSpace;
    QLabel *label_14;
    QComboBox *animalLoudness;
    QLabel *label_15;
    QComboBox *animalActiveness;
    QLabel *label_16;
    QGroupBox *animalIntegration;
    QCheckBox *dogCheckBox;
    QCheckBox *childCheckBox;
    QCheckBox *catCheckBox;
    QLabel *label_17;
    QComboBox *animalObedience;
    QLabel *label_18;
    QComboBox *animalShedding;
    QButtonGroup *animalButtonGroup;

    void setupUi(QDialog *addAnimal)
    {
        if (addAnimal->objectName().isEmpty())
            addAnimal->setObjectName(QStringLiteral("addAnimal"));
        addAnimal->resize(600, 400);
        groupBox = new QGroupBox(addAnimal);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(410, 20, 161, 361));
        backButton = new QPushButton(groupBox);
        backButton->setObjectName(QStringLiteral("backButton"));
        backButton->setGeometry(QRect(10, 80, 141, 25));
        editButton = new QPushButton(groupBox);
        editButton->setObjectName(QStringLiteral("editButton"));
        editButton->setGeometry(QRect(10, 40, 141, 25));
        editButton->raise();
        backButton->raise();
        label = new QLabel(addAnimal);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 20, 171, 31));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setLineWidth(0);
        label->setAlignment(Qt::AlignCenter);
        fieldsWidget = new QWidget(addAnimal);
        fieldsWidget->setObjectName(QStringLiteral("fieldsWidget"));
        fieldsWidget->setGeometry(QRect(20, 50, 371, 331));
        scrollArea = new QScrollArea(fieldsWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 371, 331));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setMinimumSize(QSize(371, 0));
        scrollArea->setMaximumSize(QSize(371, 10000000));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 355, 669));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 20, 51, 21));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        animalName = new QLineEdit(scrollAreaWidgetContents);
        animalName->setObjectName(QStringLiteral("animalName"));
        animalName->setGeometry(QRect(80, 20, 141, 25));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 64, 21));
        animalType = new QComboBox(scrollAreaWidgetContents);
        animalType->setObjectName(QStringLiteral("animalType"));
        animalType->setGeometry(QRect(80, 60, 141, 25));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 100, 64, 21));
        animalDetail = new QLineEdit(scrollAreaWidgetContents);
        animalDetail->setObjectName(QStringLiteral("animalDetail"));
        animalDetail->setGeometry(QRect(80, 100, 261, 25));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(240, 20, 41, 21));
        animalSex = new QComboBox(scrollAreaWidgetContents);
        animalSex->setObjectName(QStringLiteral("animalSex"));
        animalSex->setGeometry(QRect(290, 20, 51, 25));
        animalAge = new QLineEdit(scrollAreaWidgetContents);
        animalAge->setObjectName(QStringLiteral("animalAge"));
        animalAge->setGeometry(QRect(80, 180, 81, 25));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 180, 64, 21));
        animalColour = new QLineEdit(scrollAreaWidgetContents);
        animalColour->setObjectName(QStringLiteral("animalColour"));
        animalColour->setGeometry(QRect(80, 140, 261, 25));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 140, 64, 21));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(180, 180, 64, 21));
        animalLifespan = new QLineEdit(scrollAreaWidgetContents);
        animalLifespan->setObjectName(QStringLiteral("animalLifespan"));
        animalLifespan->setGeometry(QRect(260, 180, 81, 25));
        animalDifficulty = new QComboBox(scrollAreaWidgetContents);
        animalDifficulty->setObjectName(QStringLiteral("animalDifficulty"));
        animalDifficulty->setGeometry(QRect(140, 220, 201, 25));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 220, 121, 21));
        animalAffection = new QComboBox(scrollAreaWidgetContents);
        animalAffection->setObjectName(QStringLiteral("animalAffection"));
        animalAffection->setGeometry(QRect(140, 260, 201, 25));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 260, 121, 21));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(13, 300, 181, 21));
        animalCost = new QLineEdit(scrollAreaWidgetContents);
        animalCost->setObjectName(QStringLiteral("animalCost"));
        animalCost->setGeometry(QRect(200, 300, 141, 25));
        animalTime = new QLineEdit(scrollAreaWidgetContents);
        animalTime->setObjectName(QStringLiteral("animalTime"));
        animalTime->setGeometry(QRect(200, 340, 91, 25));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 340, 191, 21));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(300, 340, 41, 21));
        animalSpace = new QComboBox(scrollAreaWidgetContents);
        animalSpace->setObjectName(QStringLiteral("animalSpace"));
        animalSpace->setGeometry(QRect(140, 380, 201, 25));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 380, 121, 21));
        animalLoudness = new QComboBox(scrollAreaWidgetContents);
        animalLoudness->setObjectName(QStringLiteral("animalLoudness"));
        animalLoudness->setGeometry(QRect(140, 420, 201, 25));
        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 420, 121, 21));
        animalActiveness = new QComboBox(scrollAreaWidgetContents);
        animalActiveness->setObjectName(QStringLiteral("animalActiveness"));
        animalActiveness->setGeometry(QRect(140, 460, 201, 25));
        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 460, 121, 21));
        animalIntegration = new QGroupBox(scrollAreaWidgetContents);
        animalIntegration->setObjectName(QStringLiteral("animalIntegration"));
        animalIntegration->setGeometry(QRect(10, 510, 331, 61));
        dogCheckBox = new QCheckBox(animalIntegration);
        animalButtonGroup = new QButtonGroup(addAnimal);
        animalButtonGroup->setObjectName(QStringLiteral("animalButtonGroup"));
        animalButtonGroup->setExclusive(false);
        animalButtonGroup->addButton(dogCheckBox);
        dogCheckBox->setObjectName(QStringLiteral("dogCheckBox"));
        dogCheckBox->setGeometry(QRect(10, 30, 61, 23));
        childCheckBox = new QCheckBox(animalIntegration);
        animalButtonGroup->addButton(childCheckBox);
        childCheckBox->setObjectName(QStringLiteral("childCheckBox"));
        childCheckBox->setGeometry(QRect(150, 30, 81, 23));
        catCheckBox = new QCheckBox(animalIntegration);
        animalButtonGroup->addButton(catCheckBox);
        catCheckBox->setObjectName(QStringLiteral("catCheckBox"));
        catCheckBox->setGeometry(QRect(80, 30, 51, 23));
        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 590, 121, 21));
        animalObedience = new QComboBox(scrollAreaWidgetContents);
        animalObedience->setObjectName(QStringLiteral("animalObedience"));
        animalObedience->setGeometry(QRect(140, 590, 201, 25));
        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 630, 121, 21));
        animalShedding = new QComboBox(scrollAreaWidgetContents);
        animalShedding->setObjectName(QStringLiteral("animalShedding"));
        animalShedding->setGeometry(QRect(140, 630, 201, 25));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(addAnimal);

        animalActiveness->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(addAnimal);
    } // setupUi

    void retranslateUi(QDialog *addAnimal)
    {
        addAnimal->setWindowTitle(QApplication::translate("addAnimal", "Add Animal", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("addAnimal", "Menu", Q_NULLPTR));
        backButton->setText(QApplication::translate("addAnimal", "Back", Q_NULLPTR));
        editButton->setText(QApplication::translate("addAnimal", "Edit", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("addAnimal", "Name:", Q_NULLPTR));
        label_3->setText(QApplication::translate("addAnimal", "Type:", Q_NULLPTR));
        animalType->clear();
        animalType->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "Dog", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Cat", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Bird", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Small Animal", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("addAnimal", "Detail:", Q_NULLPTR));
        label_4->setText(QApplication::translate("addAnimal", "Sex:", Q_NULLPTR));
        animalSex->clear();
        animalSex->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "M", Q_NULLPTR)
         << QApplication::translate("addAnimal", "F", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("addAnimal", "Age:", Q_NULLPTR));
        label_6->setText(QApplication::translate("addAnimal", "Colour:", Q_NULLPTR));
        label_8->setText(QApplication::translate("addAnimal", "Lifespan:", Q_NULLPTR));
        animalDifficulty->clear();
        animalDifficulty->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "Easy", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Intermediate", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Difficult", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("addAnimal", "Difficulty of Care:", Q_NULLPTR));
        animalAffection->clear();
        animalAffection->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "Little", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Moderate", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Lots", Q_NULLPTR)
        );
        label_10->setText(QApplication::translate("addAnimal", "Affection Needed:", Q_NULLPTR));
        label_11->setText(QApplication::translate("addAnimal", "Average Cost per Year:     $", Q_NULLPTR));
        label_12->setText(QApplication::translate("addAnimal", "Time Commitment per Day:", Q_NULLPTR));
        label_13->setText(QApplication::translate("addAnimal", "hours", Q_NULLPTR));
        animalSpace->clear();
        animalSpace->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "Little Space", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Moderate Space", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Lots of Space", Q_NULLPTR)
        );
        label_14->setText(QApplication::translate("addAnimal", "Space Needed:", Q_NULLPTR));
        animalLoudness->clear();
        animalLoudness->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "No Noise", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Little Noise", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Moderate Noise", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Lots of Noise", Q_NULLPTR)
        );
        label_15->setText(QApplication::translate("addAnimal", "Noise Made:", Q_NULLPTR));
        animalActiveness->clear();
        animalActiveness->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "None", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Little", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Moderate", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Lots", Q_NULLPTR)
        );
        label_16->setText(QApplication::translate("addAnimal", "Activity Required:", Q_NULLPTR));
        animalIntegration->setTitle(QApplication::translate("addAnimal", "Integration", Q_NULLPTR));
        dogCheckBox->setText(QApplication::translate("addAnimal", "Dog", Q_NULLPTR));
        childCheckBox->setText(QApplication::translate("addAnimal", "Children", Q_NULLPTR));
        catCheckBox->setText(QApplication::translate("addAnimal", "Cat", Q_NULLPTR));
        label_17->setText(QApplication::translate("addAnimal", "Obedience Level:", Q_NULLPTR));
        animalObedience->clear();
        animalObedience->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "Untrained", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Somewhat Trained", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Trained", Q_NULLPTR)
        );
        label_18->setText(QApplication::translate("addAnimal", "Animal Shedding:", Q_NULLPTR));
        animalShedding->clear();
        animalShedding->insertItems(0, QStringList()
         << QApplication::translate("addAnimal", "None", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Little", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Moderate", Q_NULLPTR)
         << QApplication::translate("addAnimal", "Lots", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class addAnimal: public Ui_addAnimal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWANIMAL_H
