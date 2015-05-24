#include "sqlzugriff.h"
#include <QString>
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QtSql>


SqlZugriff::SqlZugriff()
{
}

void SqlZugriff::initGetT9_code(){

    query.exec("Select T9, Username from Users");
}

QString SqlZugriff::getNextString(){
    QString value = "";
    if(query.next()) value = query.value(0).toString();
    return value;
}
QString SqlZugriff::getName(QString ID){
    query.exec("Select Username from Users where User_ID = '"+ID+"'");

    QString ausgabe;
    ausgabe = query.value(0).toString();
    return ausgabe;
}
QString SqlZugriff::getName(){
    QString ausgabe;
    ausgabe = query.value(1).toString();
    return ausgabe;
}
bool SqlZugriff::checkPassword(QString username, QString password){
    if(query.exec("SELECT USER_ID FROM Users WHERE Username=\'" + username +
               "\' AND Password=\'" + password + "\'")){
        if(query.next()){
            return true;
        }
    }
    return false;
}

QString SqlZugriff::getNextName(){
    QString value = "";
    if(query.next()) value = query.value(1).toString();
    return value;
}
QPixmap SqlZugriff::getPixmap(QString name){
    QPixmap icon;
    QByteArray imagedata;
    query.exec("SELECT Image FROM Users WHERE Username=\'" + name + "\'");
    if(query.next()){
        imagedata = query.value(0).toByteArray();
        icon.loadFromData(imagedata);
        return icon;
    }
    return icon;
}

QString SqlZugriff::getCredits(QString name){

    query.exec("SELECT Credits FROM Users WHERE Username=\'" + name + "\'");
    if(query.next()){
        QString credit;
        credit = query.value(0).toString();
        return credit;
    }
}

SqlZugriff::~SqlZugriff()
{
}

