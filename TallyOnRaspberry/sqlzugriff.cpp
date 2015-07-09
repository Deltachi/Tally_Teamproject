#include "sqlzugriff.h"
#include <QString>
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QtSql>
#include "mainwindow.h"


SqlZugriff::SqlZugriff()
{
}

void SqlZugriff::getPicturePath(){
    query.exec("SELECT Value from Settings WHERE Setting_ID = '""3""'");
    query.first();
    picPath = query.value(0).toString();
}
QString SqlZugriff::getWatchDogtime(){
    query.exec("Select Value from Settings WHERE Setting_ID = '""1""'");
    QString value = "";
    query.first();
    value = query.value(0).toString();
    return value;
}

void SqlZugriff::initGetGroceries(bool sweets){
    if(sweets){
        query.exec("Select Grocery_ID, Name, Nick, Image, Barcode, Amount, Price from Groceries WHERE Typ = '""1""'");
    }else{
        query.exec("Select Grocery_ID, Name, Nick, Image, Barcode, Amount, Price from Groceries WHERE Typ = '""0""'");
    }
}
bool SqlZugriff::findGroceriesWithBarcode(QString code){
    query.exec("SELECT * FROM Groceries WHERE Barcode=\ '"+code+"'");
    return query.next();
}

void SqlZugriff::initGetUser(){

    query.exec("Select User_ID, T9, Username, Image, Credits, Blocked from Users");
}

QString SqlZugriff::getString(int x){
    QString value = "";
    value = query.value(x).toString();
    return value;
}
bool SqlZugriff::next(){
    return query.next();
}

QString SqlZugriff::blocked(QString userId){
    query.exec("SELECT Blocked from Users WHERE User_ID = '"+userId+"'");

    QString blocked;
    query.first();
    blocked = query.value(0).toString();
    return blocked;
}

QString SqlZugriff::getName(QString ID){
    query.exec("Select Username from Users where User_ID = '"+ID+"'");

    QString ausgabe;
    query.first();
    ausgabe = query.value(0).toString();
    return ausgabe;
}
void SqlZugriff::timestamp(QString UserId,int granted){
    MainWindow w;
    QString timestamp = w.getTimestamp();
    if(granted){
        query.exec("INSERT INTO Login_Requests(User_ID,Granted,Timestamp)" "VALUES('" +UserId+"','true','" +timestamp+ "')");
    }else{
        query.exec("INSERT INTO Login_Requests(User_ID,Granted,Timestamp)" "VALUES('" +UserId+"','false','" +timestamp+ "')");
    }
}

bool SqlZugriff::checkPassword(QString userId, QString password){
    if(query.exec("SELECT Username FROM Users WHERE User_ID=\'" + userId +
               "\' AND Password=\'" + password + "\'")){
        if(query.next()){
            return true;
        }
    }
    return false;
}

//warning, not working...
void SqlZugriff::update(QString tab, QString column, QString value, QString id ,QString number){
    query.exec("UPDATE '"+tab+"' SET '"+column+"' = '"+value+"' WHERE '"+id+"'=\\ '"+number+"'");
}

void SqlZugriff::updateCredits(QString userId ,QString newCredits){
    query.exec("UPDATE Users SET Credits = '"+newCredits+"' WHERE User_ID=\ '"+userId+"'");
}
void SqlZugriff::updateAmount(QString itemId ,QString newAmount){
    query.exec("UPDATE Groceries SET Amount = '"+newAmount+"' WHERE Grocery_ID=\ '"+itemId+"'");
}
void SqlZugriff::getAmount(QString itemId){
    query.exec("SELECT Amount FROM Groceries WHERE Grocery_ID=\ '"+itemId+"'");
    query.first();
}
void SqlZugriff::updateConsumeIndex(QString userId,QString Grocery_Id,QString count){
    query.exec("SELECT Count FROM Consum_Index WHERE User_ID=\'"+userId+"\' AND Grocery_ID=\'"+Grocery_Id+"\'");
    if(!query.next()){
        query.exec("INSERT INTO Consum_Index (User_ID, Grocery_ID, Count)" "VALUES('"+userId+"','"+Grocery_Id+"','"+count+"')");
    }else{
        QString amount = QString::number(count.toInt() + query.value(0).toString().toInt());
        query.exec("UPDATE Consum_Index SET Count = '"+amount+"' WHERE User_ID=\'"+userId+"\' AND Grocery_ID=\'"+Grocery_Id+"\'");
    }
}
void SqlZugriff::addSell(QString userId,QString Grocery_Id,QString Amount,QString price_per_pc){
    MainWindow w;
    QString timestamp = w.getTimestamp();
    query.exec("INSERT INTO Sell_History (User_ID, Grocery_ID, Amount, Price_per_piece, Timestamp)" "VALUES('"+userId+"','"+Grocery_Id+"','"+Amount+"','"+price_per_pc+"','"+timestamp+"')");
}
double SqlZugriff::getMaxOverdrawValue(){
    query.exec("SELECT Value FROM Settings WHERE Setting_ID='2'");
    query.first();
    return query.value(0).toDouble();
}
void SqlZugriff::getCredit(QString userId){
    query.exec("SELECT Credits FROM Users WHERE User_ID=\ '"+userId+"'");
    query.first();
}
void SqlZugriff::selectFavorites(QString userId){
    query.exec("SELECT * FROM Favorites INNER JOIN Groceries ON Favorites.Grocery_ID=Groceries.Grocery_ID WHERE Favorites.User_ID = '"+userId+"'");
}

//warning, not working...
void SqlZugriff::selectAll(QString tab, QString id ,QString number){
    query.exec("SELECT ALL FROM '"+tab+"' WHERE '"+id+"'=\\ '"+number+"'");
    query.first();
}

QPixmap SqlZugriff::getPixmap(int x){
    QPixmap icon;
    QString path = picPath + query.value(x).toString();
    icon.load(path);
    return icon;
}
/*
void SqlZugriff::get_timestamp(QString userId){
    query.exec("SELECT Timestamp FROM Login_Requests WHERE User_ID = '"+iserId+"' AND Granted = 'true'");
    query.first();
    QString timestamp;
    int count = 5;

    while(query.next() && count > 0){

    }
}
*/
SqlZugriff::~SqlZugriff()
{
}

