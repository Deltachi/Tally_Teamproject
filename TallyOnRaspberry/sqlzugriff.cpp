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
    query.first();
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

//warning, not working...
void SqlZugriff::update(QString tab, QString column, QString value, QString id ,QString number){
    query.exec("UPDATE '"+tab+"' SET '"+column+"' = '"+value+"' WHERE '"+id+"'=\\ '"+number+"'");
}

void SqlZugriff::updateCredits(QString userId ,QString newCredits){
    query.exec("UPDATE Users SET Credits = '"+newCredits+"' WHERE User_ID=\ '"+userId+"'");
}

void SqlZugriff::getCredit(QString userId){
    query.exec("SELECT Credits FROM Users WHERE User_ID=\ '"+userId+"'");
    query.first();
}

//warning, not working...
void SqlZugriff::selectAll(QString tab, QString id ,QString number){
    query.exec("SELECT ALL FROM '"+tab+"' WHERE '"+id+"'=\\ '"+number+"'");
    query.first();
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

