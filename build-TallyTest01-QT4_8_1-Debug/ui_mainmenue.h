/********************************************************************************
** Form generated from reading UI file 'mainmenue.ui'
**
** Created: Sun 3. May 17:59:05 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUE_H
#define UI_MAINMENUE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenue
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_Scannen;
    QPushButton *pushButton_Coffee;
    QPushButton *pushButton_Sweets;

    void setupUi(QWidget *MainMenue)
    {
        if (MainMenue->objectName().isEmpty())
            MainMenue->setObjectName(QString::fromUtf8("MainMenue"));
        MainMenue->resize(444, 172);
        gridLayout = new QGridLayout(MainMenue);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(50, -1, 50, -1);
        pushButton_Scannen = new QPushButton(MainMenue);
        pushButton_Scannen->setObjectName(QString::fromUtf8("pushButton_Scannen"));

        verticalLayout->addWidget(pushButton_Scannen);

        pushButton_Coffee = new QPushButton(MainMenue);
        pushButton_Coffee->setObjectName(QString::fromUtf8("pushButton_Coffee"));

        verticalLayout->addWidget(pushButton_Coffee);

        pushButton_Sweets = new QPushButton(MainMenue);
        pushButton_Sweets->setObjectName(QString::fromUtf8("pushButton_Sweets"));

        verticalLayout->addWidget(pushButton_Sweets);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(MainMenue);

        QMetaObject::connectSlotsByName(MainMenue);
    } // setupUi

    void retranslateUi(QWidget *MainMenue)
    {
        MainMenue->setWindowTitle(QApplication::translate("MainMenue", "Form", 0, QApplication::UnicodeUTF8));
        pushButton_Scannen->setText(QApplication::translate("MainMenue", "Scannen", 0, QApplication::UnicodeUTF8));
        pushButton_Coffee->setText(QApplication::translate("MainMenue", "Coffee", 0, QApplication::UnicodeUTF8));
        pushButton_Sweets->setText(QApplication::translate("MainMenue", "Sweets", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainMenue: public Ui_MainMenue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUE_H
