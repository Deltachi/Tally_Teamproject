#ifndef SQLZUGRIFF_H
#define SQLZUGRIFF_H

#include <QtSql>
#include <QtDebug>
#include <QFileInfo>


class SqlZugriff
{
public:
    SqlZugriff();
    ~SqlZugriff();
    void initGetId();
    QString getNextId();

private:
     QSqlQuery query;

};
#endif // SQLZUGRIFF_H
