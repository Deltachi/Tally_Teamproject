#include "sqlzugriff.h"
#include <QString>


SqlZugriff::SqlZugriff()
{
}
void SqlZugriff::initGetId(){
    query.exec("Select ID, Name from Benutzer");
}

QString SqlZugriff::getNextId(){
    QString value = "";
    if(query.next()) value = query.value(0).toString();
    return value;
}

QString SqlZugriff::getName(){
    QString ausgabe;
    ausgabe = query.value(1).toString();
    return ausgabe;
}

QString SqlZugriff::getnextName(){
    QString value = "";
    if(query.next()) value = query.value(1).toString();
    return value;
}

SqlZugriff::~SqlZugriff()
{

}

