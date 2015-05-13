#-------------------------------------------------
#
# Project created by QtCreator 2015-04-26T16:03:44
#
#-------------------------------------------------

QT       += core gui sql

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
    favcart.cpp

HEADERS  += mainwindow.h \
    loginscreen.h \
    sqlzugriff.h \
    passwordscreen.h \
    coffesweetsscann.h \
    buywidget.h \
    shoppingcart.h \
    scanwidget.h \
    favcart.h

FORMS    += mainwindow.ui \
    loginscreen.ui \
    passwordscreen.ui \
    coffesweetsscann.ui \
    buywidget.ui \
    shoppingcart.ui \
    scanwidget.ui \
    favcart.ui

RESOURCES += \
    myressources.qrc
