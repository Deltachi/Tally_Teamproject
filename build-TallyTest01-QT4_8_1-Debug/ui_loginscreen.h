/********************************************************************************
** Form generated from reading UI file 'loginscreen.ui'
**
** Created: Sun 3. May 19:22:24 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINSCREEN_H
#define UI_LOGINSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginScreen
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    QWidget *widget_keyboardPort;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_0;
    QPushButton *pushButton_2;
    QPushButton *pushButton_loeschen;
    QPushButton *pushButton_9;
    QPushButton *pushButton_1;
    QPushButton *pushButton_8;
    QPushButton *pushButton_Weiter;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QWidget *LoginScreen)
    {
        if (LoginScreen->objectName().isEmpty())
            LoginScreen->setObjectName(QString::fromUtf8("LoginScreen"));
        LoginScreen->resize(837, 485);
        horizontalLayout_2 = new QHBoxLayout(LoginScreen);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(LoginScreen);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(LoginScreen);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(LoginScreen);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        widget_keyboardPort = new QWidget(LoginScreen);
        widget_keyboardPort->setObjectName(QString::fromUtf8("widget_keyboardPort"));
        gridLayout = new QGridLayout(widget_keyboardPort);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_4 = new QPushButton(widget_keyboardPort);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        pushButton_4->setFont(font);

        gridLayout->addWidget(pushButton_4, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(widget_keyboardPort);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setFont(font);

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_7 = new QPushButton(widget_keyboardPort);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setFont(font);

        gridLayout->addWidget(pushButton_7, 4, 0, 1, 1);

        pushButton_0 = new QPushButton(widget_keyboardPort);
        pushButton_0->setObjectName(QString::fromUtf8("pushButton_0"));
        sizePolicy.setHeightForWidth(pushButton_0->sizePolicy().hasHeightForWidth());
        pushButton_0->setSizePolicy(sizePolicy);
        pushButton_0->setFont(font);

        gridLayout->addWidget(pushButton_0, 5, 1, 1, 1);

        pushButton_2 = new QPushButton(widget_keyboardPort);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setFont(font);

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_loeschen = new QPushButton(widget_keyboardPort);
        pushButton_loeschen->setObjectName(QString::fromUtf8("pushButton_loeschen"));
        sizePolicy.setHeightForWidth(pushButton_loeschen->sizePolicy().hasHeightForWidth());
        pushButton_loeschen->setSizePolicy(sizePolicy);
        pushButton_loeschen->setFont(font);

        gridLayout->addWidget(pushButton_loeschen, 5, 0, 1, 1);

        pushButton_9 = new QPushButton(widget_keyboardPort);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setFont(font);

        gridLayout->addWidget(pushButton_9, 4, 2, 1, 1);

        pushButton_1 = new QPushButton(widget_keyboardPort);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        sizePolicy.setHeightForWidth(pushButton_1->sizePolicy().hasHeightForWidth());
        pushButton_1->setSizePolicy(sizePolicy);
        pushButton_1->setFont(font);

        gridLayout->addWidget(pushButton_1, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(widget_keyboardPort);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setFont(font);

        gridLayout->addWidget(pushButton_8, 4, 1, 1, 1);

        pushButton_Weiter = new QPushButton(widget_keyboardPort);
        pushButton_Weiter->setObjectName(QString::fromUtf8("pushButton_Weiter"));
        sizePolicy.setHeightForWidth(pushButton_Weiter->sizePolicy().hasHeightForWidth());
        pushButton_Weiter->setSizePolicy(sizePolicy);
        pushButton_Weiter->setFont(font);

        gridLayout->addWidget(pushButton_Weiter, 5, 2, 1, 1);

        pushButton_5 = new QPushButton(widget_keyboardPort);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);
        pushButton_5->setFont(font);

        gridLayout->addWidget(pushButton_5, 2, 1, 1, 1);

        pushButton_6 = new QPushButton(widget_keyboardPort);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy);
        pushButton_6->setFont(font);

        gridLayout->addWidget(pushButton_6, 2, 2, 1, 1);


        horizontalLayout_2->addWidget(widget_keyboardPort);

        horizontalLayout_2->setStretch(1, 1);

        retranslateUi(LoginScreen);

        QMetaObject::connectSlotsByName(LoginScreen);
    } // setupUi

    void retranslateUi(QWidget *LoginScreen)
    {
        LoginScreen->setWindowTitle(QApplication::translate("LoginScreen", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("LoginScreen", "Name", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("LoginScreen", "Penis", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("LoginScreen", "Anne Bar", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("LoginScreen", "Hans", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("LoginScreen", "Gruber", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("LoginScreen", "Peter Lustig", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("LoginScreen", "Peter nicht lustig", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("LoginScreen", "Herbertz", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("LoginScreen", "Brunhilde", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("LoginScreen", "Hardi", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("LoginScreen", "Peter", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("LoginScreen", "Witcher", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("LoginScreen", "Robin", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("LoginScreen", "Adolf", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("LoginScreen", "Vagina", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("LoginScreen", "Regina", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton_4->setText(QApplication::translate("LoginScreen", "4GHI", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("LoginScreen", "3DEF", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("LoginScreen", "7PQRS", 0, QApplication::UnicodeUTF8));
        pushButton_0->setText(QApplication::translate("LoginScreen", "0", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("LoginScreen", "2ABC", 0, QApplication::UnicodeUTF8));
        pushButton_loeschen->setText(QApplication::translate("LoginScreen", "L\303\266schen", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("LoginScreen", "9WXYZ", 0, QApplication::UnicodeUTF8));
        pushButton_1->setText(QApplication::translate("LoginScreen", "1", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("LoginScreen", "8TUV", 0, QApplication::UnicodeUTF8));
        pushButton_Weiter->setText(QApplication::translate("LoginScreen", "Weiter", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("LoginScreen", "5JKL", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("LoginScreen", "6MNO", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginScreen: public Ui_LoginScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINSCREEN_H
