/********************************************************************************
** Form generated from reading UI file 'passwordscreen.ui'
**
** Created: Wed 6. May 17:14:17 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDSCREEN_H
#define UI_PASSWORDSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passwordscreen
{
public:
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_name;
    QLabel *label_credit;
    QLabel *label;
    QLineEdit *lineEdit_password;
    QGridLayout *gridLayout;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_back;
    QPushButton *pushButton_0;
    QPushButton *pushButton_login;

    void setupUi(QWidget *passwordscreen)
    {
        if (passwordscreen->objectName().isEmpty())
            passwordscreen->setObjectName(QString::fromUtf8("passwordscreen"));
        passwordscreen->resize(665, 310);
        gridLayout_2 = new QGridLayout(passwordscreen);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(passwordscreen);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/MyFiles/Natalie.jpg")));

        horizontalLayout->addWidget(label_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_name = new QLabel(passwordscreen);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        verticalLayout_2->addWidget(label_name);

        label_credit = new QLabel(passwordscreen);
        label_credit->setObjectName(QString::fromUtf8("label_credit"));

        verticalLayout_2->addWidget(label_credit);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        label = new QLabel(passwordscreen);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        lineEdit_password = new QLineEdit(passwordscreen);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));

        verticalLayout->addWidget(lineEdit_password);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_1 = new QPushButton(passwordscreen);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setFont(font);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(passwordscreen);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(passwordscreen);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(passwordscreen);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setFont(font);

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_5 = new QPushButton(passwordscreen);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(passwordscreen);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        pushButton_7 = new QPushButton(passwordscreen);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setFont(font);

        gridLayout->addWidget(pushButton_7, 2, 0, 1, 1);

        pushButton_8 = new QPushButton(passwordscreen);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font);

        gridLayout->addWidget(pushButton_8, 2, 1, 1, 1);

        pushButton_9 = new QPushButton(passwordscreen);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font);

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton_back = new QPushButton(passwordscreen);
        pushButton_back->setObjectName(QString::fromUtf8("pushButton_back"));
        sizePolicy.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy);
        pushButton_back->setFont(font);

        gridLayout->addWidget(pushButton_back, 3, 0, 1, 1);

        pushButton_0 = new QPushButton(passwordscreen);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy);
        pushButton_0->setFont(font);

        gridLayout->addWidget(pushButton_0, 3, 1, 1, 1);

        pushButton_login = new QPushButton(passwordscreen);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        sizePolicy.setHeightForWidth(pushButton_login->sizePolicy().hasHeightForWidth());
        pushButton_login->setSizePolicy(sizePolicy);
        pushButton_login->setFont(font);

        gridLayout->addWidget(pushButton_login, 3, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);

        retranslateUi(passwordscreen);

        QMetaObject::connectSlotsByName(passwordscreen);
    } // setupUi

    void retranslateUi(QWidget *passwordscreen)
    {
        passwordscreen->setWindowTitle(QApplication::translate("passwordscreen", "Form", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        label_name->setText(QString());
        label_credit->setText(QString());
        label->setText(QApplication::translate("passwordscreen", "Password", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("passwordscreen", "1", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("passwordscreen", "2", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("passwordscreen", "3", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("passwordscreen", "4", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("passwordscreen", "5", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("passwordscreen", "6", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("passwordscreen", "7", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("passwordscreen", "8", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("passwordscreen", "9", 0, QApplication::UnicodeUTF8));
        pushButton_back->setText(QApplication::translate("passwordscreen", "Back", 0, QApplication::UnicodeUTF8));
        pushButton_0->setText(QApplication::translate("passwordscreen", "0", 0, QApplication::UnicodeUTF8));
        pushButton_login->setText(QApplication::translate("passwordscreen", "Login", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class passwordscreen: public Ui_passwordscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDSCREEN_H
