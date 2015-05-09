#include "sqlzugriff.h"
#include <QString>
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QtSql>


SqlZugriff::SqlZugriff()
{
}
void SqlZugriff::init(){
   if(!database.isOpen()){
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("C:/SQLite/database.sqlite");
        database.open();
    }
}

void SqlZugriff::initGetT9_code(){
    query.exec("Select t9_code, name from Benutzer");
}

QString SqlZugriff::getNextString(){
    QString value = "";
    if(query.next()) value = query.value(0).toString();
    return value;
}
QString SqlZugriff::getName(QString ID){
    query.exec("Select name from Benutzer where id = '"+ID+"'");

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
    if(query.exec("SELECT id FROM Benutzer WHERE name=\'" + username +
               "\' AND password=\'" + password + "\'")){
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
void SqlZugriff::close(){
    database.close();
}
SqlZugriff::~SqlZugriff()
{
    database.close();
}

