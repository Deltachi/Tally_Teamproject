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
    void initGetUser(QString userId);
    bool next();
    QString getName(QString ID);
    QString getString(int x);
    bool checkPassword(QString username, QString password);
    QPixmap getPixmap(int x);
    void initGetGroceries(bool sweets);
    void update(QString tab, QString column, QString value, QString id ,QString number);
    void updateCredits(QString userId ,QString newCredits);
    void selectAll(QString tab, QString id ,QString number);
    void getCredit(QString userId);
    void getAmount(QString itemId);
    void updateAmount(QString itemId ,QString newAmount);
    QString getWatchDogtime();
    void addSell(QString userId,QString Grocery_Id,QString Amount,QString price_per_pc);
    void updateConsumeIndex(QString userId,QString Grocery_Id,QString count);
    double getMaxOverdrawValue();
    bool findGroceriesWithBarcode(QString code);
    QString blocked(QString userId);
    void getPicturePath();
    bool checkUserLoginCount(QString userId);
    void updateLoginAttempt(QString userId, bool valid);
    void selectFavorites(QString userId);
    void throwError();

private:
     QSqlQuery query;
     QString picPath;
};
#endif // SQLZUGRIFF_H
