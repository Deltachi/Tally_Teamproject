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
    mainmenue.cpp \
    loginscreen.cpp \
    sqlzugriff.cpp

HEADERS  += mainwindow.h \
    mainmenue.h \
    loginscreen.h \
    sqlzugriff.h

FORMS    += mainwindow.ui \
    mainmenue.ui \
    loginscreen.ui

RESOURCES += \
    myressources.qrc
