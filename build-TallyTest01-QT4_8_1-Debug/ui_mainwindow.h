/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 4. May 14:42:30 2015
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_pic;
    QLabel *label_username;
    QVBoxLayout *verticalLayoutDate;
    QLabel *label_Time;
    QLabel *label_Date;
    QGridLayout *gridLayout_port;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(683, 352);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(20);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        label_pic = new QLabel(centralWidget);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_pic->sizePolicy().hasHeightForWidth());
        label_pic->setSizePolicy(sizePolicy);
        label_pic->setMaximumSize(QSize(200, 100));
        label_pic->setPixmap(QPixmap(QString::fromUtf8(":/MyFiles/Tally CS - Logo beta.png")));
        label_pic->setScaledContents(true);
        label_pic->setMargin(0);

        horizontalLayout_3->addWidget(label_pic);

        label_username = new QLabel(centralWidget);
        label_username->setObjectName(QString::fromUtf8("label_username"));
        QFont font;
        font.setPointSize(15);
        label_username->setFont(font);
        label_username->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_username);

        verticalLayoutDate = new QVBoxLayout();
        verticalLayoutDate->setSpacing(6);
        verticalLayoutDate->setObjectName(QString::fromUtf8("verticalLayoutDate"));
        label_Time = new QLabel(centralWidget);
        label_Time->setObjectName(QString::fromUtf8("label_Time"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_Time->sizePolicy().hasHeightForWidth());
        label_Time->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(20);
        label_Time->setFont(font1);
        label_Time->setLayoutDirection(Qt::RightToLeft);
        label_Time->setTextFormat(Qt::AutoText);
        label_Time->setScaledContents(false);
        label_Time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayoutDate->addWidget(label_Time);

        label_Date = new QLabel(centralWidget);
        label_Date->setObjectName(QString::fromUtf8("label_Date"));
        sizePolicy1.setHeightForWidth(label_Date->sizePolicy().hasHeightForWidth());
        label_Date->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(20);
        font2.setStrikeOut(false);
        label_Date->setFont(font2);
        label_Date->setLayoutDirection(Qt::RightToLeft);
        label_Date->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayoutDate->addWidget(label_Date);

        verticalLayoutDate->setStretch(0, 1);
        verticalLayoutDate->setStretch(1, 1);

        horizontalLayout_3->addLayout(verticalLayoutDate);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_3);

        gridLayout_port = new QGridLayout();
        gridLayout_port->setSpacing(6);
        gridLayout_port->setObjectName(QString::fromUtf8("gridLayout_port"));

        verticalLayout->addLayout(gridLayout_port);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 200);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tally", 0, QApplication::UnicodeUTF8));
        label_pic->setText(QString());
        label_username->setText(QString());
        label_Time->setText(QApplication::translate("MainWindow", "16:00", 0, QApplication::UnicodeUTF8));
        label_Date->setText(QApplication::translate("MainWindow", "16.1.2015", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
