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
    if(database.checkPassword(userName,password)){
        mainWindowPointer->exit(21);
    }
    Data.close();

}
void passwordscreen::setMainWindowPointer(QApplication *a){
    mainWindowPointer = a;
}
void passwordscreen::setUsername(QString name){
    userName = name;
}

void passwordscreen::updateAccoutPicture(QString id){
    Data.open();
    SqlZugriff database;
    QPixmap icon;
    QString money;

    database.initGetUser();
    while(database.next()){
        if(database.getString(0) == id){
            icon = database.getPixmap();
            money = database.getString(4);
        }
    }
    ui->label_pic->setPixmap(icon);
    ui->label_credit->setText(money);
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
    updatePasswordField();
}

void passwordscreen::on_pushButton_0_clicked()
{
    password.append("0");
    updatePasswordField();
}

void passwordscreen::on_pushButton_login_clicked()
{
    Data.open();
    SqlZugriff database;
    if(database.checkPassword(userName,password)){
        mainWindowPointer->exit(21);
    }
    Data.close();
}
