#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T16:03:44
#
#-------------------------------------------------

QT       += core gui sql
QT+=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TallyTest01
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginscreen.cpp \
    sqlzugriff.cpp \
    passwordscreen.cpp \
    coffesweetsscann.cpp \
    buywidget.cpp \
    shoppingcart.cpp \
    scanwidget.cpp \
    favcart.cpp \
    afterbuyscreen.cpp \
    showipscreen.cpp \
    favwidget.cpp \
    settingswidget.cpp

HEADERS  += mainwindow.h \
    loginscreen.h \
    sqlzugriff.h \
    passwordscreen.h \
    coffesweetsscann.h \
    buywidget.h \
    shoppingcart.h \
    scanwidget.h \
    favcart.h \
    afterbuyscreen.h \
    showipscreen.h \
    favwidget.h \
    settingswidget.h

FORMS    += mainwindow.ui \
    loginscreen.ui \
    passwordscreen.ui \
    coffesweetsscann.ui \
    buywidget.ui \
    shoppingcart.ui \
    scanwidget.ui \
    favcart.ui \
    afterbuyscreen.ui \
    showipscreen.ui \
    favwidget.ui \
    settingswidget.ui

RESOURCES += \
    myressources.qrc

DISTFILES +=
