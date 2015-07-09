#include "passwordscreen.h"
#include "ui_passwordscreen.h"
#include "sqlzugriff.h"
#include "mainwindow.h"


passwordscreen::passwordscreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passwordscreen)
{
    ui->setupUi(this);
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
}

passwordscreen::~passwordscreen()
{
    delete ui;
}
void passwordscreen::updatePasswordField(){
    short loop;
    ui->lineEdit_password->setText("");
    for(loop=0;loop<password.length();loop++){
        ui->lineEdit_password->setText(ui->lineEdit_password->text() + "*");
    }

    Data.open();
    SqlZugriff database;
    if(database.checkPassword(userId,password) && blocked != "1"){
        database.timestamp(userId,1);
        Data.close();
        mainWindowPointer->exit(21);
    }
    Data.close();
    MainWindow w;
    w.setWatchDog();

}
void passwordscreen::setMainWindowPointer(QApplication *a,QString gUserId){
    mainWindowPointer = a;
    userId = gUserId;
    password.clear();
    updateAccoutPicture(userId);
    updatePasswordField();
}
void passwordscreen::setUsername(QString name){
    userName = name;
}
void passwordscreen::setUserId(QString gUserId){
    userId = gUserId;
}
void passwordscreen::updateAccoutPicture(QString id){
    Data.open();
    SqlZugriff database;
    QPixmap icon;
    QString money;

    database.getPicturePath();
    database.initGetUser();
    while(database.next()){
        if(database.getString(0) == id){
            icon = database.getPixmap(3);
            money = database.getString(4);
        }
    }
    ui->label_pic->setPixmap(icon);
    ui->label_credit->setText(money);
    blocked = database.blocked(id);
    if(blocked == "1"){
        ui->label_credit->setVisible(false);
        ui->label_2->setVisible(false);
        ui->label_name->setText("User blocked");
    }

    Data.close();
}

void passwordscreen::on_pushButton_1_clicked()
{
    password.append("1");
    updatePasswordField();
}

void passwordscreen::on_pushButton_2_clicked()
{
    password.append("2");
    updatePasswordField();
}

void passwordscreen::on_pushButton_3_clicked()
{
    password.append("3");
    updatePasswordField();
}

void passwordscreen::on_pushButton_4_clicked()
{
    password.append("4");
    updatePasswordField();
}

void passwordscreen::on_pushButton_5_clicked()
{
    password.append("5");
    updatePasswordField();
}

void passwordscreen::on_pushButton_6_clicked()
{
    password.append("6");
    updatePasswordField();
}

void passwordscreen::on_pushButton_7_clicked()
{
    password.append("7");
    updatePasswordField();
}

void passwordscreen::on_pushButton_8_clicked()
{
    password.append("8");
    updatePasswordField();
}

void passwordscreen::on_pushButton_9_clicked()
{
    password.append("9");
    updatePasswordField();
}

void passwordscreen::on_pushButton_back_clicked()
{
    password.clear();
    Data.open();
    SqlZugriff database;
    database.timestamp(userId,0);
    Data.close();
    updatePasswordField();
}

void passwordscreen::on_pushButton_0_clicked()
{
    password.append("0");
    updatePasswordField();
}

void passwordscreen::on_pushButton_login_clicked()
{
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff database;
    qDebug() << userName << " " << password << " " << userId;
    if(database.checkPassword(userName,password)){
        Data.close();
        mainWindowPointer->exit(21);
    }
    Data.close();
    updatePasswordField();
}
