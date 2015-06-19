#include "sqlzugriff.h"
#include <QString>
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QtSql>


SqlZugriff::SqlZugriff()
{
}

void SqlZugriff::initGetGroceries(bool sweets){
    if(sweets){
        query.exec("Select Grocery_ID, Name, Nick, Image, Barcode, Amount, Price from Groceries WHERE Typ = '""1""'");
    }else{
        query.exec("Select Grocery_ID, Name, Nick, Image, Barcode, Amount, Price from Groceries WHERE Typ = '""0""'");
    }
}
void SqlZugriff::initGetUser(){

    query.exec("Select User_ID, T9, Username, Image, Credits, Blocked from Users");
}

QString SqlZugriff::getString(int x){
    QString value = "";
    value = query.value(x).toString();
    return value;
}
bool SqlZugriff::next(){
    return query.next();
}

QString SqlZugriff::getName(QString ID){
    query.exec("Select Username from Users where User_ID = '"+ID+"'");

    QString ausgabe;
    ausgabe = query.value(0).toString();
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

void SqlZugriff::update(int ID){
    query.exec("UPDATE Users SET Password = "+ID+" WHERE User_ID = 1 ");
}

QPixmap SqlZugriff::getPixmap(){
    QPixmap icon;
    QByteArray imagedata;
    imagedata = query.value(3).toByteArray();
    icon.loadFromData(imagedata);
    return icon;
}

SqlZugriff::~SqlZugriff()
{
}

