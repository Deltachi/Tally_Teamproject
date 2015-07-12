#include "sqlzugriff.h"
#include <QString>
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QtSql>
#include <QTime>
#include <QDate>
#include <QMessageBox>
#include "mainwindow.h"

//constructer
SqlZugriff::SqlZugriff()
{
}

//gets the Picture from the Database
void SqlZugriff::getPicturePath(){
    if(query.exec("SELECT Value from Settings WHERE Setting_ID = '""3""'")){
        query.first();
        picPath = query.value(0).toString();
        return;
    }
    throwError();
}

//gets the Watchdogtime from the Database
QString SqlZugriff::getWatchDogtime(){
    if(query.exec("Select Value from Settings WHERE Setting_ID = '""1""'")){
        QString value = "";
        query.first();
        value = query.value(0).toString();
        return value;
    }
    throwError();       //if Database not open
}

//open window with the message : Database not found
void SqlZugriff::throwError(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(NULL, QObject::tr("Critical Error"), QObject::tr(qPrintable("Database not found at:\r\n \"" + Database_Path + "\"\r\nThe Program will not work.\r\n:(")),QMessageBox::Close);
    exit(EXIT_FAILURE);
}

//selects the Groceries from the Database
void SqlZugriff::initGetGroceries(bool sweets){
    if(sweets){
        if(query.exec("Select Grocery_ID, Name, Nick, Image, Barcode, Amount, Price from Groceries WHERE Typ = '""1""'"));      //Sweets
        else throwError();
    }else{
        if(query.exec("Select Grocery_ID, Name, Nick, Image, Barcode, Amount, Price from Groceries WHERE Typ = '""0""'"));      //Drinks
        else throwError();
    }
}


bool SqlZugriff::findGroceriesWithBarcode(QString code){
    if(query.exec("SELECT * FROM Groceries WHERE Barcode=\ '"+code+"'"))
        return query.next();
    else throwError();
}

//selects the Users from the Database
void SqlZugriff::initGetUser(){
    if(query.exec("Select User_ID, T9, Username, Image, Credits, Blocked from Users"));
    else throwError();
}

//selects a special user from the Database
void SqlZugriff::initGetUser(QString userId){
    if(query.exec("Select * FROM Users WHERE User_ID = '"+userId+"'"))
        query.first();
    else throwError();
}

//chose 1 value from the query
QString SqlZugriff::getString(int x){
    QString value = "";
    value = query.value(x).toString();
    return value;
}

//chose the next value from the query
bool SqlZugriff::next(){
    return query.next();
}

//
QString SqlZugriff::blocked(QString userId){
    if(query.exec("SELECT Blocked from Users WHERE User_ID = '"+userId+"'"));
    else throwError();

    QString blocked;
    query.first();
    blocked = query.value(0).toString();
    return blocked;
}

QString SqlZugriff::getName(QString ID){
    if(query.exec("Select Username from Users where User_ID = '"+ID+"'"));
    else throwError();

    QString ausgabe;
    query.first();
    ausgabe = query.value(0).toString();
    return ausgabe;
}
bool SqlZugriff::checkUserLoginCount(QString userId){
    if(query.exec("SELECT Login_Attempts, Timestamp FROM Users WHERE User_ID = '"+userId+"'"));
    else throwError();
    bool valid;
    if(query.next()){
        if(query.value(0).toInt() < 3){
            valid = true;
        }else{
            QDateTime date = query.value(1).toDateTime();
            if(date.time().msecsTo(QDateTime::currentDateTime().time()) > 60000){ //wait some time
                valid = true;
            }else{
                valid = false;
            }
        }
    }else{
        valid = true;
    }
    return valid;
}
void SqlZugriff::updateLoginAttempt(QString userId, bool valid){
    QString date(QDate::currentDate().toString(Qt::ISODate));
    date.append(' ' + QTime::currentTime().toString());
    query.exec("UPDATE Users SET Timestamp ='"+date+"' WHERE User_ID='"+userId+"'");
    if(valid){
        query.exec("UPDATE Users SET Login_Attempts ='0' WHERE User_ID='"+userId+"'");
    }else{
        query.exec("UPDATE Users SET Login_Attempts = Login_Attempts + '1' WHERE User_ID='"+userId+"'");
    }
}

bool SqlZugriff::checkPassword(QString userId, QString password){
    if(query.exec("SELECT Username FROM Users WHERE User_ID=\'" + userId +
               "\' AND Password=\'" + password + "\'")){
        if(query.next()){
            return true;
        }else{
            return false;
        }
    }else throwError();
    return false;
}

//warning, not working...
void SqlZugriff::update(QString tab, QString column, QString value, QString id ,QString number){
    if(query.exec("UPDATE '"+tab+"' SET '"+column+"' = '"+value+"' WHERE '"+id+"'=\\ '"+number+"'"));
    else throwError();
}

void SqlZugriff::updateCredits(QString userId ,QString newCredits){
    if(query.exec("UPDATE Users SET Credits = '"+newCredits+"' WHERE User_ID=\ '"+userId+"'"));
    else throwError();
}
void SqlZugriff::updateAmount(QString itemId ,QString newAmount){
    if(query.exec("UPDATE Groceries SET Amount = '"+newAmount+"' WHERE Grocery_ID=\ '"+itemId+"'"));
    else throwError();
}
void SqlZugriff::getAmount(QString itemId){
    if(query.exec("SELECT Amount FROM Groceries WHERE Grocery_ID=\ '"+itemId+"'"))
        query.first();
    else throwError();
}
void SqlZugriff::updateConsumeIndex(QString userId,QString Grocery_Id,QString count){
    if(query.exec("SELECT Count FROM Consum_Index WHERE User_ID=\'"+userId+"\' AND Grocery_ID=\'"+Grocery_Id+"\'")){
        if(!query.next()){
            query.exec("INSERT INTO Consum_Index (User_ID, Grocery_ID, Count)" "VALUES('"+userId+"','"+Grocery_Id+"','"+count+"')");
        }else{
            QString amount = QString::number(count.toInt() + query.value(0).toString().toInt());
            query.exec("UPDATE Consum_Index SET Count = '"+amount+"' WHERE User_ID=\'"+userId+"\' AND Grocery_ID=\'"+Grocery_Id+"\'");
        }
    }
    else throwError();
}
void SqlZugriff::addSell(QString userId,QString Grocery_Id,QString Amount,QString price_per_pc){
    MainWindow w;
    QString timestamp = w.getTimestamp();
    if(query.exec("INSERT INTO Sell_History (User_ID, Grocery_ID, Amount, Price_per_piece, Timestamp)" "VALUES('"+userId+"','"+Grocery_Id+"','"+Amount+"','"+price_per_pc+"','"+timestamp+"')"));
    else throwError();
}
double SqlZugriff::getMaxOverdrawValue(){
    if(query.exec("SELECT Value FROM Settings WHERE Setting_ID='2'"))
        query.first();
    else throwError();

    return query.value(0).toDouble();
}
void SqlZugriff::getCredit(QString userId){
    if(query.exec("SELECT Credits FROM Users WHERE User_ID=\ '"+userId+"'"))
        query.first();
    else throwError();
}
void SqlZugriff::selectFavorites(QString userId){
    if(query.exec("SELECT * FROM Favorites INNER JOIN Groceries ON Favorites.Grocery_ID=Groceries.Grocery_ID WHERE Favorites.User_ID = '"+userId+"'"));
    else throwError();
}

//warning, not working...
void SqlZugriff::selectAll(QString tab, QString id ,QString number){
    if(query.exec("SELECT ALL FROM '"+tab+"' WHERE '"+id+"'=\\ '"+number+"'"))
        query.first();
    else throwError();
}

QPixmap SqlZugriff::getPixmap(int x){
    QPixmap icon;
    QString path = picPath + query.value(x).toString();
    icon.load(path);
    return icon;
}
SqlZugriff::~SqlZugriff()
{
}

