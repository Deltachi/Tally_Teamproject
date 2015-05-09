#ifndef SQLZUGRIFF_H
#define SQLZUGRIFF_H

#include <QtSql>
#include <QString>
#include <QDebug>
#include <QFileInfo>
#include <QString>


class SqlZugriff
{
public:
    SqlZugriff();
    ~SqlZugriff();
    void initGetT9_code();
    void init();
    QString getNextId();
    QString getName(QString ID);
    QString getName();
    QString getNextString();
    QString getNextName();
    void close();
    bool checkPassword(QString username, QString password);

private:
     QSqlQuery query;
     QSqlDatabase database;
};
#endif // SQLZUGRIFF_H
