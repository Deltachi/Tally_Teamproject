#include "passwordscreen.h"
#include "ui_passwordscreen.h"
#include "sqlzugriff.h"
#include "mainwindow.h"


passwordscreen::passwordscreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passwordscreen)
{
    ui->setupUi(this);
    tempBlocked = false;
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

    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff database;
    if(database.checkUserLoginCount(userId)){
        if(tempBlocked){ //was user blocked before?
            ui->label_credit->setText(" ");
            ui->label_name->setText(" ");
            tempBlocked = false;
        }
        if(database.checkPassword(userId,password) && blocked != "1" && database.checkUserLoginCount(userId)){  //Passwort wurde korrekt eingegeben und der User ist niocht geblockt
            database.updateLoginAttempt(userId,true);
            Data.close();
            mainWindowPointer->exit(21);
        }
    }else{
        ui->label_name->setText("Error:");
        QFont font;
        font.setPointSize(13);
        ui->label_name->setFont(font);
        ui->label_credit->setFont(font);
        ui->label_credit->setText("Temp blocked.");
        ui->label_2->setVisible(false);
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

    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
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
        QFont font;
        font.setPointSize(13);
        ui->label_name->setFont(font);
        ui->label_credit->setFont(font);
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
    updatePasswordField();
    Data = QSqlDatabase::addDatabase("QSQLITE");
    Database_Link
    Data.open();
    SqlZugriff database;
    database.updateLoginAttempt(userId,false);
    if(!database.checkUserLoginCount(userId)){
        Data.close();
        QFont font;
        font.setPointSize(13);
        ui->label_name->setFont(font);
        ui->label_credit->setFont(font);
        ui->label_name->setText("Wrong login!");
        ui->label_credit->setText("Temp blocked.");
        ui->label_2->setVisible(false);
        tempBlocked = true;
        return;
    }
    Data.close();
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
        if(database.checkUserLoginCount(userId)){
            database.updateLoginAttempt(userId,true);
            Data.close();
            mainWindowPointer->exit(21);
        }else{
            QFont font;
            font.setPointSize(13);
            ui->label_name->setFont(font);
            ui->label_credit->setFont(font);
            ui->label_name->setText("Wrong login!");
            ui->label_credit->setText("Temp blocked.");
            ui->label_2->setVisible(false);
            tempBlocked = true;
        }
    }
    database.updateLoginAttempt(userId,false);
    Data.close();
    updatePasswordField();
}
