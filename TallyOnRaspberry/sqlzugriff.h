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
    QString getNextId();
    QString getName(QString ID);
    QString getName();
    QString getNextString();
    QString getNextName();
    bool checkPassword(QString username, QString password);
    QPixmap getPixmap(QString name);

private:
     QSqlQuery query;
};
#endif // SQLZUGRIFF_H
