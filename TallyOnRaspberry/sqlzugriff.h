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
    void initGetUser();
    bool next();
    QString getName(QString ID);
    QString getString(int x);
    bool checkPassword(QString username, QString password);
    QPixmap getPixmap();
    void initGetGroceries(bool sweets);
    void update(int ID);

private:
     QSqlQuery query;
};
#endif // SQLZUGRIFF_H
