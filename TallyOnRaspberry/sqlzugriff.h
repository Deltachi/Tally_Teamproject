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
    void update(QString tab, QString column, QString value, QString id ,QString number);
    void updateCredits(QString userId ,QString newCredits);
    void selectAll(QString tab, QString id ,QString number);
    void getCredit(QString userId);
    void timestamp(QString userId,int granted);

private:
     QSqlQuery query;
};
#endif // SQLZUGRIFF_H
