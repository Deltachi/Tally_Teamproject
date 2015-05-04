#include "sqlzugriff.h"
#include <QString>


SqlZugriff::SqlZugriff()
{
}
void SqlZugriff::initGetId(){
    query.exec("Select ID from Benutzer");
}

QString SqlZugriff::getNextId(){
    QString value = "";
    if(query.next()) value = query.value(0).toString();
    return value;
}

SqlZugriff::~SqlZugriff()
{

}

