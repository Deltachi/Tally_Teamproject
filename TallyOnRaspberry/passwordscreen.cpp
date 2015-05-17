#include "passwordscreen.h"
#include "ui_passwordscreen.h"
#include "sqlzugriff.h"


passwordscreen::passwordscreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passwordscreen)
{
    ui->setupUi(this);
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Data.setDatabaseName("C:/SQLite/database.sqlite");
}

passwordscreen::~passwordscreen()
{
    delete ui;
}
void passwordscreen::updatePasswordField(){
    ui->lineEdit_password->setText(password);
}
void passwordscreen::setMainWindowPointer(QApplication *a){
    mainWindowPointer = a;
}
void passwordscreen::setUsername(QString name){
    userName = name;
}
void passwordscreen::updateAccoutPicture(QString name){
    Data.open();
    SqlZugriff database;
    QPixmap icon;
    icon = database.getPixmap(name);
    ui->label_pic->setPixmap(icon);
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

}

void passwordscreen::on_pushButton_0_clicked()
{
    password.clear();
    updatePasswordField();
}

void passwordscreen::on_pushButton_login_clicked()
{
    Data.open();
    SqlZugriff database;
    if(database.checkPassword(userName,ui->lineEdit_password->text())){
        mainWindowPointer->exit(21);
    }
    Data.close();
}
